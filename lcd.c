#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
//#define F_CPU 16000000  //16 MHz
#include <util/delay.h>

#include "util.h"
#include "lcd_parallel.h"

void bike_screen(){
	LCDGotoXY(0,0);
	LCDWriteString("Speed:");

	LCDGotoXY(0,1);
	LCDWriteString("Dist:");

	LCDGotoXY(0,2);
	LCDWriteString("Batt:");

	LCDGotoXY(0,3);
	LCDWriteString("Power:");

}

//Update speed at position on screen
void update_speed(uint16_t speed){
	static char msg[20];
	sprintf(msg, "%x msg", speed);
	LCDGotoXY(6,0);
	LCDWriteString(msg);

}

//update total distance
void update_dist(int dist){
	LCDGotoXY(6,1);
	LCDWriteInt(dist,-1);
	LCDWriteString(" mi");

}

//Update battery info
void update_batt(int batt){
	LCDGotoXY(6,2);
	LCDWriteInt(batt,-1);
	LCDWriteString(" V");

}

//Update power draw
void update_pow(int power){
	LCDGotoXY(6,3);
	LCDWriteInt(power,-1);
	LCDWriteString(" W");

}







