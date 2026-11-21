/*Assembly Program : The program reads received byte from serial register whenever received interrupt occurs and transmits it back over the transmit pin.*/

        .org 0000h
        ljmp main

        .org 0023h
        jbc scon.1,xmit
        jbc scon.0,recv
recv:   mov R0,0bh
        djnz R0,delay
        mov a,sbuf
        mov ie,#80h
        mov sbuf,a
        nop
        nop
        nop
        jbc scon.1,xmit
        mov ie,#90h
        reti
xmit:   mov ie,#90h
        reti
delay:  nop
        ret

main:   .org 0055h
        anl tmod,#0fh
        orl tmod,#20h
        mov th1,#0cch
        orl pcon,#80h
        orl tcon,#40h
        mov scon,#50h
        orl ie,#90h
wait:   ajmp wait
        .end