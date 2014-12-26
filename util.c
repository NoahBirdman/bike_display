#include "util.h"

/*
volatile char twi_rx;


//Look for TWI received
ISR (TWI_vect){
	TWBR |= (1<<TWIF);
//Start bit ACK
	
	twi_rx = TWDR;	

}
*/

//Adjustable delay_ms 
void delay_adj(int time_ms){
	for(int i = 0; i<time_ms; i++) _delay_ms(10);
}

 //Configure USART with 9600 baud rate
 void usart_config(){
 	//Actual Baud is 9615
 	
	UBRR0L = 103;
	UCSR0B |= (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	sei();
}

void usart_send(char theChar){

	while(!(UCSR0A&(1<<UDRE0)));
	
	UDR0 = theChar;
}

//Send String over usart. This calls usart_send
void usart_string(char* theString){
	for(int i=0; i<strlen(theString);i++){
		usart_send(theString[i]);
	}
}


void config_adc(){
//ADMUX
	//REFS1 REFS0 -- select refernce voltage
	//			--Default 00 for external AREF 01 for Vcc
	//MUX3:0 -- Channel selection for ADC
	//Channel 5 for now
//	PRR &+ ~(1<<PRADC);
//	DDRC &= ~(1<<DDC5);

//Ref = Vcc ADC4
// 	ADMUX |= (1<<REFS0)|(1<<MUX2); 

//Ref = AREF ADC4
	ADMUX |= (1<<MUX2);
	
//ADCSRA -- Control and Status Register
	//ADEN -- Enable ADC
	//ADSC -- Begin Conversion
	//ADATE -- Auto Trigger
	//ADIF -- ADC Interrupt Flag
	//ADIE -- ADC Interrupt Enable
	//ADPS2:0 -- Presaclar Bits  -- 011 divide by 8
	ADCSRA |= (1<<ADEN)|(1<<ADIE)|(1<<ADPS1)|(1<<ADPS0);

//ADCSRB -- Control and Stautus Register
	//Not Neeeded
	
}

//Iniitialize ADC for ADC4 (PortC 4)
int adc_result(){
	int result =0;
//Turn on ADC --Important after sleep mode
	PRR &= ~(1<<PRADC);
	ADCSRA |= (1<<ADSC);
	
	while((ADCSRA & (1<<ADSC)));
	
	result = (ADCL);
	result |= (ADCH<<8);

	return  result;
}

//Configures Two-Wire serial to mimic I2C

//Configures Input Capture for Timer 1. 
void config_ICP(){
//TCCR1A 
	//COM1A:B Select Port Operation -- 00 Normal Port Operation
	//WGM1:0 PWM Operation -- 00 Normal Port Operation
	TCCR1A |= (0x1<<WGM13)|(0x1<<WGM12);
//TCCR1B
	//ICNC1 Input Capture Noise Canceler -- 1 
	//ICES1 Edge Select -- 1 Rising Edge
	//WGM3:2 -- 00 See TCCR1A
	//CS2:0 Clock Select -- 101 clk / 1024;
	TCCR1B |= (1<<ICES1)|(1<<CS12)|(1<<CS10);
	
	//Write CS2:0 to 0 to stop ICP
	
//TCCR1C
	//FOC1A and B --Force output compare 

//TIMSK1
	//ICE1 Input Captue Interrupt Enable
	//TOIE1 Timer Overflow Interrupt Enable
	TIMSK1 |= (1<<ICIE1);
		
}

//calculate speed from Input Capture
int calc_speed(uint16_t timer_val){
	static double previous_val;
	static double average;
     average ++;
     previous_val ++;

}
//This function should be called after detecting 0x7E 
void usart_xbee_rx(){
	usart_send('a');
	
}



