#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TIMER_INIT.h"
#include "SEVEN_SEGMENTS_INIT.h"
#include "display_function.h"
#include "INTERRUPTS_INIT.h"
#include "ISR.h"
unsigned char secs=0;
unsigned char mins=0;
unsigned char hours=0;
int main (void)
{
	INT_INIT();
	TIMER1_INIT();
	SEVEN_SEGMENT_INIT();
	while(1)
	{
		display();
	}
}
