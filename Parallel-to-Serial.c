/* The program reads a character from the keyboard, displays it on
screen transmits it over parallel port, reads the received
character on the serial port and displays it on the screen.
*/

#include <stdio.h>
#include <dos.h>
#include <conio.h>
#define DATA 0x378
#define STAT 0x379
#define CNTRL 0x37a
#define SP2 0x2f8
#define LCR 0x2fb
#define DLL 0x2f8
#define DLH 0x2f9
#define LSR 0x2fd
#define IER 0x2f9
#define IIR 0x2fa

main()
{
unsigned inc1,inc2,inr;
    int ch;
    int rcv;

/*-------------------Initialization-------------------*/

    outportb(DATA,0xff);   /* initialize data port */
    outportb(CNTRL,0x00);
    outportb(LCR,0x00);
    outportb(IER,0x03);   /*set interrupt enable register*/
    outportb(LCR,0x83);     /* set bit format, DLAB=1 */
    outportb(DLL,0x60);     /* set baud rate=1200 */
    outportb(DLH,0x00);


/*-------------------PARALLEL PORT-------------------*/

    clrscr();
    while((ch=getch()) != '\r')
    {
        putchar(ch);
        delay(1);
wbusy:  inc1=inportb(STAT);
        while ((inc1 & 0x80) == 0x80) {goto wbusy;};
        outportb(DATA,ch);

        delay(5);
        outportb(CNTRL,0x01);  /* send strobe */

wack:   inc2=inportb(STAT);
        while ((inc2 & 0x40) == 0x40) {goto wack;};
        delay(2);
        outportb(CNTRL,0x00);  /* clear strobe */
        delay(5);
        outportb(DATA,0xff);   /* remove data */


/*------------------- Serial Port-------------------*/

wdata:  inr=inportb(IIR);
        while((inr & 0x04) != 0x04) {goto wdata;};
        outportb(LCR,0x03);    /*   dlab=0  */
        rcv=inportb(SP2);
        putchar(rcv);
		};

/*----------------------------------------------------------*/
    /*   send next byte   */

}