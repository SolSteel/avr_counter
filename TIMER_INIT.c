#include<avr/io.h>
#include "TIMER_INIT.h"
void TIMER1_INIT()
{
	TCCR1A=(1<<FOC1A);	//NON PWM
	TCCR1B=(1<<WGM12)|(1<<CS12)|(1<<CS10);//PRESCALER = 1024
	TIMSK|=(1<<OCIE1A);//ENABLE COMPARE MODE FOR A
	OCR1A=1000; //assuming FREQ=1mhz , PRESCALER: 1024 , t = 1ms so COUNTER 1S IS = 1000
	TCNT1=0; //INITIALIZE COUNTER TO 0
	SREG|=1<<7; //enable interrupts
}
