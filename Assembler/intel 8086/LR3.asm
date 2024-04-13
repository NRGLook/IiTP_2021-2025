.model small
.stack 100h
.data
    bufferStr db 7,7 dup('$')
    massiv dw 60 dup(0)           
    
    msg1 db 0Dh,0Ah, 'Input $'
    msg2 db ': $'
    msg3 db 0Dh,0Ah,'Error!', 0Dh,0Ah,'$'
    msg4 db 0Dh,0Ah,'Decreasing', 0Dh,0Ah,'$'
    msg5 db 0Dh,0Ah,'Increasing', 0Dh,0Ah,'$'  
    msg6 db 0Dh,0Ah,'Mixed', 0Dh,0Ah,'$' 
    msg7 db 0Dh,0Ah,'Enter the length of array:',0Dh,0Ah,'$'
      
.code
start:       
   
print macro str              
    push ax
    push di       
    mov ax,0
    mov ah,9
    mov dx,offset str
    int 21h 
    pop di     
    pop ax
endm
                
;main algoritm                          
    mov ax,data
    mov ds,ax
    mov cx,30 ;how many elements in array
    mov di,0   
    mov ax,1
                        
getStr1:   
    print msg1 
    call ShowNumber
    inc ax     
    print msg2
    call input 
    cmp dx,offset msg3
    je error1 
    add di,2
    jmp cont
error1:       
    dec ax 
    inc cx
cont:       
    loop getStr1                                  
    mov ax,0
    mov cx,29 
    mov si,0   
checkMassiv:
    mov bx,massiv[si+2]
    cmp massiv[si],bx
    jg minus2
    cmp massiv[si],bx
    jl plus2
    jmp contin22
minus2: 
    sub ax,1
    jmp contin22  
plus2:
    add ax,1
contin22:   
    add si,2
    loop checkMassiv 
    
    cmp ax,-29
    je decreasing
    cmp ax,29
    je increasing
    jmp mixed
                                
decreasing:
    print msg4     
    jmp contin11 
    
increasing: 
    print msg5
    jmp contin11      
    
mixed:            
    print msg6
    
contin11:                            
    mov ax,4C00h
    int 21h          
    
;proc                          
input proc        
    push ax
    push cx                
    push di
    mov ah,0Ah
    mov dx,offset bufferStr
    int 21h
               
    mov di,10            
    mov ax,0               
    mov bx,0 
                   
    cmp bufferStr[2],'-'
    je minus        

plus:                
    cmp bufferStr[1],6
    je error
      
    cmp bufferStr[1],0
    je error
    
    mov si,offset bufferStr+2 
    mov cl,bufferStr[1]   
    jmp loopCheck

minus: 
    cmp bufferStr[1],0
    je error
    
    mov si,offset bufferStr+3
    mov cl,bufferStr[1]
    dec cx     
    jmp loopCheck

loopCheck:
    mov bl,[si]             
    inc si                 
    cmp bl,'0'            
    jl error         
    cmp bl,'9'             
    jg error        
    sub bl,'0'             
    mul di                 
    jc error         
    add ax,bx              
    jc error         
    loop loopCheck 
    
    cmp ax,32767
    jg error
    
    mov cx,1       
    cmp bufferStr[2],'-'
    je mulMinus 
    jmp stop
        
mulMinus: 
    neg ax         
    jmp stop
                               
error:
    print msg3
    mov cx,2      
stop:  
pop di         
mov massiv[di],ax
pop cx 
pop ax  
ret
input endp

;Output of a signed 16-bit integer      
ShowNumber proc
        push    ax
        push    bx
        push    cx
        push    dx
        mov     bx,     10      ;the base of the number system (divisor)
        xor     cx,     cx      ;the number of characters in the number module / clear CX
        or      ax,     ax      ;for a negative number
        jns     tools
                neg     ax      ;change the sign (make it positive)
                push    ax      ;and display the "-" (minus) symbol on the screen
                mov     ah,     02h
                mov     dl,     '-'
                int     21h
                pop     ax
        tools:                  ;divide the number by 10
                xor     dx,     dx
                div     bx
                push    dx      ;we save the rest in the stack
                inc     cx      ;number of digits in a number
                or      ax,     ax
        jnz     tools           ;repeat until there are numbers in the number
        mov     ah,     02h
        functionfordisplay:
                pop     dx      ;extract the digits (the remainder of the division by 10) from the stack
                add     dl,'0'  ;convert to numeric characters
                int     21h     ;and we display them on the screen
        loop    functionfordisplay
    pop     dx
    pop     cx
    pop     bx
    pop     ax
        ret
ShowNumber       endp        
end start