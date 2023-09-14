#include <avr/io.h>
#include<util/delay.h>
#include "display_function.h"
extern unsigned char secs;
extern unsigned char mins;
extern unsigned char hours;
void display()
{
	PORTA=(PORTA&0xC0)|(1<<PA0);//ONLY FIRST SEVEN SEGMENT ON;
	PORTC=(PORTC&0xF0)|(secs%10); //LET THE VALUE ON DISPLAY = SECS%10
	_delay_ms(2);
	PORTA=(PORTA&0xC0)|(1<<PA1);//ONLY SECOND SEVEN SEGMENT ON;
	PORTC=(PORTC&0xF0)|(secs/10); //LET THE VALUE ON DISPLAY = SECS/10
	_delay_ms(2);
	PORTA=(PORTA&0xC0)|(1<<PA2);//ONLY THIRD SEVEN SEGMENT ON;
	PORTC=(PORTC&0xF0)|(mins%10); //LET THE VALUE ON DISPLAY = MINS%10
	_delay_ms(2);
	PORTA=(PORTA&0xC0)|(1<<PA3);//ONLY SECOND SEVEN SEGMENT ON;
	PORTC=(PORTC&0xF0)|(mins/10); //LET THE VALUE ON DISPLAY = MINS/10
	_delay_ms(2);
	PORTA=(PORTA&0xC0)|(1<<PA4);//ONLY SECOND SEVEN SEGMENT ON;
	PORTC=(PORTC&0xF0)|(hours%10); //LET THE VALUE ON DISPLAY = HOURS%10
	_delay_ms(2);
	PORTA=(PORTA&0xC0)|(1<<PA5);//ONLY SECOND SEVEN SEGMENT ON;
	PORTC=(PORTC&0xF0)|(hours/10); //LET THE VALUE ON DISPLAY = HOURS/10
	_delay_ms(2);
}
