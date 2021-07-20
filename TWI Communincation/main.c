#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void){
	
	DDRB  = 0b00000000;
	DDRC  = 0xFF;
	DDRA = 1<<PINA0;
	PORTA = 0<<PINA0;
	PORTC = 0x00;
	int pressed=0;
	
	
	
    while (1) {
		
				
		if(PINB == 0b00000000){                         //check if switched is pressed
			if(pressed == 0){                     
				pressed=1;
				PORTA ^= (1<<PINA0);
				
				
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTA;		/*START*/
				while(!(TWCR & 1<<TWINT)){
					;	}			                 /* Wait for TWINT flag to be raised*/
				while(!(TWSR == 0b00001000)){
					;  }                              /*Check Status register for start condition*/
				TWDR = 0b10010010;						/*Write address of slave and write command*/ 
				TWCR = 1<<TWINT | 1<<TWEN;   			/*Start sending address by clearing TWINT Flag*/ 
					    
					    
				while(!(TWCR & 1<<TWINT)){
					;        }                   		/* Wait for TWINT flag to be set*/ 
				while(!(TWSR == 0b00011000)){
					;        }
				TWDR = 0b00100111;				/*Write data in data register*/
				TWCR = 1<<TWINT | 1<<TWEN;			/*Clear TWINT Flag and data is sent*/
						 
				while(!(TWCR & 1<<TWINT)){
					;        }                      		/*wait for TWINT flag to be set*/
				while(!(TWSR == 0x28)){
					;         } 
				TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTO;     /*Stop command sent*/
					  
				
				
				TWCR = 1<<TWINT | 1<<TWSTA | 1<<TWEN;        /*START*/
				while(!(TWCR & 1<<TWINT))
					;
				while(!(TWSR == 0x08))
					;
				TWDR = 0b10010011;                         //Write address of slave and read command in TWDR
				TWCR = 1<<TWINT | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))                  //Wait for Twint Flag to be set
					;
				while(!(TWSR == 0x40))					   //Check Status register
					;        		
			    TWCR = 1<<TWINT | 1<<TWEA | 1<<TWEN;
				while(!(TWCR & 1<<TWINT))
					;
				PORTC = TWDR ^ 0xFF;						//read the received data
				while(!(TWSR == 0x50 || TWSR == 0x58))
					;
				
				TWCR = 1<<TWINT | 1<<TWSTO | 1<<TWEN;       //Stop condition
					    	  
			}
		}
		else
			pressed = 0;
		}
}
