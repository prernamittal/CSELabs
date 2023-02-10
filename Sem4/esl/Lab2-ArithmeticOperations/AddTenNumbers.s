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
		LDR R0, =SRC ;pointer to SRC
		MOV R2, #10
loop	LDR R3, [R0], #4
		ADDS R5, R5, R3
		SUBS R2, #1
		BNE loop
		LDR R6, =DST
		STR R5, [R6]
STOP
		B STOP
SRC DCD 1,2,3,4,5,6,7,8,9,10
		AREA data, DATA, READWRITE
DST DCD 0
		END
