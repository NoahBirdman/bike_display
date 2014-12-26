/*
* New LCD Test
*
*NEWHAVEN Display 
*NHD-0420DZW-AY5
*
*LCD can connect via serial or parallel. This particular progam
*uses serial at a 9600 baud rate. This can be increased later
*This LCD has an HD44780A00 driver.
*
*
* Author: Noah Bergman
*   Date: 6/29/2014
*
*/
Another Commit at Line  16
//Frequency defined as 16Mhz in makefile
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <string.h>
//#define F_CPU 16000000
#include <util/delay.h>

one more at 25
//Util.c and Util.h are found /Documents/projects/AVR/support_files/
#include "util.h"

#include "lcd_parallel.h"
//#include "../support_files/custom_char.h"
#include "myutils.h"
#include "lcd.c"

volatile uint16_t timer_val =0;

ISR(TIMER1_CAPT_vect ){
	timer_val = 0;
	timer_val = (ICR1L & 0x00FF);
	timer_val |= (ICR1H << 8);

	PORTC ^= (0x01 <<PC5);
}

 int main(){

 	int speed =20;
 	uint16_t distance =0x0F;
 	int charge =22;
 	int power =23;
 	DDRC &= (0x01 << PC5);
 	PORTC =(0x01 << PC5);
 	config_ICP();
 	sei();

	LCDInit(0);
	LCDClear();
	_delay_ms(1);
	bike_screen();
	
	
	 while(1){
		update_speed(timer_val);
		update_dist(distance);
		update_batt(charge);
		update_pow(power);

		_delay_ms(100);
	}

return 0;
}
 
 
