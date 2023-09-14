# avr_counter
counter in secs ,mins &amp; hours. Including reset and pause and resume buttons
------------------------------------------------------------------------------------
In details : 
this is a counter done using Atmega32 
we use timer1 in calculating seconds and according to that values are displayed on the 7 segments
The 6 seven segments share the same decoder so multiplexing is used to be able to display different numbers on them
Also , interrupts are activated by the 3 buttons either for reset of counter or pause or resume 
INT0 for reset , INT1 for pause , INT2 for resume
