#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
int main(void)
{
    DDRB |= 1<<PINB0; 
    PORTB |= 0<<PINB0;
	
    
    unsigned char receiveData;
	sei();
	
    int ubrr = 51;
    UBRR0H =  (unsigned char) (ubrr>>8);
    UBRR0L =  (unsigned char) ubrr;
    
    UCSR0B = 0xD8; //(1<<RXEN0) | (1<<TXEN0) | 1<<RXCIE0;
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);
	
	while (1) {
		/**while(!(UCSR0A & (1<<RXC0)))
			;
		receiveData = UDR0;
		if(receiveData == 0b10100011){
			PORTB ^= (1<<PINB0);                      //this commented block of code was for polling method communication
		}
		/*while(!(UCSR0A & 1<<UDRE0))
			;
		UDR0 = receiveData;**/
			
    }
}

ISR(USART0_RX_vect){
	char a;
	a = UDR0;
	if(a == 0b10100001)
		{ PORTB ^= 1<<0;
			
		}
}

