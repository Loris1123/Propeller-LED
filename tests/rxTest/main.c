/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-08
 * Description: Main file for the rx-Test
 */


//Daten für Uart Kommunikation
//#define FOSC 16000000 // Clock Speed
//#define BAUD 9600
//#define MYUBRR FOSC/16/BAUD-1



#include <avr/io.h>
#include <avr/interrupt.h>

// Calculate Baudrate
#define BAUDRATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void USART_init(void){

    // Set baud
    UBRR0 = BAUD_PRESCALER;

    // Enable UART Receive and Receivecomplete Interrupt
    UCSR0B = (1<<RXEN0) | (1 << RXCIE0);

    // Set frameformat to 8 Data and 1 Stopbit
    UCSR0C = ((1<<UCSZ00)|(1<<UCSZ01));

}

int main(void) {
    sei();      // Enable global interrupts
    USART_init();

    DDRB = (1 << PB5); // Set Pin5 of PortD as Output (LED)

    while (1){

    }
    return 0;
}

ISR(USART_RX_vect){
    PORTB = (1 << PB5);  // Enable LED to notify something has been transmitted
}