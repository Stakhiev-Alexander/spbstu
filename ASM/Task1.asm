DOSSEG
.model TINY
.data

array db "IVAKIN   V.Y.",10,13
      db "PETRIN   R.A.",10,13
      db "KOTOVSKY A.A.",10,13
      db "KORKIN   V.G.",10,13
      db "ANTONOVA A.S.",10,13
      db "SYCHEV   D.Y.",10,13
      db "KOLMAKOV I.V.",10,13
      db "KOLYADOV S.V.",10,13
      db "MOSTOVIN A.V.",10,13
      db "SIDOROV  I.V.",10,13
      db '$'

array2 db "SBOROV  A.V.",10,13
      db "AKINSHIN I.V.",10,13
      db "MALEVICH V.A.",10,13
      db '$'

string db "---------------------",10,13,'$'

.code

swap:                 ; swap function
  pop dx
  pop bx                 ; bx = &array
  push dx
  mov cx, 15d               ; cx = num of loop
for:
  push bx
  add bx, cx
  dec bx
  mov al, [bx]               ; ax = first word
  mov dl, [bx+15d]            ; dx = second word
  mov [bx], dl
  mov [bx+15d], al
  pop bx
  loop for
  ret                ; end of swap function

start:
  mov ax, @data
  mov ds, ax

  mov bx, offset array
  mov di, offset array2
  add bx,150d

  mov dx, [di]               ; dx = word of array2
  mov [bx], dx               ; [bx] = last word of array

  ; print new list
  mov dx, offset array
  mov ah, 9h
  int 21h

   mov dx, offset string
   mov ah, 9h
   int 21h

  mov cx, 12d
  loop2:
    push cx
    mov bx, offset array

    mov cx, 12d
    mov di, offset array
    mov si,14
  loop1:
    mov al, [bx+15d]
    mov ah, [bx]
    cmp al, ah
    je m1
    cmp al, ah
    ja inc_str
    mov bx, di
    push bx
    push cx
    push bx
    call swap
    pop cx
    pop bx
    mov di, bx
    jmp inc_str
  m1:
    add bx,1d
    sub si,1
    cmp si,0
    jne loop1

    jmp inc_str
  inc_str:
    mov bx, di
    add bx, 15d
    mov di, bx
    loop loop1

    pop cx
    loop loop2

    mov dx, offset array
    mov ah, 9h
    int 21h
    mov ah, 4ch
    int 21h

end start
