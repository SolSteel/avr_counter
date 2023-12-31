#include <avr/io.h>
#include "INTERRUPTS_INIT.h"
void INT_INIT()//PD2,PD3,PB2
{
	SREG|=1<<7;//ENABLE INTERRUPTS
	DDRD&=~(1<<PD2)&~(1<<PD3); //BUTTONS INPUT FOR INT0,INT1
	DDRB&=~(1<<PB2); //BUTTONS INPUT FOR INT2
	PORTD|=(1<<PD2); //INTERNAL PULL UP FOR INT0
	PORTB|=(1<<PB2); //INTERNAL PULLUP FOR INT2
	GICR|=(1<<INT0)|(1<<INT1)|(1<<INT2);//ENABLE INT0,INT1,INT2
	MCUCR|=(1<<ISC11)|(1<<ISC01)|(1<<ISC10); //INT0 FALLING EDGE, INT1 RISING EDGE
	MCUCR&=~(1<<ISC00);
	MCUCSR&=~(1<<ISC2);//INT2 FALLING EDGE TRIGGERED
}
