/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-08
 * Description: Main file for the rx-Test. Data will be transmitted from a Raspberry Pi to Arduino via cable
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>

#define BAUD 9600

void USART_init(void){

    // Set baud
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;
    #if USE_2X
        UCSR0A |= (1 << U2X0);
    #else
        UCSR0A &= ~(1 << U2X0);
    #endif

    // Enable UART Receive and Receivecomplete Interrupt
    UCSR0B = (1<<RXEN0) | (1 << RXCIE0);

    // Set frameformat to 8 Data and 1 Stopbit
    UCSR0C = ((1<<UCSZ00)|(1<<UCSZ01));

}

void rx_to_led(int rx){
    int b = rx >> 2;
    int d = (rx & 3) << 6;

    PORTB = b;
    PORTD = d;
}

int main(void) {

    DDRB = (1 << PB0) | (1 << PB1) |(1 << PB2) |(1 << PB3) |(1 << PB4) | (1 << PB5);
    DDRD = (1 << PD6) | (1 << PD7);

    sei();      // Enable global interrupts
    USART_init();

    while (1){

    }
    return 0;
}

ISR(USART_RX_vect){
    int next_sign  = UDR0;
    rx_to_led(next_sign);
}