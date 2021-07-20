#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>


int main(void){
	DDRB  = 0x00;
	DDRA = 0xFF;
	DDRC = 0xFF;
	PORTA = 0x00;
	
	int pressed=0;
	sei();
	
	//setting ubrr
	int ubrr = 51;
	UBRR0H =  (unsigned char) (ubrr>>8);
	UBRR0L =  (unsigned char) ubrr;
	
	//Initialize UART0
	UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<TXCIE0);
	UCSR0C = (1<<USBS0) | (3<<UCSZ00);
	
	
	
	while(1){
		if(!(PINB & 1<<PINB0)){
			if(pressed == 0){
				pressed = 1;
				
				while(!(UCSR0A & (1<<UDRE0)))
					;
				UDR0 = 0b10100001;
				
			}
		}
		else{
			pressed = 0;
			
		}
		}
		
	
}

ISR(USART0_TX_vect){
		PORTA ^= 0x01;
}