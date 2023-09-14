#include <avr/io.h>
#include <avr/interrupt.h>
#include "ISR.h"
extern unsigned char secs;
extern unsigned char mins;
extern unsigned char hours;
ISR (INT0_vect)
{
	secs=0;
	mins=0;
	hours=0;
	TCNT1=0; //INITIALIZE COUNTER TO 0
}
ISR (INT1_vect)
{
	TCCR1B&=0xF8; //CLEAR LAST 3 BITS (CLOCK PAUSES)
}
ISR (INT2_vect)
{
	TCCR1B|=(1<<CS12)|(1<<CS10); //ASSUMING PRESCALER IS 1024
}
ISR (TIMER1_COMPA_vect)
{
	secs++;
	if(secs==60)
	{
		mins++;
		secs=0;
	}
	if(mins==60)
	{
		hours++;
		mins=0;
	}
}
