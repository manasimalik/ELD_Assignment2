#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRB = 0x20; 			//This line sets the LED on board(Digital Pin 13) as output. This can also be written in binary as 0b00100000 or as DDRB | = (1 << DDB5);
	while(1){				// Infinte loop for the code to run endlessly.
		PORTB |= (1<<PB5);  // Sets the bit to 1 or HIGH. (OR with 1)
		_delay_ms(1000);
		PORTB &= ~(1<<PB5); // Clears the bit previously set to HIGH or 1. (And with 0)
		_delay_ms(500);	//Delay between blinks is 500msec
	} 
return 0;}
