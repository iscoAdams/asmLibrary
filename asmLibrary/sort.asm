include emu8086.inc
org 100h           

#selection sort
#min program
call sort

int 20h    

#with strings
arr db 'zebah'  ;res = 'abehz' 
n equ $ -arr 

#with numbers
; n equ 14h   ;20 number as example to test the functionality
; arr db n dup (?)

count dw ?       
sort proc
mov cx,n 
dec cx       ;only compare the (n-1) elements and the last will be in the proper pos
mov si,0     
$l:
    mov bx,si        ;index of the element to be exchanged 
    mov count,cx     
    mov cx,n
    dec cx       
    sub cx,si         ;inner loop size
    mov di,si         ;inner loop cnt
    $inner:
        inc di
        mov al,arr[bx]
        cmp arr[di],al
        jge cont      ;innr loop condition
        mov bx,di
    cont: loop $inner
    mov al,arr[si]
    xchg al,arr[bx]
    mov arr[si],al
    inc si
    mov cx,count
loop $l
ret
sort endp         