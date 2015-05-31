/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-19
 * Description: Main file for the Propeller LED Display.
 */

#include <avr/io.h>
#include <stdint-gcc.h>
#include <avr/interrupt.h>
#include <util/delay.h>"
#include <util/setbaud.h>

#define mydelay 500

void letter_a(void);
void letter_b(void);
void letter_c(void);
void letter_d(void);
void letter_e(void);
void letter_f(void);
void letter_g(void);
void letter_h(void);
void letter_i(void);
void letter_j(void);
void letter_k(void);
void letter_l(void);
void letter_m(void);
void letter_n(void);
void letter_o(void);
void letter_p(void);
void letter_q(void);
void letter_r(void);
void letter_s(void);
void letter_t(void);
void letter_u(void);
void letter_v(void);
void letter_w(void);
void letter_x(void);
void letter_y(void);
void letter_z(void);



void setup(void){
    //Set Output
    DDRB = (1 << PB0) | (1 << PB1) |(1 << PB2) |(1 << PB3) |(1 << PB4) | (1 << PB5);
    DDRD = (1 << PD6) | (1 << PD7);

    // Interrupts
    sei();

    // Init UART
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

/*
 * Maps the input 8-Bit to 8 OutputLEDs
 */
void char_to_led(uint8_t rx){
    int b = rx >> 2;
    int d = (rx & 3) << 6;
    PORTB = b;
    PORTD = d;
}

int main(void){

    setup();

    while(1){

    }
    return 0;

}

ISR(USART_RX_vect){
    //char_to_led(UDR0);
    unsigned char letter = UDR0;
    if(letter == 'a' || letter == 'A') {
        letter_a();
    } else if(letter == 'b' || letter == 'B'){
        letter_b();
    }else{
        char_to_led(letter);
    }
}

// Methods for printing letters
void letter_a(void){
    char_to_led(0b01111110);
    _delay_ms(mydelay);
    char_to_led(0b00001001);
    _delay_ms(mydelay);
    char_to_led(0b00001001);
    _delay_ms(mydelay);
    char_to_led(0b00001001);
    _delay_ms(mydelay);
    char_to_led(0b01111110);
    _delay_ms(mydelay);
}

void letter_b(void){
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b00110110);
    _delay_ms(mydelay);
}