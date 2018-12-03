MODEL TINY
STACK 256
DATASEG
CODESEG
start:
  mov ah,35h
  mov al,9
    ;save in ES:BX address of old interrupt handler
  int 21h
  cli
  mov ax,es
  mov ds,ax
    ;in DS:DX - address of new interrupt handler
  mov dx,bx
  mov ah,25h
  mov al,60h
    ;Put old interrupt handler on number 60h
  int 21h
  mov ax,seg cmp_cl
  mov ds,ax
  mov dx, offset cmp_cl
  mov ah,25h
    ;Set our interrupt handler to 9th interrupt
  mov al,09h
  int 21h
  sti
    ;Infinite cycle
  infc:
    mov ah,06h
    mov dl,0FFh
      ;Read the symbol
    int 21h
      ;If key was not pressed, go to label
    jz infc
    mov dl,al ;
      ;Print the symbol
    int 21h
    jmp infc
      ;Our interrupt handler
  cmp_cl:
    in al,60h
      ;Del is pressed
    cmp al,83
    je DelPress
      ;Del is released
    cmp al,211
    je DelUnpr
      ;If some other key pressed call standart interrupt handler
    int 60h
    jmp CLEnd
  DelPress:                           ;Processing Delete Key
    in al,61h
      ;Send a signal to the keyboard and allow the beep
    or al,10000011b
    out 61h,al
      ;The signal to the keyboard
    and al,01111111b
    out 61h,al
      ;Timer control word
    mov al,10100110b
    out 43h,al                                ;Set
    mov al,22                                 ;frequency
    out 42h,al                                ;of the 3d timer
    push es
      ;Keyboard Buffer Segment
    mov ax, 040h
    mov es,ax
      ;Change the values of CapsLock flags
    mov al,es:[017h]
    xor al,64
    mov es:[017h],al
    mov al,es:[018h]
    or al,64
    mov es:[018h],al
    pop es
      ;Submitting hardware interrupt completion signal
    mov al,20h
    out 20h,al
    jmp CLEnd

  DelUnpr:                    ;Processing Delete Key Release
    in al,61h
    and al,11111100b
    out 61h,al
    in al,61h
    or al,10000000b
    out 61h,al
    and al,01111111b
    out 61h,al
    push es
    mov ax, 040h
    mov es,ax
    mov al,es:[018h]
    and al,191
    mov es:[018h],al
    pop es
    mov al,20h
    out 20h,al
  CLEnd:
    iret
end start
