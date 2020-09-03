#include <htc.h>
#include <lcd.h>
#include <stdio.h>

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ 4000000
#endif

#define led_amarelo RC4
#define led_azul RC5
#define led_verde RC6
#define led_vermelho RC7
#define	LCD_RS RA4

unsigned char buffer=0xFF;
unsigned char senha_1=0xFF;
unsigned char senha_2=0xFF;
unsigned char senha_3=0xFF;
unsigned char senhar_1=0xFF;
unsigned char senhar_2=0xFF;
unsigned char senhar_3=0xFF;
unsigned char tentativas=0;
unsigned char tempo=0;
bit ok=0;
bit foi=0;

void write_ee(unsigned char adr, unsigned char dado){
	GIE=0;
        WREN=1;
	EEDAT=dado;
	EEADR=adr;
	EECON2=0x55;
	EECON2=0xAA;
	WR=1;
	GIE=1;
	EEIE=1;
	return;
}

void entrada_senhas(void){
    INTE=0;

    lcd_clear();
    printf("Novas senhas:\nSenha 1:");
    LCD_RS = 0;
    lcd_write(0x0D);
    LCD_RS = 1;
    while(buffer==0xFF) SLEEP();
    write_ee(0x10,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF)SLEEP();
    write_ee(0x11,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF)SLEEP();
    write_ee(0x12,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    
    __delay_ms(500);

    lcd_clear();

    printf("Novas senhas:\nSenha 2:");
    while(buffer==0xFF)SLEEP();
    write_ee(0x20,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF)SLEEP();
    write_ee(0x21,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF)SLEEP();
    write_ee(0x22,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    __delay_ms(500);

    lcd_clear();

    printf("Novas senhas:\nSenha 3:");
    while(buffer==0xFF)SLEEP();
    write_ee(0x30,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF)SLEEP();
    write_ee(0x31,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF)SLEEP();
    write_ee(0x32,buffer);
    while(!ok)SLEEP();
    ok=0;
    printf("%d",buffer);
    buffer=0xFF;
    LCD_RS = 0;
    lcd_write(0x0C);
    LCD_RS = 1;
    __delay_ms(500);

    INTE=1;

}

void timer(void){
    GIE=0;
    while(tempo<=30){
        lcd_clear();
        printf("Espere %ds",tempo);
        __delay_ms(500);
        __delay_ms(500);
        tempo++;
    }
    tempo=0;
    GIE=1;
}

void senhas(void){
    lcd_clear();
    printf("Digite a senha:\nSenha:");
    LCD_RS = 0;
    lcd_write(0x0D);
    LCD_RS = 1;
    while(buffer==0xFF && foi==0)SLEEP();
    if(foi) return;
    senha_1=buffer;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF && foi==0)SLEEP();
    if(foi) return;
    senha_2=buffer;
    printf("%d",buffer);
    buffer=0xFF;
    while(buffer==0xFF && foi==0)SLEEP();
    if(foi) return;
    senha_3=buffer;
    printf("%d",buffer);
    buffer=0xFF;
    LCD_RS = 0;
    lcd_write(0x0C);
    LCD_RS = 1;
    __delay_ms(500);
    EEADR=0x10;
    RD=1;
    NOP();
    senhar_1=EEDAT;
    EEADR=0x11;
    RD=1;
    NOP();
    senhar_2=EEDAT;
    EEADR=0x12;
    RD=1;
    NOP();
    senhar_3=EEDAT;
    if((senha_1==senhar_1)&&(senha_2==senhar_2)&&(senha_3==senhar_3)){
        led_amarelo=0;
        led_azul=0;
        led_vermelho=0;
        led_verde=0;
        led_amarelo=1;
        tentativas=0;
        return;
    }
    else{
        senhar_1=0xFF;
        senhar_2=0xFF;
        senhar_3=0xFF;
    }
    EEADR=0x20;
    RD=1;
    NOP();
    senhar_1=EEDAT;
    EEADR=0x21;
    RD=1;
    NOP();
    senhar_2=EEDAT;
    EEADR=0x22;
    RD=1;
    NOP();
    senhar_3=EEDAT;
    if((senha_1==senhar_1)&&(senha_2==senhar_2)&&(senha_3==senhar_3)){
        led_amarelo=0;
        led_azul=0;
        led_vermelho=0;
        led_verde=0;
        led_verde=1;
        tentativas=0;
        return;
    }
    else{
        senhar_1=0xFF;
        senhar_2=0xFF;
        senhar_3=0xFF;
    }
    EEADR=0x30;
    RD=1;
    NOP();
    senhar_1=EEDAT;
    EEADR=0x31;
    RD=1;
    NOP();
    senhar_2=EEDAT;
    EEADR=0x32;
    RD=1;
    NOP();
    senhar_3=EEDAT;
    if((senha_1==senhar_1)&&(senha_2==senhar_2)&&(senha_3==senhar_3)){
        led_amarelo=0;
        led_azul=0;
        led_vermelho=0;
        led_verde=0;
        led_azul=1;
        tentativas=0;
        return;
    }
    else{
        senhar_1=0xFF;
        senhar_2=0xFF;
        senhar_3=0xFF;
    }
    lcd_clear();
    printf("Senha incorreta");
    led_amarelo=0;
    led_azul=0;
    led_vermelho=0;
    led_verde=0;
    tentativas++;
    if(tentativas==4){
        printf("\nBloqueado!");
        tentativas=0;
        __delay_ms(500);
        __delay_ms(500);
        led_amarelo=0;
        led_azul=0;
        led_vermelho=0;
        led_verde=0;
        led_vermelho=1;
        timer();
        led_vermelho=0;
        entrada_senhas();
        return;
    }
    printf("\nTente de novo");
    __delay_ms(500);
    __delay_ms(500);
}

void interrupt xandi_lima(void){
	
	if(EEIF && EEIE){
		EEIF=0;
		WREN=0;
                ok=1;
	}
	
	if (RBIF && RBIE){
            __delay_ms(50);
            RBIF=0;
            if(!RB5){
                RB1=1;
                RB2=0;
                if(!RB5) buffer=0;
                else buffer=1;
            }
            if(!RB6){
                RB1=1;
                RB2=0;
                if(!RB6) buffer=2;
                else buffer=3;
            }
            if(!RB7){
                RB1=1;
                RB2=0;
                if(!RB7) buffer=4;
                else buffer=5;
            }
            RB1=0;
            RB2=0;
	}

        if(INTE && INTF){
            __delay_ms(50);
            INTF=0;
            foi=1;
            led_amarelo=0;
            led_azul=0;
            led_vermelho=0;
            led_verde=0;
        }
	
}	
void main()
{	
	ANSEL=0;
	ANSELH=0;
	TRISA=0;
	TRISB=0b11111001;
	TRISC=0x0F;
        led_amarelo=0;
        led_azul=0;
        led_vermelho=0;
        led_verde=0;
	EECON1=0;  //modo gravação ativado
	INTCON=0b11011000;
        IOCB=0b11100000;
	OPTION_REG=0;
        lcd_init();

	while(1){
            senhas();
            if(foi){
                foi=0;
                entrada_senhas();
            }
	}
			
			
		
			
	
	
}