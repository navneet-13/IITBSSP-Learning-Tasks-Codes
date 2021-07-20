#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

char transmit(char data){
	SPDR = data;
	while(!(SPSR & 1<<SPIF))					/**  MASTER **/
		;
	return SPDR;
}

int main(void){
	int pressed = 0;
	DDRC = 0b11111111;
	DDRD = 0x00;
	DDRE = 0xFF;
	DDRF = 0x01;
	DDRB  = 0b00000111;
	sei();
	
	SPCR  = 1<<SPE | 1<<MSTR | 1<<SPIE;
    while (1) {
		PORTB |= 1<<PINB0;
		
		if(!(PIND & 1<<PIND0)){
			if(pressed == 0){
				pressed = 1;
				PORTF ^= 1<<PINF0;
				
				PORTB &= 0xFE;
				
				SPDR = 0x00;
				_delay_ms(10);
				SPDR = 0xAA;
				_delay_ms(10);
					
				SPDR = 0xBB;
				_delay_ms(10);
				
				SPDR = 0xCC;
				_delay_ms(10);	
					
		}
		}
		else{
			pressed = 0;}
			
		
    }
}

ISR(SPI_STC_vect){
	
	PORTE ^= 1<<0;
		
}
