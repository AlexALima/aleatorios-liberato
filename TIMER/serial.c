#include <htc.h>
#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>
__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 4000000
#endif

#define BIT7 RA5
#define BIT6 RA4
#define BIT5 RA3
#define BIT4 RC5
#define BIT3 RC4
#define BIT2 RC6
#define BIT1 RC7
#define BIT0 RB6

char conta_int=0;
char segundos=0;
char DADO_RX=0;
bit bit_7=0, bit_6=0, bit_5=0, bit_4=0, bit_3=0, bit_2=0, bit_1=0, bit_0=0;
char byte;


void interrupt nome(void){
//rotina de interrupção
	char lixo;	
	if (RCIF==1) {//testa se é recepção serial
		if (FERR){//testa se tem erro de frame
			lixo=RCREG;
		}
		else{
			DADO_RX=RCREG;
		}
	}
}

void init_serial (void){
	//configura a porta serial para 9600bps
	//habilita a interrupção por recepção serial
	//***********   MUDAR ISSO AQUI PRA TER 1200 {
		//CONFIGURAÇÃO DA TRANSMISSÃO SERIAL 
		SYNC=0;
		BRGH=0;
		BRG16=1;
		SPBRG=207;
		SPBRGH=0;
	// }
		SPEN=1;
		TX9=0;
		TXEN=1;
		
		//CONFIGURAÇÃO DA RECEPÇÃO SERIAL
	//***********   MUDAR ISSO AQUI PRA TER 1200 {
		RCIE=1; //HABILITA A INTERRUPÇÃO POR INTERRUPÇÃO
		PEIE=1; //HABILITA A INTERRUPÇÃO DOS PERIFÉRICOS
		RX9=0; //RECEBER 8 BITS
		CREN=1; //HABILITA A RECEPÇÃO SERIAL
}

void tx_serial (unsigned char dado) {
	while(!TRMT){}; //verifica se o buffer de transmissão está ocupado
	TXREG=dado; //transmite o dado
	}
	

void enviar_endereco (void){
tx_serial('a');
__delay_ms(10);
tx_serial('l');
__delay_ms(10);
tx_serial('r');
__delay_ms(10);
tx_serial('s');
__delay_ms(10);
tx_serial('c');
__delay_ms(10);

}

void atualizar(){
lcd_goto(0);
printf("\n%d %d %d %d %d %d %d %d",bit_7,bit_6,bit_5,bit_4,bit_3,bit_2,bit_1,bit_0);}

void main()
{
	char dado_anterior=0;
	ANSEL=0;
	ANSELH=0;
	TRISA=0;
	TRISB=0;
	TRISC=0;
	TRISA2=1;
	TRISA5=1;
	TRISA4=1;
	TRISA3=1;
	TRISC4=1;
	TRISC5=1;
	TRISC6=1;
	TRISC7=1;
	TRISB6=1;
	RB5=1;
	OPTION_REG=0b11010101; // PRESCALER 1:64 CLOCK INTERNO
	INTCON=0b10100000; //HABILITA INTERRUPÇÃO TIMER0
	OPTION_REG=0b11010101;
	char lixo=0;
	T0IE=0;
	init_serial();
	lcd_init();
	printf(" TI - Conv.Num.");
	printf("\n%d %d %d %d %d %d %d %d",bit_7,bit_6,bit_5,bit_4,bit_3,bit_2,bit_1,bit_0);
	

	
	while(1){
		if (BIT7){ bit_7=!bit_7;
			__delay_ms(10);
			atualizar();
			while(BIT7){};
		}
		if (BIT6){ bit_6=!bit_6;
			__delay_ms(10);
			atualizar();
			while(BIT6){};
		}
		if (BIT5){ bit_5=!bit_5;
			__delay_ms(10);
			atualizar();
			while(BIT5){};
		}
		if (BIT4){ bit_4=!bit_4;
			__delay_ms(10);
			atualizar();
			while(BIT4){};
		}
		if (BIT3){ bit_3=!bit_3;
			__delay_ms(10);
			atualizar();
			while(BIT3){};
		}
		if (BIT2){ bit_2=!bit_2;
			__delay_ms(10);
			atualizar();
			while(BIT2){};
		}
		if (BIT1){ bit_1=!bit_1;
			__delay_ms(10);
			atualizar();
			while(BIT1){};
		}
		if (BIT0){ bit_0=!bit_0;
			__delay_ms(10);
			atualizar();
			while(BIT0){};
		}
		if (RA2){
			__delay_ms(10);
			if(bit_0) byte=(byte+1);
			if(bit_1) byte=(byte+2);
			if(bit_2) byte=(byte+4);
			if(bit_3) byte=(byte+8);
			if(bit_4) byte=(byte+16);
			if(bit_5) byte=(byte+32);
			if(bit_6) byte=(byte+64);
			if(bit_7) byte=(byte+128);
			enviar_endereco();
			RB5=0;
			RB4=1;
			tx_serial(byte);
			__delay_ms(100);
			RB5=0;
			RB4=1;
		
		}
	
	}
	
}	
