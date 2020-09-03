#include <htc.h>
#include <stdio.h>

__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_ON & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF);

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 20000000
#endif


int a=0;
char forma=0;
int cont=0;

void interrupt xandi(){
    if(INTF){
        __delay_ms(20);
        INTF=0;
        forma++;
        if(forma==4) forma=0;
    }
    if(ADIF){
        ADIF=0;
        cont=(ADRESH*4);
    }
}


void main()
{
    ANSEL=0;
    ANSELH=0;
    OPTION_REG=0;
    INTCON=0b11010000;
    ADCON0=0b01000001; //LEFT_J - VDD - CANAL 0 - ON
    ADCON1=0b01100000; // 1:64
    ADIE=1;
    TRISA0=1;
    TRISA2=1;
    TRISC=0;
    PORTC=0;
    while(1){
            while(forma==0){
        while(PORTC<128){
        a++;
        PORTC=(PORTC+a);
        for(char b=0;b<cont;b++) __delay_us(1);
        }
        while(PORTC<255){
        a--;
        PORTC=(PORTC+a);
        for(char b=0;b<cont;b++) __delay_us(1);
        }
        a=0;
        while(PORTC>128){
        a++;
        PORTC=(PORTC-a);
        for(char b=0;b<cont;b++) __delay_us(1);
        }
        while(PORTC>0){
        a--;
        PORTC=(PORTC-a);
        for(char b=0;b<cont;b++) __delay_us(1);
        }
        
        a=0;

        }
    while(forma==1){
        PORTC=0;
        while(PORTC!=0xFF){
            PORTC++;
        }
        while(PORTC){
            PORTC--;
        }
    }
    while(forma==2){
        PORTC=0;
        while(PORTC!=0xFF){
            PORTC++;
        }
    }
    while(forma==3){
        PORTC=0xFF;
        while(PORTC){
            PORTC--;
        }
    }
            GO=1;
    }
}
