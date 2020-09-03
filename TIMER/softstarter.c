

/* EXERCÍCIO 4 - ALEXANDRE DE ALMEIDA LIMA - 4411*/

#include <htc.h>
#include "lcd.h"
#include <stdio.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

unsigned int ANGULO = 0;
unsigned int ANGULO_R = 0;
unsigned int delay_r = 0;
char bite = 0;
char lixo;
char status = 0;
unsigned char DADO_RX[7] = 0;
bit f_dado = 0;
bit teste_recebido = 0;
bit erro_conexao = 0;
bit ligado = 0;
bit ligando = 0;
bit desligando = 0;
bit configurado = 0;
bit enviar_dados = 0;
bit enviar_alfa = 0;
bit enviar_ligado = 0;
bit enviar_desligado = 0;
bit manual = 0;
bit realimentacao = 0;
bit sobrecorrente = 0;
bit enviar_status = 0;
bit jobs = 0;
bit anal_ok = 0;
bit alfa_ok = 0;
unsigned int valor_anal = 0;
unsigned char TMR0X = 237;
unsigned int ANGMAX = 0;
unsigned char cont_teste = 0;
unsigned char cont_dados = 0;
unsigned char TMR1LX = 0;
unsigned char TMR1HX = 0;
unsigned char ANGMNH = 0;
unsigned char ANGMNL = 0;
unsigned int anal_cont = 0;

void init_serial(void) {
    //configura a porta serial para 9600bps
    //habilita a interrupção por recepção serial
    //***********   MUDAR ISSO AQUI PRA TER 1200 {
    //CONFIGURAÇÃO DA TRANSMISSÃO SERIAL
    SYNC = 0;
    BRGH = 0;
    BRG16 = 1;
    SPBRG = 129;
    SPBRGH = 0;
    // }
    SPEN = 1;
    TX9 = 0;
    TXEN = 1;

    //CONFIGURAÇÃO DA RECEPÇÃO SERIAL
    //***********   MUDAR ISSO AQUI PRA TER 1200 {
    RCIE = 1; //HABILITA A INTERRUPÇÃO POR INTERRUPÇÃO
    PEIE = 1; //HABILITA A INTERRUPÇÃO DOS PERIFÉRICOS
    RX9 = 0; //RECEBER 8 BITS
    CREN = 1; //HABILITA A RECEPÇÃO SERIAL
}

void tx_serial(unsigned char dado) {
    while (!TRMT) {
    }; //verifica se o buffer de transmissão está ocupado
    TXREG = dado; //transmite o dado
}

void putch(char c) {
    tx_serial(c);
}

void interrupt xandi_lima(void) {
    //rotina de interrupção

    if (INTF && INTE) { //TESTA SE É INTERRUPÇÃO POR MUDANÇA DE NÍVEL DO RA2
        PORTA = PORTA;
        INTF = 0;
        /*if (++cont_teste == 170) {
            cont_teste = 0;
            if (!teste_recebido) {
                if (ligado) {
                    RA0 = 0;
                    ligando = 0;
                    desligando = 1;
                    configurado = 0;
                    T0IE = 1;
                    TMR0X = 237;
                    TMR0 = TMR0X;
                }
            } else {
                teste_recebido = 0;
            }
        }*/

        if (manual) {
            if (++anal_cont == 255) anal_ok = 1;
        }

        if (ligado) {
	        if (++cont_dados == 10) { // && (ligando || desligando)){  //a cada 66ms atualiza os dados
                cont_dados = 0;
                GO_nDONE = 1;
        }
            TMR1IE = 1;
            RA1 = 0;
            TMR1L = ((ANGULO) & 0x00FF); // carregando 3036 no timer 1
            TMR1H = (((ANGULO) >> 8) & 0x00FF); // carregando 3036 no timer 1
            TMR1ON = 1;
        }
    }

    if (T0IF && T0IE) {
        T0IF = 0;
        TMR0 = TMR0X;
        if (ligando) {
            if (++anal_cont == 1000) anal_ok = 1;
            if (++ANGULO >= ANGMAX) {
                T0IE = 0;
                ligando = 0;
                RA0 = 1;
                enviar_alfa = 1;
                status = 7;
                enviar_status = 1;
                alfa_ok=0;
            }
        }
        if (desligando) {
            if (--ANGULO <= 27000) {
                T0IE = 0;
                TMR1ON = 0;
                TMR1IE = 0;
                INTE = 0;
                ligado = 0;
                desligando = 0;
                RA1 = 0;
                //ADIE=0;
                TMR1L = 0; // carregando 3036 no timer 1
                TMR1H = 0; // carregando 3036 no timer 1
                status = 0;
                anal_ok = 0;
                anal_cont = 0;
                enviar_alfa = 1;
                enviar_status = 1;
                enviar_desligado = 1;
                alfa_ok=0;
            }
        }
    }

    if (ADIF) {
        ADIF = 0;
        valor_anal = ((ADRESH * 256) + ADRESL);
        if (ANGULO>44500 && ligado) {
            if ((valor_anal > 500) && ligando && !realimentacao && !manual) { //realimentação = 2.5V
                T0IE = 0;
                realimentacao = 1;
                status = 2;
                enviar_status = 1;
            }
            if ((valor_anal > 500) && (!ligando)) { //corrente elevada= 2.5V
                status = 4;
                enviar_status = 1;
            }
            if (valor_anal > 620) { //sobrecorrente = 3V
                TMR1IE = 0;
                RA0 = 0;
                T0IE = 0;
                ligado = 0;
                RA1 = 0;
                manual = 0;
                ANGULO = ANGULO_R;
                status = 3;
                enviar_status = 1;
                __delay_ms(100);
            }
            if (valor_anal < 230 && realimentacao) { //corrente normal
                T0IE = 1;
                realimentacao = 0;
                status = 1;
                enviar_status = 1;
            }
        }
        if (manual){
        if (valor_anal > 400) { //corrente elevada= 2.5V
                status = 4;
                enviar_status = 1;
            }
            if (valor_anal > 600) { //sobrecorrente = 3V
                TMR1IE = 0;
                RA0 = 0;
                T0IE = 0;
                ligado = 0;
                RA1 = 0;
                manual = 0;
                ANGULO = ANGULO_R;
                status = 3;
                enviar_status = 1;
            }
        }
        enviar_alfa = 1;

    }

    if (TMR1IF && TMR1IE) { //overflow timer 1 após 500ms
        RA1 = 1;
        TMR1IF = 0;
        TMR1ON = 0;
        TMR1IE = 0;
        TMR1L = ((ANGULO) & 0x00FF); // carregando 3036 no timer 1
        TMR1H = (((ANGULO) >> 8) & 0x00FF); // carregando 3036 no timer 1
    }



    if (RCIF) {//testa se é recepção serial
        if (FERR) {//testa se tem erro de frame
            lixo = RCREG;
        } else {
            DADO_RX[bite] = RCREG;
            if (DADO_RX[bite] == '#') bite = 0;
            else {
                if (++bite == 7) {
                    bite = 0;
                    f_dado = 1;
                }
            }
        }
    }
}

