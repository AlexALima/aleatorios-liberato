#include <htc.h>
#include "lcd.h"
#include <stdio.h>

__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 1000000
#endif

unsigned char cont=0, CICLO_L=0, CICLO_H=0;


void interrupt alex()
{
	if (TMR2IF){
		TMR2IF=0;
		TRISC5=0;
		if(++cont==50){
			cont=0;
			CICLO_L=(PORTC & 0X0F);
			CICLO_H=(PORTB & 0XF0);
			CCPR1L=(CICLO_L | CICLO_H);
		}	
	}
}

void main()
{
	OSCCON=0b01000000;
	ANSEL=0;
	ANSELH=0;
	TRISA=0;
	TRISB=0b11110000;
	TRISC=0b00101111;
	PR2=249;
	CCP1CON=0b00001100;
	CCPR1L=0;
	TMR2IF=0;
	T2CON=0b00000000;
	TMR2IE=1;
	INTCON=0b11000000;
	TMR2ON=1;
	while(1){
	}
}	