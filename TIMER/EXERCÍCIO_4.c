
/* EXERC�CIO 4 - ALEXANDRE DE ALMEIDA LIMA - 4411*/

#include <htc.h>
#include "lcd.h"
#include <stdio.h>

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 20000000
#endif

char DADO_RX=0;

void init_serial (void){
	//configura a porta serial para 9600bps
	//habilita a interrup��o por recep��o serial
	//***********   MUDAR ISSO AQUI PRA TER 1200 {
		//CONFIGURA��O DA TRANSMISS�O SERIAL 
		SYNC=0;
		BRGH=0;
		BRG16=1;
		SPBRG=129;
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

void interrupt nome(void){
//rotina de interrup��o
	char lixo;	
	if (RCIF==1) {//testa se � recep��o serial
		if (FERR){//testa se tem erro de frame
			lixo=RCREG;
		}
		else{
			DADO_RX=RCREG;
			RA0=!RA0;
			tx_serial('A');
		}
	}
}


void main()
{
	ANSEL=0;
	ANSELH=0;
	TRISA=0b11111110;
	TRISB=0b00100000;
	TRISC=0xFF;
	RA0=0;
	OPTION_REG=0b00000000; //PULL UP ATIVADO E INTERRUP��O POR BORDA DE DESCIDA DO RA2
	INTCON=0b11011000; //HABILITA INTERRUP��O TIMER1 E INTERRUP��O POR MUDAN�A DE N�VEL E POR MUDAN�A DO RA2
	init_serial();
	while(1);
}