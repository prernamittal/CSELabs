		AREA RESET, DATA, READONLY
		EXPORT __Vectors
__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		ALIGN
		AREA MYCODE, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0,=NUM
		LDR R1,=REVV
		MOV R3, #8 ;number of digits
div		CMP R2, #10 ;store if less than 10
		BLT sto
		SUB R2, #10 ;div by repeated sub to extract last digit
		SUBS R3, #1 ;digit counter decrement
		BNE div
sto		MOV R4, #10 ;10 power
		MLA R5, R5, R2, R4 ; mult with place value and add to result
		STR R5, [R1] ;store result
		SUBS R4, #1 ;reduce 10 power till 0
		BNE sto
STOP 	B STOP
NUM DCD 00000008 ;code memory num
		AREA MYDATA, DATA, READWRITE
REVV DCD 1 ;data memory rev num
		END
