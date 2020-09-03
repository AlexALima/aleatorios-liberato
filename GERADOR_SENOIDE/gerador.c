#include <htc.h>
#include <stdio.h>

#pragma config FOSC = HS// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

#ifndef _XTAL_FREQ
   #define _XTAL_FREQ 8000000
#endif


unsigned int a=230;
unsigned char ok=0;
unsigned char cont=0;
unsigned char tempo=0;

void interrupt xandi(void){


    

	if (TMR2IF){
		TMR2IE=0;
		TRISC5=1;
                TRISC4=1;
	}

        if (TMR1IF){
		TMR1IF=0;
                TMR1L=(63535&0xFF);
                TMR1H=((63535>>8)&0xFF);
                a=((ADRESH)+24);


                GO=1;
	}


}

void main()
{
	ANSEL=0b00000100;
	ANSELH=0;
	TRISA=0b00000100;
	TRISB=0b11110000;
	TRISC=0b00111111;
        ADCON0=0b00001001;
        ADCON1=0b01000000;
	PR2=100;
	CCP1CON=0b10001100;
	CCPR1L=0;
	TMR2IF=0;
	T2CON=0b00000000;
	TMR2IE=1;
        INTCON=0b11000000;
        TMR2ON=1;
        T1CON=0b00000001;
        TMR1L=(63535&0xFF);
        TMR1H=((63535>>8)&0xFF);
        TMR1IE=1;
	while(1){
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=0;
            while(++ok<=a);
            NOP();
            ok=0;
            RA0=!RA0;
            RA1=!RA0;
            CCPR1L=10;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=21;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=31;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=41;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=50;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=59;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=67;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=74;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=81;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=87;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=91;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=95;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=98;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=99;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=100;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=99;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=98;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=95;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=91;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=87;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=81;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=74;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=67;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=59;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=50;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=41;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=31;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=21;
            while(++ok<=a);
            NOP();
            ok=0;
            CCPR1L=10;
	}
}