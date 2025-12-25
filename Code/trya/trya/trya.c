/*  
 * Team Id: 4961 
 * Author List: Hiten Arya 
 * Filename: trya.c 
 * Theme: Thirsty Crow 
 * Functions: uart0_init() , uart_tx(char) , uart_rx(), send_str(char data[100]),  main() 
 * Global Variables: data
 */ 
#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define COMMAND_HELLO 0x01

#define RX  (1<<4)
#define TX  (1<<3)
#define TE  (1<<5)
#define RE  (1<<7)

volatile unsigned char data;
//unsigned int recieve; 

void uart0_init()
{
	UCSR0B = 0x00;							//disable while setting baud rate
	UCSR0A = 0x00;
	UCSR0C = 0x06;
	UBRR0L = 0x5F; 							//9600BPS at 14745600Hz
	UBRR0H = 0x00;
	UCSR0B = 0x98;
	//UCSR0C = 3<<1;							//setting 8-bit character and 1 stop bit
	//UCSR0B = RX | TX;
}


void uart_tx(char data)
{
	while(!(UCSR0A & TE));						//waiting to transmit
	UDR0 = data;
}

ISR(USART0_RX_vect)
{
	data = UDR0;
	//recieve=1;
}

char uart_rx()
{
	while(!(UCSR0A & RE));						//waiting to receive
	return UDR0;
}
/*  
 * Function Name: 
	send_str 
 * Input:  
	data[100] -> character array which contain string 
 * Output: 
	it sends each character of array to uart_tx function till null character
 * Logic: 
	Acess each character of string and send it to uart_tx using for loop
 * Example Call:  
	send_str("I received :"); 
 */ 
void send_str(char data[100])
{
	int i;
	for(i=0;data[i]!='\0';i++)
	{
		uart_tx(data[i]);
	}
}

int main(void)
{
    /* Replace with your application code */
	char command; 
	uart0_init();
    while (1) 
    {
	
			// command is receiving character which uart_rx is returning in it
			command=uart_rx();
			send_str("I received :");
			uart_tx(command);
							
		
    }
	return 0;
}
