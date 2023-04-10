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
		LDR R0, =num         ; load number address into R0
		LDRH R1, [R0]                ; load number into R1
		MOV R2, #10                  ; set loop counter to 10
		LDR R3, =table       ; load table address into R3

loop
		MUL R4, R1, R2               ; multiply number by loop counter
		STRH R4, [R3], #2            ; store result in half-word and increment address
		SUBS R2, R2, #1              ; decrement loop counter
		BNE loop           ; repeat loop if counter not zero
STOP 
		B STOP
num	DCD 5     ; number
		AREA mydata, DATA, READWRITE
table DCD 0     ; output table
		END
