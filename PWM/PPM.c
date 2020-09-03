#include <htc.h>
#include "lcd.h"
#include <stdio.h>

__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 8000000
#endif

unsigned char cont=0, CICLO_L=0, CICLO_H=0;


void interrupt alex()
{
	if (TMR2IF){
		TMR2ON=0;
		TMR2IF=0;
		RA1=1;
		__delay_us(500);
		RA1=0;
		GO_nDONE=1;
	}
	if (ADIF){
		ADIF=0;
		PR2=(255-ADRESH);
		TMR2ON=1;
	}
}

void main()
{
	OSCCON=0b01110000;
	ANSEL=0b00000001;
	ANSELH=0;
	ADCON0=0b00000001;
	ADCON1=0b00100000;
	TRISA=0b00000001;
	TRISB=0;
	TRISC=0;
	TMR2IF=0;
	T2CON=0b00010010;
	TMR2IE=1;
	ADIE=1;
	INTCON=0b11000000;
	PR2=255;
	TMR2ON=1;
	while(1){
	}
}	