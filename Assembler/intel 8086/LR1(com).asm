.model tiny ; model of memory for COM
 .code ; beginning of the code segment
 org 100h ; initial IP value = 100h
start: mov ah,9 ; DOS function number - in AN
 mov dx,offset message ; the address of the line is in DX
 int 21h ; calling a DOS system function
 ret ; completion of the COM program
message db "Hello World!",0Dh,0Ah,'$' ; output string
 end start ; end of the program








