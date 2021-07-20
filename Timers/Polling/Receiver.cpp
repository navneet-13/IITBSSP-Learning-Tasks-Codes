#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void){

	sei();
	DDRB = 0xFF;
	int UBR = 51;
	UBRR0H  = (char)UBR >> 8;
	UBRR0L  = (char)UBR ;
	UCSR0B = 1<<RXEN0 | 1<<TXEN0 | 1<<RXCIE0 ;
	UCSR0C = 1<<UCSZ00 | 1<<UCSZ01 | 1<<USBS0;
	
	while (1){
		
	}
}

ISR(USART0_RX_vect){
	int a;
	a = UDR0;
	PORTB = a;

	
}