/* INTERRUPÇÃO DE TMR1:

NItmr1=(Fsist{Focs/4 ou cristal de 32,768kHz} x t[s])/(PS x (65536-TMR1))

 */

void main() {
    ANSELH = 0;
    TRISA = 0b00111100;
    TRISB = 0b00110000;
    TRISC = 0b00000001;
    ANSEL = 0b00010000;
    ADCON0 = 0b10010001;
    ADCON1 = 0b01100000;
    OPTION_REG = 0b00000100; //PULL UP ATIVADO E INTERRUPÇÃO POR BORDA DE DESCIDA DO RA2
    INTCON = 0b11000000; //HABILITA INTERRUPÇÃO TIMER1 E INTERRUPÇÃO POR MUDANÇA DE NÍVEL E POR MUDANÇA DO RA2
    INTE = 1;
    RA1 = 0;
    ADIF = 0;
    ADIE = 1;
    init_serial();
    RA0 = 0;
    T0IE = 0;
    TMR0 = 0;
    T1CON = 0b00000000; //prescaler 1:1;
    TMR1IE = 0; //INTERRUPÇÃO POR OVERFLOW TIMER1 ATIVADA
    TMR1L = 0; // carregando 3036 no timer 1
    TMR1H = 0; // carregando 3036 no timer 1


    while (1) {
        if (!ligado) {
            RA1 = 0;
            RA0 = 0;
        }

        if (enviar_alfa) {
            enviar_alfa = 0;
            if (jobs) {
                jobs = !jobs;
                printf("ADL%04d", valor_anal);
                __delay_ms(10);
            } 
            else {
                jobs = !jobs;
                if (!manual && alfa_ok) {
                    printf("alfH%03d", TMR1H);
                    __delay_ms(10);
                    printf("alfL%03d", TMR1L);
                    __delay_ms(10);
                }
            }

        }

        if (enviar_status) {
            enviar_status = 0;
            printf("STATUS%d", status);
            __delay_ms(10);
        }

        if (enviar_ligado) {
            enviar_ligado = 0;
            status = 7;
            enviar_status = 1;
        }

        if (enviar_desligado) {
            enviar_desligado = 0;
            status = 0;
            enviar_status = 1;
        }


        if (f_dado) {
            f_dado = 0;
            if ((DADO_RX[0] == 't') && (DADO_RX[1] == 'e') && (DADO_RX[2] == 's') && (DADO_RX[3] == 't') && (DADO_RX[4] == 'e') && (DADO_RX[5] == 'x') && (DADO_RX[6] == 'x')) {
                printf("testeok");
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 't') && (DADO_RX[1] == 'e') && (DADO_RX[2] == 's') && (DADO_RX[3] == 't') && (DADO_RX[4] == 'e') && (DADO_RX[5] == 'o') && (DADO_RX[6] == 'x')) {
                printf("testecc");
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 't') && (DADO_RX[1] == 'e') && (DADO_RX[2] == 's') && (DADO_RX[3] == 't') && (DADO_RX[4] == 'e') && (DADO_RX[5] == 'i') && (DADO_RX[6] == 'n')) {
                printf("testeok");
                teste_recebido = 1;
                enviar_status = 1;
            }
            if ((DADO_RX[0] == 'A') && (DADO_RX[1] == 'N') && (DADO_RX[2] == 'G') && (DADO_RX[3] == 'H')) {
                TMR1HX = (((DADO_RX[4] - 48)*100)+((DADO_RX[5] - 48)*10)+(DADO_RX[6] - 48));
                if (!manual) printf("enviook");
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 'A') && (DADO_RX[1] == 'N') && (DADO_RX[2] == 'G') && (DADO_RX[3] == 'L')) {
                TMR1LX = (((DADO_RX[4] - 48)*100)+((DADO_RX[5] - 48)*10)+(DADO_RX[6] - 48));
                ANGULO_R = (TMR1HX * 256 + TMR1LX);
                ANGULO = ANGULO_R;
                if (!manual) printf("enviook");
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 'T') && (DADO_RX[1] == 'M') && (DADO_RX[2] == 'R') && (DADO_RX[3] == '0')) {
                TMR0X = (((DADO_RX[4] - 48)*100)+((DADO_RX[5] - 48)*10)+(DADO_RX[6] - 48));
                printf("enviook");
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 'A') && (DADO_RX[1] == 'M') && (DADO_RX[2] == 'N') && (DADO_RX[3] == 'H')) {
                ANGMNH = (((DADO_RX[4] - 48)*100)+((DADO_RX[5] - 48)*10)+(DADO_RX[6] - 48));
                printf("enviook");
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 'A') && (DADO_RX[1] == 'M') && (DADO_RX[2] == 'N') && (DADO_RX[3] == 'L')) {
                ANGMNL = (((DADO_RX[4] - 48)*100)+((DADO_RX[5] - 48)*10)+(DADO_RX[6] - 48));
                ANGMAX = ((ANGMNH * 256) + ANGMNL);
                printf("enviook");
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 'l') && (DADO_RX[1] == 'i') && (DADO_RX[2] == 'g') && (DADO_RX[3] == 'a') && (DADO_RX[4] == 'r') && (DADO_RX[5] == 'x') && (DADO_RX[6] == 'x')) {
              
                    ANGULO = ANGULO_R;
                    TMR1IE = 0;
                    INTE = 1;
                    T0IE = 1;
                    TMR0 = TMR0X;
                    TMR1L = ((ANGULO) & 0x00FF); // carregando 3036 no timer 1
                    TMR1H = (((ANGULO) >> 8) & 0x00FF); // carregando 3036 no timer 1
                    ligando = 1;
                    ADIE=1;
                    ligado = 1;
                    status = 1;
                    alfa_ok=1;
                    OPTION_REG = 0b01000100;
                teste_recebido = 1;
            }

            if ((DADO_RX[0] == 'l') && (DADO_RX[1] == 'i') && (DADO_RX[2] == 'g') && (DADO_RX[3] == 'a') && (DADO_RX[4] == 'r') && (DADO_RX[5] == 'm') && (DADO_RX[6] == 'n')) {
                ANGULO = ANGULO_R;
                INTE = 1;
                TMR1L = ((ANGULO) & 0x00FF); // carregando 3036 no timer 1
                TMR1H = (((ANGULO) >> 8) & 0x00FF); // carregando 3036 no timer 1
                ligado = 1;
                manual = 1;
                ADIE=1;
                teste_recebido = 1;
                status = 1;
                OPTION_REG = 0b01000100;
            }

            if ((DADO_RX[0] == 'd') && (DADO_RX[1] == 'e') && (DADO_RX[2] == 's') && (DADO_RX[3] == 'l') && (DADO_RX[4] == 'i') && (DADO_RX[5] == 'g') && (DADO_RX[6] == 'x')) {
                T0IE = 1;
                TMR0 = TMR0X;
                ligando = 0;
                desligando = 1;
                ligado = 1;
                teste_recebido = 1;
                alfa_ok=1;
                OPTION_REG = 0b00000100;
            }
            if ((DADO_RX[0] == 'e') && (DADO_RX[1] == 'm') && (DADO_RX[2] == 'e') && (DADO_RX[3] == 'r') && (DADO_RX[4] == 'g') && (DADO_RX[5] == 'e') && (DADO_RX[6] == 'x')) {
                TMR1IE = 0;
                RA0 = 0;
                T0IE = 0;
                ligado = 0;
                RA1 = 0;
                ADIE = 0;
                manual = 0;
                ANGULO = ANGULO_R;
                anal_ok = 0;
                anal_cont = 0;
                teste_recebido = 1;
            }
            if ((DADO_RX[0] == 'c') && (DADO_RX[1] == 'o') && (DADO_RX[2] == 'n') && (DADO_RX[3] == 'f') && (DADO_RX[4] == 'g') && (DADO_RX[5] == 'o') && (DADO_RX[6] == 'k')) {
                if (ANGULO && TMR0X && ANGMAX) {
                    printf("configc");
                    configurado = 1;
                }
                teste_recebido = 1;
            }
        }


    }
}

