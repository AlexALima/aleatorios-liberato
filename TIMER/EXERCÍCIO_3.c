
/* EXERC�CIO 4 - ALEXANDRE DE ALMEIDA LIMA - 4411*/

#include <htc.h>
#include "lcd.h"
#include <stdio.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 20000000
#endif

unsigned int ANGULO=23870;
char oi=1;
char lixo;
char bite=0;
unsigned char DADO_RX[7]=0;
char f_dado=0;

void init_serial (void){
	//configura a porta serial para 9600bps
	//habilita a interrup��o por recep��o serial
	//***********   MUDAR ISSO AQUI PRA TER 1200 {
		//CONFIGURA��O DA TRANSMISS�O SERIAL 
		SYNC=0;
		BRGH=1;
		BRG16=1;
		SPBRG=38;
		SPBRGH=0;
	// }
		SPEN=1;
		TX9=0;
		TXEN=1;
		
		//CONFIGURA��O DA RECEP��O SERIAL
	//***********   MUDAR ISSO AQUI PRA TER 1200 {
		RCIE=1; //HABILITA A INTERRUP��O POR INTERRUP��O
		PEIE=1; //HABILITA A INTERRUP��O DOS PERIF�RICOS
		RX9=0; //RECEBER 8 BITS
		CREN=1; //HABILITA A RECEP��O SERIAL
}

void tx_serial (unsigned char dado) {
	while(!TRMT){}; //verifica se o buffer de transmiss�o est� ocupado
	TXREG=dado; //transmite o dado
}

void putch(char c)
{
	tx_serial(c);
}

void interrupt xandi_lima(void){
//rotina de interrup��o
	
	if (INTF){ //TESTA SE � INTERRUP��O POR MUDAN�A DE N�VEL DO RA2
		PORTA=PORTA;
		INTF=0;
		TMR1IE=1;
		RA1=0;
		RA0=!RA0;
		TMR1L=((ANGULO) & 0x00FF); // carregando 3036 no timer 1
		TMR1H=(((ANGULO)>>8) & 0x00FF); // carregando 3036 no timer 1
		TMR1ON=1;
	}

	if (T0IF){
		T0IF=0;
		TMR0=250;
		if(oi){
			if (++ANGULO>=65530){
				oi=!oi;
			}
		}	
		else{
			if (--ANGULO<=23870){
				oi=!oi;
			}	
		}
		}

	
	if (TMR1IF){ //overflow timer 1 ap�s 500ms
		RA1=1;
		TMR1IF=0;
		TMR1ON=0;
		TMR1IE=0;
		TMR1L=((ANGULO) & 0x00FF); // carregando 3036 no timer 1
		TMR1H=(((ANGULO)>>8) & 0x00FF); // carregando 3036 no timer 1
	}
		

}

/* INTERRUP��O DE TMR1:

NItmr1=(Fsist{Focs/4 ou cristal de 32,768kHz} x t[s])/(PS x (65536-TMR1))

*/

void main()
{
	ANSEL=0;
	ANSELH=0;
	TRISA=0b00111100;
	TRISB=0b00100000;
	TRISC=0;
	OPTION_REG=0b01000100; //PULL UP ATIVADO E INTERRUP��O POR BORDA DE DESCIDA DO RA2
	INTCON=0b11000000; //HABILITA INTERRUP��O TIMER1 E INTERRUP��O POR MUDAN�A DE N�VEL E POR MUDAN�A DO RA2
	INTE=1;
	
	/* BITS DE CONF DO INTCON:
	RABIF = FLAG QUE SINALIZA INTERRUP��O
	GIE = GLOBAL INTERRUPT
	PEIE = PERIPHERAL INTERRUPT
	RABIE = PORTA/B INTERRUPT ENABLE */
	T0IE=1;
	TMR0=250;
	T1CON=0b00000000; //prescaler 1:8;
	TMR1IE=1; //INTERRUP��O POR OVERFLOW TIMER1 ATIVADA
	TMR1L=((ANGULO) & 0x00FF); // carregando 3036 no timer 1
	TMR1H=(((ANGULO)>>8) & 0x00FF); // carregando 3036 no timer 1

	
	while(1){
	}
	
}