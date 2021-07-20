#include <avr/io.h>
#define F_CPU 8000000UL
# include <util/delay.h>
#include <avr/interrupt.h>
int a = 0;


int main(void){
	sei();
    DDRB = 0b00001000;
	DDRD = 0b11111111;
	DDRE = 0x00;
	SPCR = 1<<SPE | 1<<SPIE;
    while (1) {
		
			}
	}

ISR(SPI_STC_vect){
	PORTF ^= 1;
	if(a==0){
		SPDR = 0x03;           //after 1st transfer write 0x03 to SPDR that will be sent to Master
		a++;
		}
	else if(a==1){
		SPDR = 0x12;
		PORTD = SPDR;
		a++;
		}
	
	else if(a==2){
		SPDR = 0x19;
		PORTD = SPDR;
		a++;
		}
	
	else if(a==3){
		_delay_ms(10);
		SPDR = 0x19;
		PORTD = SPDR;
		a=0;
	}
	
}