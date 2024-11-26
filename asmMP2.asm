
section .data

section .text
bits 64
default rel 
global asmMP2
extern printf

asmMP2:
    
    ; xmm4 = x1 , xmm1 = x2 , xmm2 = y1 , xmm3 = y2
    ;sqrt ( (X2 - X1)^2 + (Y2 - Y1)^2 )
    
    movss xmm4, xmm0
    
    ;x2 - x1
    subss xmm1, xmm4
    ;y2 - y1
    subss xmm3, xmm2
    
    ;(X2 - X1)^2
    mulss xmm1, xmm1
    ;(Y2 - Y1)^2
    mulss xmm3, xmm3
    ;(X2 - X1)^2+(Y2 - Y1)^2
    vaddss xmm4, xmm1, xmm3
    ;sqrt
    sqrtss xmm0, xmm4
    ret