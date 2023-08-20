		AREA RESET,DATA,READONLY
		EXPORT __Vectors
__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0, =NUM
		LDR R7, =RES
		LDR R1,[R0]
		MOV R2,#1
		MOV R3,#0xA
		MOV R4,#0
		MOV R5,#0xF
UP		MOV R6,R1
		AND R6,R5
		MLA R4,R6,R2,R4
		MUL R2,R3
		LSR R1,#4
		CMP R1,#0
		BNE UP
		STR R4,[R7]
STOP	B STOP	
NUM DCD 0x35
		AREA mydata,DATA,READWRITE
RES DCD 0
		END