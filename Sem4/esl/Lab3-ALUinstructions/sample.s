		AREA RESET, DATA, READONLY
		EXPORT __Vectors
__Vectors 
		DCD 0x40001000 ; stack pointer value when stack is empty
		DCD Reset_Handler ; reset vector
		ALIGN
		AREA mycode, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R1, =VALUE1 ;pointer to the first value1
		LDR R2,=VALUE2 ;pointer to the second value
		UMULL R3, R4, R2, R1 ;Multiply the values from R1 and R2 and store 
 ;least significant 32 bit number into R3 and most
;significant 32 bit number into R4.
		LDR R2, =RESULT
		STR R4, [R2]
		ADD R2, #4
		STR R3, [R2] ; store result in memory
STOP
		B STOP
VALUE1 DCD 0X54000000 ; First 32 bit number
VALUE2 DCD 0X10000002 ; Second 32 bit number 
		AREA data, DATA, READWRITE
RESULT DCD 0