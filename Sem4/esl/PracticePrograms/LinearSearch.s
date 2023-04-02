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
		LDR 	R1, =num		;load the base address of the array into r1	
		LDR 	R2, =key		;load the base address of the key into r2	
		LDR 	R3, [R2]
        MOV     R0, #0          ; initialize index to 0
Loop    CMP     R0, #10         ; have we searched all 10 elements?
        BEQ     NotFound        ; if so, we didn't find the target
        LDR     R1, [R0], #4    ;load the current element into r1
        CMP     R1, R3  ; compare to the target value
        BEQ     Found           ; if they're equal, we found the target
        B       Loop            ; repeat the loop
NotFound
		MOV R4, #0				;0 for key not found
Found
		MOV R5, #1				;1 for key found
STOP 
		B STOP
num DCD 0,1,2,3,4,5,6,7,8,9    ; number array
		AREA mydata, DATA, READWRITE
key DCD 5
		END