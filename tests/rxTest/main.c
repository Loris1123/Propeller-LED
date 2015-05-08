/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-08
 * Description: Main file for the rx-Test
 */

#define BAUD_PRESCALER 0x0067  // 9600 baud

#include <avr/io.h>

void init_USART(void){
    // Set baudrate
    UBRR0 = BAUD_PRESCALER;
    // 8 data, 1 Stopbit
    UCSR0C = (0 << USBS0) | (1 << UCSZ01) | (1 << UCSZ00);
    // Enable Reciever. Disable transmitter, Enable receive complete interrupt
    UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (0 << TXEN0);
}

int main(void) {

    sei();
    DDRB = (1 << PB5); // Set Pin5 of PortD as Output (LED)
    init_USART();

    while(1){

    }
    return 0;
}

ISR(USART0_RX_vect){
    PORTB = (1 << PB5);  // Enable LED to notify something has been transmitted
}