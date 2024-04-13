.model small
.data
mes1 db 0ah,'Hello World',0dh,0ah,'$';message for displaying hello world and moving to next line  
mes2 db 0ah,'Hello World',0dh,0ah,'$'

display1 MACRO msg ;a macro is similar to fuctions in higher level language 
LEA DX,msg         ;loads dx effective address of msg
MOV AH,09H
INT 21H            ;dos interept for displaying the message
ENDM

.code
MOV AX,@data       ;initialze data segment
MOV DS,AX
display1 mes1      ;calling macro for displaying message          
display1 mes2
MOV AH,4CH
INT 21H
END