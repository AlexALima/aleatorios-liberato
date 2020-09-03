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
# 3 "C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
	psect config,class=CONFIG,delta=2 ;#
# 3 "C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
	dw 0xFFFC & 0xFFF7 & 0xFFEF & 0xFFDF & 0xFFFF & 0xFFFF & 0xFCFF & 0xFBFF & 0xF7FF ;#
	FNROOT	_main
	FNCALL	_xandi_lima,_write_ee
	FNCALL	intlevel1,_xandi_lima
	global	intlevel1
	FNROOT	intlevel1
	global	_INTCON
psect	text120,local,class=CODE,delta=2
global __ptext120
__ptext120:
_INTCON	set	11
	global	_PORTB
_PORTB	set	6
	global	_CARRY
_CARRY	set	24
	global	_EEIF
_EEIF	set	108
	global	_GIE
_GIE	set	95
	global	_INTE
_INTE	set	92
	global	_INTF
_INTF	set	89
	global	_OPTION_REG
_OPTION_REG	set	129
	global	_TRISA
_TRISA	set	133
	global	_TRISB
_TRISB	set	134
	global	_TRISC
_TRISC	set	135
	global	_EEIE
_EEIE	set	1132
	global	_ANSEL
_ANSEL	set	286
	global	_ANSELH
_ANSELH	set	287
	global	_EEADR
_EEADR	set	269
	global	_EEDAT
_EEDAT	set	268
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
	file	"EEPROM.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_write_ee
?_write_ee:	; 0 bytes @ 0x0
	global	?_xandi_lima
?_xandi_lima:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	write_ee@dado
write_ee@dado:	; 1 bytes @ 0x0
	ds	1
	global	??_write_ee
??_write_ee:	; 0 bytes @ 0x1
	global	write_ee@adr
write_ee@adr:	; 1 bytes @ 0x1
	ds	1
	global	??_xandi_lima
??_xandi_lima:	; 0 bytes @ 0x2
	ds	5
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	??_main
??_main:	; 0 bytes @ 0x0
	ds	3
;;Data sizes: Strings 0, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      7       7
;; BANK0           80      3       3
;; BANK1           80      0       0
;; BANK2           80      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _xandi_lima in COMMON
;;
;;   _xandi_lima->_write_ee
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _xandi_lima in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _xandi_lima in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _xandi_lima in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 3, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 3     3      0       0
;;                                              0 BANK0      3     3      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 0
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (1) _xandi_lima                                           5     5      0      30
;;                                              2 COMMON     5     5      0
;;                           _write_ee
;; ---------------------------------------------------------------------------------
;; (2) _write_ee                                             2     1      1      30
;;                                              0 COMMON     2     1      1
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 2
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;
;; _xandi_lima (ROOT)
;;   _write_ee
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      7       7       1       50.0%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       4       2        0.0%
;;BANK0               50      3       3       3        3.8%
;;BITBANK1            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK1               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK2            50      0       0       6        0.0%
;;BANK2               50      0       0       7        0.0%
;;ABS                  0      0       0       8        0.0%
;;BITBANK0            50      0       0       9        0.0%
;;DATA                 0      0       0      10        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 38 in file "C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
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
;;      Temps:          0       3       0       0
;;      Totals:         0       3       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
	line	38
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 6
; Regs used in _main: [wreg+status,2]
	line	39
	
l3024:	
;EEPROM.c: 39: ANSEL=0;
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	clrf	(286)^0100h	;volatile
	line	40
;EEPROM.c: 40: ANSELH=0;
	clrf	(287)^0100h	;volatile
	line	41
;EEPROM.c: 41: TRISA=0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	clrf	(133)^080h	;volatile
	line	42
	
l3026:	
;EEPROM.c: 42: TRISB=0xF0;
	movlw	(0F0h)
	movwf	(134)^080h	;volatile
	line	43
	
l3028:	
;EEPROM.c: 43: TRISC=0;
	clrf	(135)^080h	;volatile
	line	45
;EEPROM.c: 45: EECON1=0b00000100;
	movlw	(04h)
	bsf	status, 5	;RP0=1, select bank3
	bsf	status, 6	;RP1=1, select bank3
	movwf	(396)^0180h	;volatile
	line	46
;EEPROM.c: 46: INTCON=0b11010000;
	movlw	(0D0h)
	movwf	(11)	;volatile
	line	47
	
l3030:	
;EEPROM.c: 47: OPTION_REG=0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	clrf	(129)^080h	;volatile
	goto	l3032
	line	49
