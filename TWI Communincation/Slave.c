#include <avr/io.h>
#define F_CPU 8000000UL


int main(void){
	
	DDRE = 0xFF;
	PORTE = 0x00;
	TWDR = 0x00;
	TWAR = 0b10010010;
	TWDR = 0x00;
	
    while (1){
		
		TWCR = 1<<TWEN | 1<<TWEA;                 //Start TWI on slave
		while(!(TWCR & 1<<TWINT))                 //Wait for Twint flag
			;
		
		while(!(TWSR == 0b01100000))              //Check Status register
			; 
		
		TWCR = 1<<TWEA | 1<<TWINT | 1<<TWEN;	  //Clear twint flag  
		
		
		while(!(TWCR & 1<<TWINT))				  //Wait for Twint flag to be set
			;
		PORTE ^= TWDR;	                          //Read receive data
		while(!(TWSR == 0x80))
			;
		TWCR = 	1<<TWINT | 1<<TWEA | 1<<TWEN;
		while(!(TWSR == 0xA0))
			;	
		TWCR = 	1<<TWINT | 1<<TWEA | 1<<TWEN;
		
		
		while(!(TWCR & 1<<TWINT))
			;
		while(!(TWSR == 0xA8))                     //check status register
			;
		
		TWDR = PORTE;                              //Write the data to be sent in TWDR 
		TWCR = 1<<TWINT | 1<<TWEN;
		while(!(TWCR & 1<<TWINT))
			;
		while(!(TWSR == 0xC0 || TWSR == 0xC8))
			;
		TWCR = 	1<<TWINT | 1<<TWEA | 1<<TWEN;
		
    }   
	
	 

}

