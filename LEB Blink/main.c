/*
 * GccApplication1.c
 *
 * Created: 27-05-2021 22:38:24
 * Author : krnav
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>


int main(void){
	DDRB = 1<<0;       //set portB pin0 as output
	PORTB = 0<<0;      //set the value of pin0 low
	
    while (1){
		_delay_ms(500);
		PORTB = 1<<0;
		_delay_ms(500);
		PORTB = 0<<0;
		
    }
}

