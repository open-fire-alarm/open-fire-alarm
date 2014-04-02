#include <stdio.h>

/*Real time clock program - INTERRUPT DRIVEN TIMER*/

void timer(void); /*Function Prototype for ISR*/

int hours,mins,secs,ticks; /* GLOBAL VARIABLES FOR RETURNING VALUES*/


void main()
{
    unsigned char *pactl,*tmsk2;

	tmsk2=(unsigned char*)0x24;
	pactl=(unsigned char*)0x26;

	*pactl=0x03; /*Set prescaler to maximum*/
	*tmsk2=0x40; /*Enable RTI interrupt*/
}

@interrupt void timer(void)
{
    unsigned char *tflg2;
    tflg2=(unsigned char*)0x25;

	ticks++;
	if (ticks==30)
	{
		ticks=0;
		secs++;
	}
	if (secs==60)
	{
		secs=0;
		mins++;
	}
	if (mins==60)
	{
		mins=0;
		hours++;
	}
	if (hours==24)
	{
		hours=0;
	}
	*tflg2=0x40; /*Reset RTI flag*/
}
