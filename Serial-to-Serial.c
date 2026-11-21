/* Program reads a key/character from keyboard, displays it on screen, transmits it over serial port and displays the received character on the screen */

#include <stdio.h>
#include <dos.h>
#include <conio.h>
#define THR 0x2f8
#define RBR 0x2f8
#define SP2 0x2f8
#define LCR 0x2fb
#define DLL 0x2f8
#define DLH 0x2f9
#define LSR 0x2fd
#define IER 0x2f9
#define IIR 0x2fa

main()
{
    unsigned inspl;
    int rcv,ch;

/*-------------------Initialization-------------------*/

    outportb(LCR,0x00);
    outportb(IER,0x03);   /*set interrupt enable register */
    outportb(LCR,0x83);   /* set bit format, DLAB=1 */
    outportb(DLL,0x60);   /* set baud rate=1200 */
    outportb(DLH,0x00);

    while((ch=getche())!='\r'){
        outportb(LCR,0x03);
        outportb(THR,ch);
        delay(20);
        outportb(THR,0x00);

/*-------------------- Serial Port Read --------------------*/

wdata:  inspl=inportb(IIR);
        while((inspl & 0x04) != 0x04) {goto wdata;};
        rcv=inportb(RBR);
        putchar(rcv);
        outportb(LCR,0x83);
/*----------------------------------------------------------*/

    };

    return 0;

}
