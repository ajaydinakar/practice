;Ajay Dinakar   kandavalli   
	   .MODEL   small
     .STACK   100h
     .DATA
         msg1   DB     'too many ghost voters ',13,10,'$'
                 
        msg2   DB     'counting seems to be right ',13,10,'$' 
     .CODE
	      rdr PROC    near
	     mov   ah,1       ;1st digit   1st number 
		   int   21h
	     sub al,30h
       mov cl,10
		   mul cl           ;mul al x 10
		   mov bl,al        ;1st digit x 10 stored in bl
		   mov ah,1   
		   int 21h
       sub al,30h		 
		   add bl,al        ;the number stored in bl
         RET
    rdr  ENDP
    mdr  PROC near
         push ax
         push bx
         push cx
         push dx
         mov bp,sp
         mov ax,[bp+10]	
		     mov cl,10
		     mov ch,0
	 l:
	       mov ah,0
	       div cl
		 
		     mov dl,ah
		 
		     mov dh,0
		     push dx
		     add ch,1
		 
		     cmp al,0
		     ja l
		
	  m:   pop dx
		     add dl,30h
		     mov ah,2
		     int 21h
		     sub ch,1
		     cmp ch,0
		     ja m 
     
		     pop dx
         pop cx
		     pop bx
		     pop ax
		     RET
	  mdr ENDP			 
    Main:mov   ax,@data
         mov   ds,ax 
         CALL rdr          ;call for reading first number
		     mov dl,bl
		     CALL rdr          ;call for reading second number
		     add dl,bl         ;adding two numbers
		     mov dh,0
		     push dx
		     cmp  dl,100       ;comparing with hundred
		     ja  result1      
		     mov ah,9
         lea dx,msg2
         int 21h
         jmp exit
			
result1: mov ah,9
         lea dx,msg1
         int 21h
		 
  		   ;jmp main		 
    exit:
	     
		 
		 call mdr
		 pop dx
		 mov  ah,4ch
         int  21h
         END   Main
