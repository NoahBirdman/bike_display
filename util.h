#ifndef UTIL_H
#define UTIL_H

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
//#define F_CPU 16000000  //16 MHz
#include <util/delay.h>
#include <string.h>
#include <stdint.h>
//Configure for 9600 baud rate
void usart_config(void);

//Send one character 
void usart_send(char theChar);

//Send string over usart :::Requires usart_send()
void usart_string(char* theString);

//Conigure ADC for ADC4 (PortC4) -- External AREF
void config_adc(void);

//Begin ADC Conversion
int adc_result(void);

//Initiallize TW0-Wire Serial for I2C
void config_TWI(void);

//TWI for the MCP3021 adc 
uint16_t TWI_MCP3021(void);

void delay_adj(int time_ms);

void config_ICP(void);
#endif