;EEPROM.c: 49: while(1){
	
l897:	
	line	51
	
l3032:	
;EEPROM.c: 51: if (!INTE){
	btfsc	(92/8),(92)&7
	goto	u2271
	goto	u2270
u2271:
	goto	l3032
u2270:
	line	52
	
l3034:	
;EEPROM.c: 52: _delay((unsigned long)((200)*(4000000/4000.0)));
	opt asmopt_off
movlw  2
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
movwf	((??_main+0)+0+2),f
movlw	4
movwf	((??_main+0)+0+1),f
	movlw	186
movwf	((??_main+0)+0),f
u2287:
	decfsz	((??_main+0)+0),f
	goto	u2287
	decfsz	((??_main+0)+0+1),f
	goto	u2287
	decfsz	((??_main+0)+0+2),f
	goto	u2287
	clrwdt
opt asmopt_on

	line	53
	
l3036:	
;EEPROM.c: 53: INTF=0;
	bcf	(89/8),(89)&7
	line	54
	
l3038:	
;EEPROM.c: 54: INTE=1;
	bsf	(92/8),(92)&7
	goto	l3032
	line	55
	
l898:	
	goto	l3032
	line	56
	
l899:	
	line	49
	goto	l3032
	
l900:	
	line	63
	
l901:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_xandi_lima
psect	text121,local,class=CODE,delta=2
global __ptext121
__ptext121:

;; *************** function _xandi_lima *****************
;; Defined at:
;;		line 22 in file "C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
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
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_write_ee
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text121
	file	"C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
	line	22
	global	__size_of_xandi_lima
	__size_of_xandi_lima	equ	__end_of_xandi_lima-_xandi_lima
	
_xandi_lima:	
	opt	stack 6
; Regs used in _xandi_lima: [wreg+status,2+status,0+pclath+cstack]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_xandi_lima+1)
	movf	fsr0,w
	movwf	(??_xandi_lima+2)
	movf	pclath,w
	movwf	(??_xandi_lima+3)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	btemp+1,w
	movwf	(??_xandi_lima+4)
	ljmp	_xandi_lima
psect	text121
	line	24
	
i1l2136:	
;EEPROM.c: 24: if(EEIF && EEIE){
	btfss	(108/8),(108)&7
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l892
u1_20:
	
i1l2138:	
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	btfss	(1132/8)^080h,(1132)&7
	goto	u2_21
	goto	u2_20
u2_21:
	goto	i1l892
u2_20:
	line	25
	
i1l2140:	
;EEPROM.c: 25: EEIF=0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(108/8),(108)&7
	line	26
;EEPROM.c: 26: WREN=0;
	bsf	status, 5	;RP0=1, select bank3
	bsf	status, 6	;RP1=1, select bank3
	bcf	(3170/8)^0180h,(3170)&7
	line	27
;EEPROM.c: 27: EEIE=0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bcf	(1132/8)^080h,(1132)&7
	line	28
	
i1l892:	
	line	30
;EEPROM.c: 28: }
;EEPROM.c: 30: if (INTF && INTE){
	btfss	(89/8),(89)&7
	goto	u3_21
	goto	u3_20
u3_21:
	goto	i1l894
u3_20:
	
i1l2142:	
	btfss	(92/8),(92)&7
	goto	u4_21
	goto	u4_20
u4_21:
	goto	i1l894
u4_20:
	line	31
	
i1l2144:	
;EEPROM.c: 31: write_ee(0x01,PORTB);
	bcf	status, 5	;RP0=0, select bank0
	movf	(6),w	;volatile
	movwf	(??_xandi_lima+0)+0
	movf	(??_xandi_lima+0)+0,w
	movwf	(?_write_ee)
	movlw	(01h)
	fcall	_write_ee
	line	32
	
i1l2146:	
;EEPROM.c: 32: INTF=0;
	bcf	(89/8),(89)&7
	line	33
	
i1l2148:	
;EEPROM.c: 33: INTE=0;
	bcf	(92/8),(92)&7
	goto	i1l894
	line	34
	
i1l893:	
	line	36
	
i1l894:	
	movf	(??_xandi_lima+4),w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	btemp+1
	movf	(??_xandi_lima+3),w
	movwf	pclath
	movf	(??_xandi_lima+2),w
	movwf	fsr0
	swapf	(??_xandi_lima+1)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_xandi_lima
	__end_of_xandi_lima:
;; =============== function _xandi_lima ends ============

	signat	_xandi_lima,88
	global	_write_ee
psect	text122,local,class=CODE,delta=2
global __ptext122
__ptext122:

;; *************** function _write_ee *****************
;; Defined at:
;;		line 10 in file "C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
;; Parameters:    Size  Location     Type
;;  adr             1    wreg     unsigned char 
;;  dado            1    0[COMMON] unsigned char 
;; Auto vars:     Size  Location     Type
;;  adr             1    1[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         1       0       0       0
;;      Locals:         1       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         2       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_xandi_lima
;; This function uses a non-reentrant model
;;
psect	text122
	file	"C:\Users\Alexandre\Documents\Colégio\micros\EEPROM\EEPROM.c"
	line	10
	global	__size_of_write_ee
	__size_of_write_ee	equ	__end_of_write_ee-_write_ee
	
_write_ee:	
	opt	stack 6
; Regs used in _write_ee: [wreg]
;write_ee@adr stored from wreg
	movwf	(write_ee@adr)
	line	11
	
i1l2124:	
;EEPROM.c: 11: GIE=0;
	bcf	(95/8),(95)&7
	line	12
	
i1l2126:	
;EEPROM.c: 12: EEDAT=dado;
	movf	(write_ee@dado),w
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	movwf	(268)^0100h	;volatile
	line	13
;EEPROM.c: 13: EEADR=adr;
	movf	(write_ee@adr),w
	movwf	(269)^0100h	;volatile
	line	14
;EEPROM.c: 14: EECON2=0x55;
	movlw	(055h)
	bsf	status, 5	;RP0=1, select bank3
	bsf	status, 6	;RP1=1, select bank3
	movwf	(397)^0180h	;volatile
	line	15
;EEPROM.c: 15: EECON2=0xAA;
	movlw	(0AAh)
	movwf	(397)^0180h	;volatile
	line	16
	
i1l2128:	
;EEPROM.c: 16: WR=1;
	bsf	(3169/8)^0180h,(3169)&7
	line	17
	
i1l2130:	
;EEPROM.c: 17: GIE=1;
	bsf	(95/8),(95)&7
	line	18
	
i1l2132:	
;EEPROM.c: 18: EEIE=1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(1132/8)^080h,(1132)&7
	goto	i1l889
	line	19
	
i1l2134:	
	line	20
;EEPROM.c: 19: return;
	
i1l889:	
	return
	opt stack 0
GLOBAL	__end_of_write_ee
	__end_of_write_ee:
;; =============== function _write_ee ends ============

	signat	_write_ee,8312
psect	text123,local,class=CODE,delta=2
global __ptext123
__ptext123:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
