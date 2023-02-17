		AREA RESET,DATA,READONLY 
		EXPORT __Vectors 
__Vectors 
		DCD 0X10001000 
		DCD Reset_Handler 
		ALIGN 
		AREA MYCODE,CODE,READONLY 
		ENTRY
		EXPORT Reset_Handler 
Reset_Handler 
		MOV R0,#8 ;dividend
		MOV R1,#3  ;divisor
		MOV R2,#0 ;q
		MOV R3,#0 ;r
		LDR R4, =Q
		LDR R5, =R
loop	CMP R0,R1
		BCC skip
		SUBS R0,R1
		ADD R2,#1
		B loop
skip	MOV R3,R0
		STR R2,[R4]
		STR R3,[R5]
STOP 
		B STOP 
		AREA MYDATA, DATA, READWRITE 
Q DCD 0
R DCD 0
		END