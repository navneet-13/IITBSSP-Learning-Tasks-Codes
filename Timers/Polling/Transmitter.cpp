#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void){
	sei();
	//Initializing
	DDRB = 0xFF;
	int UBR = 51; 
	UBRR0H = (char)UBR >> 8;
	UBRR0L = (char)UBR ;
	UCSR0B = 1<<RXEN0 | 1<<TXEN0 | 1<<TXCIE0 ;
	UCSR0C = 1<<UCSZ00 | 1<<UCSZ01 | 1<<USBS0;
	TCCR1B = 1<<WGM12 | 1<<CS12 | 1<<CS10;
	OCR1A = 7812.5;
    while (1){
		UDR0 = 0b11001100;
		_delay_ms(2);
		UDR0 = 0b11110000;
		_delay_ms(2);
		/*while(!(TIFR & (1<<OCF1A)))
			;
		TIFR = 1<<OCF1A;*/
			
    }
}

ISR(USART0_TX_vect){
	TCNT1 = 0;
	PORTB ^= 1<<PINB0;
	while(!(TIFR & (1<<OCF1A)))    //Waiting for flag to be set
			;
	TIFR = 1<<OCF1A;               //Clear the flag
	
}

