
/* EXERC�CIO 4 - ALEXANDRE DE ALMEIDA LIMA - 4411*/

#include <htc.h>
#include "lcd.h"
#include <stdio.h>

__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 20000000
#endif


void interrupt xandi_lima(void){
//rotina de interrup��o
	if (TMR2IF) TRISC5=0;
	
	if (INTF){ //TESTA SE � INTERRUP��O POR MUDAN�A DE N�VEL DO RA2
		PORTA=PORTA;
		INTF=0;
		TMR2=0;
		
	}

	if (T0IF){
		T0IF=0;
		TMR0=6;
		CCPR1L--;
		if (!CCPR1L){
			T0IE=0;
			TMR2ON=0;
			RC5=1;
			
		}	
		}

		
}

/* INTERRUP��O DE TMR1:

NItmr1=(Fsist{Focs/4 ou cristal de 32,768kHz} x t[s])/(PS x (65536-TMR1))

*/

//void main()
//{
/*	ANSEL=0;
	ANSELH=0;
	TRISA=0b00111100;
	TRISB=0b00100000;
	TRISC=0;
	OPTION_REG=0b01000100; //PULL UP ATIVADO E INTERRUP��O POR BORDA DE DESCIDA DO RA2
	INTCON=0b11000000; //HABILITA INTERRUP��O TIMER1 E INTERRUP��O POR MUDAN�A DE N�VEL E POR MUDAN�A DO RA2
	INTE=1;
	
	BITS DE CONF DO INTCON:
	RABIF = FLAG QUE SINALIZA INTERRUP��O
	GIE = GLOBAL INTERRUPT
	PEIE = PERIPHERAL INTERRUPT
	RABIE = PORTA/B INTERRUPT ENABLE 
	T0IE=1;
	TMR0=250;
	T1CON=0b00000000; //prescaler 1:8;
	TMR1IE=1; //INTERRUP��O POR OVERFLOW TIMER1 ATIVADA
	TMR1L=((ANGULO) & 0x00FF); // carregando 3036 no timer 1
//	TMR1H=(((ANGULO)>>8) & 0x00FF); // carregando 3036 no timer */
	
	
void main()
{
	OSCCON=0b01000000; //1Mhz
	ANSEL=0;
	ANSELH=0;
	TRISA=0b00000100;
	TRISB=0b11110000;
	TRISC=0b00101111;
	PR2=128;
	CCP1CON=0b00001110;
	CCPR1L=128;
	TMR2IF=0;
	T2CON=0b00000010;
	TMR2IE=1;
	INTCON=0b11010000;
	TMR2ON=1;
	OPTION_REG=0b01000101;
	T0IE=1;
	TMR0=6;
	
	while(1){
	}
}	

	