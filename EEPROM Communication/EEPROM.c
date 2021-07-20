#include <avr/io.h>
#define F_CPU 8000000UL

int main(void){
	
	DDRA = 0x07;
	DDRC = 0xFF;
	DDRF = 0xFF;
	DDRE = 0xFF;
	PORTA = 0x00;
	DDRB = 0x00;
	int pressed_0 = 0;
	int pressed_1 = 0;
	int pressed_2 = 0;
	
 
    while (1) {
		
		if(!(PINB & 1<<PINB0)){
			if(pressed_0 == 0){
				pressed_0 = 1;
				PORTA = 0<<PINA2 | 1<<PINA0;
				
				
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTA;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x08))
					;
					
				TWDR = 0b10100010;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					; 
				while(!(TWSR == 0x18))
				    ;
				
				TWDR = 0x11;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x28))
					;
				 
				TWDR = 0x01;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x28))
					;
			
				TWDR = 0x08;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x28))
					;
		       
				TWDR = 0x04;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x28))
					;
				
				TWDR = 0x07;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x28))
					;
				
				
					
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTO;
			}
		}
		
		else
			pressed_0 = 0;
		
		
		
		if(!(PINB & 1<<PINB2)){
			if(pressed_2 == 0){
				pressed_2 = 1;
				PORTA = 0<<PINA0 | 1<<PINA2;
				
				
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTA;
				while(!(TWCR & 1<<TWINT))
				;
				while(!(TWSR == 0x08))
				;
				
				TWDR = 0b10100010;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
				;
				while(!(TWSR == 0x18))
				;
				
				TWDR = 0x11;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
				;
				while(!(TWSR == 0x28))
				;
				
				TWDR = 0x01;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
				;
				while(!(TWSR == 0x28))
				;
				
				TWDR = 0x00;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
				;
				while(!(TWSR == 0x28))
				;
				
				TWDR = 0x00;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
				;
				while(!(TWSR == 0x28))
				;
				
				TWDR = 0x02;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
				;
				while(!(TWSR == 0x28))
				;
				
				
				
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTO;
			}
		}
		
		else
		pressed_2 = 0;
		
		
		
		
		if(!(PINB & 1<<PINB1)){
			if(pressed_1 == 0){
				pressed_1 = 1;
				PORTA ^= 1<<PINA1;
				
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTA;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x08))
					;
				TWDR = 0b10100010;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x18))
					;
				
				TWDR = 0x11;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x28))
					;
				
				TWDR = 0x01;
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x28))
					;
				
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTA;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x10))
					;
				
				TWDR = 0b10100011;
				TWCR = 1<<TWINT | 1<<TWEN ;
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x40))
					;
				
				TWCR = 1<<TWINT | 1<<TWEA | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				PORTC = TWDR;
				while(!(TWSR == 0x50))
					;
					
				TWCR = 1<<TWINT | 1<<TWEA | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				PORTF = TWDR;
				while(!(TWSR == 0x50))
					;
				
				TWCR = 1<<TWINT | 0<<TWEA | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				PORTE = TWDR;
				while(!(TWSR == 0x58))
					;
				
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTO;	
				
					
			}
		}
		
		else
			pressed_1 = 0;
		
    }
}

