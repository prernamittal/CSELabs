		AREA RESET, DATA, READONLY
		EXPORT __Vectors
__Vectors
		DCD 0X10001000 
		DCD Reset_Handler 
		ALIGN
		AREA mycode, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0, =SRC ; Load address of SRC into R0
		LDR R1, =DST ; Load the address of DST onto R1 
		LDR R3, [R0] ; Load data pointed by R0 into R3
		STR R3,[R1] ; Store data from R3 into the address pointed by R1
STOP B STOP
		AREA mydata, DATA, READWRITE
SRC DCD 0 ;SRC location in data memory
DST DCD 0 ;DST location in data memory		
		END