.model small 
 .stack 100h 
 .code 
start: mov ax,DATA 
 mov ds,ax 
 mov dx,offset message
 mov ah,9
 int 21h 
 mov dx,offset message2
 int 21h
 mov ax,4C00h
 int 21h 
 .data 
message db "Hello World!",0Dh,0Ah,'$'    
message2 db "Hello World2",0Dh,0Ah,'$'
 end start
