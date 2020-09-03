
/* EXERCÍCIO 4 - ALEXANDRE DE ALMEIDA LIMA - 4411*/

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
	//habilita a interrupção por recepção serial
	//***********   MUDAR ISSO AQUI PRA TER 1200 {
		//CONFIGURAÇÃO DA TRANSMISSÃO SERIAL 
		SYNC=0;
		BRGH=0;
		BRG16=1;
		SPBRG=129;
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

void interrupt nome(void){
//rotina de interrupção
	char lixo;	
	if (RCIF==1) {//testa se é recepção serial
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
	OPTION_REG=0b00000000; //PULL UP ATIVADO E INTERRUPÇÃO POR BORDA DE DESCIDA DO RA2
	INTCON=0b11011000; //HABILITA INTERRUPÇÃO TIMER1 E INTERRUPÇÃO POR MUDANÇA DE NÍVEL E POR MUDANÇA DO RA2
	init_serial();
	while(1);
}