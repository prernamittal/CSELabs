		AREA RESET, CODE, READONLY
		EXPORT __Vectors
__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		AREA myCode, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0, =SRC
		LDR R1, [R0]
		LDR R2, =DST
		MOV R3, #0
		MOV R4, #0
		MOV R5, #0
UP		CMP R1, #10
		BCC STO
		SUB R1, #10
		ADD R3, #1
		B UP
STO		LSL R1,R4
		ADD R4, #4
		ORR R5, R1
		MOV R1, R3
		MOV R3, #0
		CMP R1,#0
		BHI UP
		STR R5, [R2]
STOP 	
		B STOP
SRC DCD 0x11
		AREA MYDATA, DATA, READWRITE
DST DCD 0x0
		END