/*  
 * Team Id: 4961 
 * Author List: Hiten Arya 
 * Filename: main.c 
 * Theme: Thirsty Crow 
 * Functions: magnet_pin_config() ,motor_pin_config(),magnet_on(),magnet_off(), forward(),backward(),left(), right(),stop(), main() 
 * Global Variables: NONE 
 */ 

#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void magnet_pin_config()
{
	DDRH = 0b11111111;
	PORTH =0b11111111;
}

void motor_pin_config()
{
	DDRA = 0x0F;
	PORTA = 0x00;
}

void magnet_on()
{
	PORTH = 0b11111111;
}

void magnet_off()
{
	PORTH = 0b00000000;
}

void forward()
{
	PORTA = 0x06;
}

void backward()
{
	PORTA = 0x09;
}

void left()
{
	PORTA =0x05 ;
}

void right()
{
	PORTA = 0x0A;
}

void soft_left()
{
	PORTA =0x04 ;
}

void soft_right()
{
	PORTA = 0x02;
}


void stop()
{
	PORTA =0x00 ;
}




int main(void)
{
	
	motor_pin_config();
	magnet_pin_config();
	while (1)
	{
		backward();
		_delay_ms(3000);
		stop();
		magnet_on();
		_delay_ms(3000);
		forward();
		_delay_ms(3000);
		magnet_off();
		stop();
		_delay_ms(3000);
	}
}

