.model small
.stack 256

.data 
 mag1 db "Input string: ",13,10,"$";13-left 10-new string
 mag2 db 13,10, "Enter the substring that you want to delete:", 13,10,"$"
 mag3 db 13,10, "Result:$" 
 mag4 db 13,10, "Empty string!$"
 str1 db 200 dup("$")
 str2 db 200 dup("$")
 flag dw 0

.code 
main proc
;enter pointer for data in ds and cs
 mov ax,data
 mov ds,ax
 mov es,ax      

;enter string
 mov dx,offset mag1
 call puts;to procedure - enter number next operation from IP
 mov dx, offset str1
 call gets  
 lea di,str1
 mov al,' '
 repe scasb
 jb Error 

;enter the substring 
 mov dx,offset mag2 
 call puts
 mov dx,offset str2
 call gets       

;cycle for the string
 xor cx,cx;deleting stack-pointer
 mov cl,str1[1];st1-the length str2 - the length
 sub cl,str2[1]
 jb End;jump if str2>str1 - end program
 inc cl
 cld;df=0
 
 lea si,str1[2];addres second operand to the first(not value)      
 lea di,str2[2]
 
Cycle: 
 mov flag,1
 call cmpSubstr 
 loop Cycle;for Cycle - to Cycle - CX-1 if CX!=0      
 
Error:
 mov dx,offset mag4
 mov ah,9
 int 21h
 
 
;showing string
End:
 mov dx,offset mag3
 call puts;to puts - address another comand
 mov dx,offset str1[2]
 call puts

;ending program
 mov ah,4Ch
 int 21h
 
 ret  
endp main
 
gets proc;function for enter string
 mov ah,10
 int 21h
 ret;return for the nearest operation
endp gets

puts proc;function for showing string
 mov ah,9
 int 21h
 ret
endp puts

deleteSubstr proc; function for deleting substring
 push si
 push di 
 mov cl,str1[1]
 mov di,bx
 repe movsb
 pop di
 pop si
 ret
endp deleteSubstr

cmpSubstr proc;function for checking substring
 push cx
 push si
 push di
 mov bx,si;complete adress of the beginning word 
 
 xor cx,cx;deleting stack-pointer - result to the first operand

 mov cl,str2[1]
 repe cmpsb
 je found;jump if 1=2
 jne notFound;jump if 1!=2
 
found:
 call deleteSubstr
 mov flag,0
notFound:
 pop di
 pop si
 pop cx
 add si,flag
 ret
endp cmpSubstr

end main

 