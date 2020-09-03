#include <htc.h>
#include <lcd.h>
#include <stdio.h>

#include <htc.h>
#include "lcd.h"
__CONFIG(FOSC_INTRC_NOCLKOUT & WDTE_OFF & PWRTE_ON & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);


#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 8000000
#endif

#define CS RB1

bit oi;
bit ei;
unsigned int boi=0;

void I2C_Init(){
    SSPSTAT=0b00000000;
    SSPCON=0b00100001;  // SPI Master mode
    SSPCON2=0b00000000;
    SSPIE=1;
}



void interrupt xandi_lima(void){

        if(INTE && INTF){
            __delay_ms(50);
            INTF=0;
            oi=1;
        }

        if(SSPIE && SSPIF){
            SSPIF=0;
            ei=1;
        }

}
void main()
{
        OSCCON=0b01110000;
	ANSEL=0;
	ANSELH=0;
	TRISA=0;
	TRISB=0b00000001;
	TRISC=0;
        TRISC4=1;
	INTCON=0b11011000;
	OPTION_REG=0;
        oi=0;
        ei=0;
        I2C_Init();
        RB1=0;
        PORTA=0;
        CS=1;
	while(1){
            if(oi){
                while(boi<0xFF){
                oi=0;
                CS=0;
                SSPBUF=0b00000110;
                while(!ei);
                ei=0;
                CS=1;
                CS=0;
                SSPBUF=0b00000010;
                while(!ei);
                ei=0;
                SSPBUF=boi;
                while(!ei);
                ei=0;
                SSPBUF=boi;
                while(!ei);
                ei=0;
                CS=1;
                __delay_ms(10);
                boi++;
                }
            }
            __delay_ms(100);
            RA0=!RA0;
	}


}