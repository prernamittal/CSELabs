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
        LDR     R0, =num ; load the base address of the array into r0
		LDR 	R6, =key	;load the base address of the key into r6	
		LDR 	R7, [R6]
        MOV     R1, #10         ; number of elements in the array
        MOV     R2, #0          ; initialize low index to 0
        MOV     R3, #9      ; initialize high index to n-1
Loop    CMP     R2, R3          ; have we searched the entire range?
        BGT     NotFound        ; if so, we didn't find the target
        ADD     R4, R2, R3      ; compute mid index as (low + high) / 2
        LSR     R4, R4, #1      ; use logical shift right to divide by 2
        LDR     R5, [R0, R4, LSL #2] ; load the value at the mid index
        CMP     R5, R7		    ; compare to the target value
        BEQ     Found           ; if they're equal, we found the target
        BHI     HighHalf        ; if mid value > target, search lower half
        ADD     R2, R4, #1      ; otherwise, search upper half
        B       Loop
HighHalf
        SUB     R3, R4, #1      ; set high index to mid-1
        B       Loop
NotFound
		MOV R8, #0				;0 for key not found
Found
		MOV R9, #1				;1 for key found
STOP 
		B STOP
num	DCD 0,1,2,3,4,5,6,7,8,9     ; number array
		AREA mydata, DATA, READWRITE
key DCD 5     ; key to be found
		END
