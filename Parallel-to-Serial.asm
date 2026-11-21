/*Assembly Program: The Program polls for Strobe to be asserted to low by the PC, (indicating data ready) reads data from the parallel port acknowledges it, 
transmits it over transmitter pin and deasserts Busy to low to indicate that next cycle may begin.*/

        .org 0000h
        ljmp main

        .org 0023h
        nop
        nop
        clr scon.1
        nop
        reti

main:   .org 0050h
        anl tmod,#0fh
        orl tmod,#20h
        mov th1,#0cch
        orl pcon,#80h
        orl tcon,#40h
        mov scon,#50h
        mov ie,#90h
        setb p3.5
getdata: setb p3.4
strwait: jb p3.2,strwait
        clr p3.4
        nop
        mov a,p1
        clr p3.5
        nop
        nop
stb:    jnb p3.2,stb
        setb p3.5
        nop
        nop
        mov sbuf,a
        nop
        nop
        nop
        nop
        sjmp getdata
        .end
