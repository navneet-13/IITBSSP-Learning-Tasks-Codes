#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
int a=0;

int main(void){
	sei();
	DDRB = 0xFF;
	DDRA = 0xFF;
	DDRF = 0xFF;
	int UBR = 51; 
	UBRR0H = (char)UBR >> 8;
	UBRR0L = (char)UBR ;
	UCSR0B = 1<<RXEN0 | 1<<TXEN0 | 1<<TXCIE0;
	UCSR0C = 1<<UCSZ00 | 1<<UCSZ01 | 1<<USBS0;
	TCCR1B = 1<<WGM12 | 1<<CS12 | 1<<CS10;              //prescaler set to 1/1024
	TIMSK = 1<<OCIE1A;
	OCR1A = 7812.5;                                     //Compare value that corresponds to 1sec
	TCNT1 = 0;
    while (1){
		
		PORTB ^= 1;
		_delay_ms(200);
		a++;
		if(a==3){
			UDR0 = 0b11000001;
			_delay_ms(2);
		    a=0;}
}
}

ISR(USART0_TX_vect){
	PORTF ^= 1;
	sei();                  //global bit enabled for nested interrupt
	_delay_ms(2000);        
}

ISR(TIMER1_COMPA_vect){
	UDR0 = 0b11101100;        // data transmission in the timer interrupt routine
	PORTA ^= 0xFF;
}