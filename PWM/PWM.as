opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 10920"

opt pagewidth 120

	opt lm

	processor	16F690
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
# 5 "C:\Users\Alexandre\Documents\Colégio\micros\PWM\PPM.c"
	psect config,class=CONFIG,delta=2 ;#
# 5 "C:\Users\Alexandre\Documents\Colégio\micros\PWM\PPM.c"
	dw 0xFFFC & 0xFFF7 & 0xFFEF & 0xFFFF & 0xFFFF & 0xFFFF & 0xFCFF & 0xFBFF & 0xF7FF ;#
	FNROOT	_main
	FNCALL	intlevel1,_alex
	global	intlevel1
	FNROOT	intlevel1
	global	_CICLO_H
	global	_CICLO_L
	global	_cont
	global	_ADCON0
psect	text76,local,class=CODE,delta=2
global __ptext76
__ptext76:
_ADCON0	set	31
	global	_ADRESH
_ADRESH	set	30
	global	_INTCON
_INTCON	set	11
	global	_T2CON
_T2CON	set	18
	global	_ADIF
_ADIF	set	102
	global	_CARRY
_CARRY	set	24
	global	_GIE
_GIE	set	95
	global	_GO_nDONE
_GO_nDONE	set	249
	global	_RA1
_RA1	set	41
	global	_TMR2IF
_TMR2IF	set	97
	global	_TMR2ON
_TMR2ON	set	146
	global	_ADCON1
_ADCON1	set	159
	global	_OSCCON
_OSCCON	set	143
	global	_PR2
_PR2	set	146
	global	_TRISA
_TRISA	set	133
	global	_TRISB
_TRISB	set	134
	global	_TRISC
_TRISC	set	135
	global	_ADIE
_ADIE	set	1126
	global	_TMR2IE
_TMR2IE	set	1121
	global	_ANSEL
_ANSEL	set	286
	global	_ANSELH
_ANSELH	set	287
	global	_EEADR
_EEADR	set	269
	global	_EEDATA
_EEDATA	set	268
	global	_EECON1
_EECON1	set	396
	global	_EECON2
_EECON2	set	397
	global	_RD
_RD	set	3168
	global	_WR
_WR	set	3169
	global	_WREN
_WREN	set	3170
	file	"PWM.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssCOMMON,class=COMMON,space=1
global __pbssCOMMON
__pbssCOMMON:
_CICLO_H:
       ds      1

_CICLO_L:
       ds      1

_cont:
       ds      1

; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2
	clrf	((__pbssCOMMON)+0)&07Fh
	clrf	((__pbssCOMMON)+1)&07Fh
	clrf	((__pbssCOMMON)+2)&07Fh
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_alex
?_alex:	; 0 bytes @ 0x0
	global	??_alex
??_alex:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	ds	5
	global	??_main
??_main:	; 0 bytes @ 0x5
;;Data sizes: Strings 0, constant 0, data 0, bss 3, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      5       8
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK2           80      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _alex in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _alex in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _alex in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _alex in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 0
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (1) _alex                                                 5     5      0       0
;;                                              0 COMMON     5     5      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;
;; _alex (ROOT)
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      5       8       1       57.1%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       0       2        0.0%
;;BANK0               50      0       0       3        0.0%
;;BITBANK1            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK1               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK2            50      0       0       6        0.0%
;;BANK2               50      0       0       7        0.0%
;;ABS                  0      0       8       8        0.0%
;;BITBANK0            50      0       0       9        0.0%
;;DATA                 0      0       8      10        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 32 in file "C:\Users\Alexandre\Documents\Colégio\micros\PWM\PPM.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"C:\Users\Alexandre\Documents\Colégio\micros\PWM\PPM.c"
	line	32
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 7
; Regs used in _main: [wreg+status,2]
	line	33
	
l2144:	
;PPM.c: 33: OSCCON=0b01110000;
	movlw	(070h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(143)^080h	;volatile
	line	34
;PPM.c: 34: ANSEL=0b00000001;
	movlw	(01h)
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	movwf	(286)^0100h	;volatile
	line	35
	
l2146:	
;PPM.c: 35: ANSELH=0;
	clrf	(287)^0100h	;volatile
	line	36
	
l2148:	
;PPM.c: 36: ADCON0=0b00000001;
	movlw	(01h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(31)	;volatile
	line	37
	
l2150:	
;PPM.c: 37: ADCON1=0b00100000;
	movlw	(020h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(159)^080h	;volatile
	line	38
	
l2152:	
;PPM.c: 38: TRISA=0b00000001;
	movlw	(01h)
	movwf	(133)^080h	;volatile
	line	39
;PPM.c: 39: TRISB=0;
	clrf	(134)^080h	;volatile
	line	40
;PPM.c: 40: TRISC=0;
	clrf	(135)^080h	;volatile
	line	41
	
l2154:	
;PPM.c: 41: TMR2IF=0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(97/8),(97)&7
	line	42
	
l2156:	
;PPM.c: 42: T2CON=0b00010010;
	movlw	(012h)
	movwf	(18)	;volatile
	line	43
	
l2158:	
;PPM.c: 43: TMR2IE=1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(1121/8)^080h,(1121)&7
	line	44
	
l2160:	
;PPM.c: 44: ADIE=1;
	bsf	(1126/8)^080h,(1126)&7
	line	45
	
l2162:	
;PPM.c: 45: INTCON=0b11000000;
	movlw	(0C0h)
	movwf	(11)	;volatile
	line	46
	
l2164:	
;PPM.c: 46: PR2=255;
	movlw	(0FFh)
	movwf	(146)^080h	;volatile
	line	47
	
l2166:	
;PPM.c: 47: TMR2ON=1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(146/8),(146)&7
	goto	l901
	line	48
;PPM.c: 48: while(1){
	
l900:	
	line	49
	
l901:	
	line	48
	goto	l901
	
l902:	
	line	50
	
l903:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_alex
psect	text77,local,class=CODE,delta=2
global __ptext77
__ptext77:

;; *************** function _alex *****************
;; Defined at:
;;		line 15 in file "C:\Users\Alexandre\Documents\Colégio\micros\PWM\PPM.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          5       0       0       0
;;      Totals:         5       0       0       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text77
	file	"C:\Users\Alexandre\Documents\Colégio\micros\PWM\PPM.c"
	line	15
	global	__size_of_alex
	__size_of_alex	equ	__end_of_alex-_alex
	
_alex:	
	opt	stack 7
; Regs used in _alex: [wreg+status,2+status,0]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_alex+1)
	movf	fsr0,w
	movwf	(??_alex+2)
	movf	pclath,w
	movwf	(??_alex+3)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	btemp+1,w
	movwf	(??_alex+4)
	ljmp	_alex
psect	text77
	line	16
	
i1l2126:	
;PPM.c: 16: if (TMR2IF){
	btfss	(97/8),(97)&7
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l2136
u1_20:
	line	17
	
i1l2128:	
;PPM.c: 17: TMR2ON=0;
	bcf	(146/8),(146)&7
	line	18
;PPM.c: 18: TMR2IF=0;
	bcf	(97/8),(97)&7
	line	19
;PPM.c: 19: RA1=1;
	bsf	(41/8),(41)&7
	line	20
	
i1l2130:	
;PPM.c: 20: _delay((unsigned long)((500)*(8000000/4000000.0)));
	opt asmopt_off
movlw	249
movwf	(??_alex+0)+0,f
u224_27:
	clrwdt
decfsz	(??_alex+0)+0,f
	goto	u224_27
	nop2	;nop
	clrwdt
opt asmopt_on

	line	21
	
i1l2132:	
;PPM.c: 21: RA1=0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(41/8),(41)&7
	line	22
	
i1l2134:	
;PPM.c: 22: GO_nDONE=1;
	bsf	(249/8),(249)&7
	goto	i1l2136
	line	23
	
i1l895:	
	line	24
	
i1l2136:	
;PPM.c: 23: }
;PPM.c: 24: if (ADIF){
	btfss	(102/8),(102)&7
	goto	u2_21
	goto	u2_20
u2_21:
	goto	i1l897
u2_20:
	line	25
	
i1l2138:	
;PPM.c: 25: ADIF=0;
	bcf	(102/8),(102)&7
	line	26
	
i1l2140:	
;PPM.c: 26: PR2=(255-ADRESH);
	decf	(30),w	;volatile
	xorlw	0ffh
	addlw	0FFh
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(146)^080h	;volatile
	line	27
	
i1l2142:	
;PPM.c: 27: TMR2ON=1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(146/8),(146)&7
	goto	i1l897
	line	28
	
i1l896:	
	line	29
	
i1l897:	
	movf	(??_alex+4),w
	movwf	btemp+1
	movf	(??_alex+3),w
	movwf	pclath
	movf	(??_alex+2),w
	movwf	fsr0
	swapf	(??_alex+1)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_alex
	__end_of_alex:
;; =============== function _alex ends ============

	signat	_alex,88
psect	text78,local,class=CODE,delta=2
global __ptext78
__ptext78:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
