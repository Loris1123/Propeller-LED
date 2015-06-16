/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-19
 * Description: Main file for the Propeller LED Display.
 */

#include <avr/io.h>
#include <stdint-gcc.h>
#include <avr/interrupt.h>
#include <util/delay.h>
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
void char_to_led(uint8_t);

int text_length = 0;
char display_text[20];
char *p_display_text = display_text;

void setup(void){

    //Set Output
    DDRB = (1 << PB0) | (1 << PB6) | (1 << PB7);
    DDRD = (1 << PB3) | (1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PD7);

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

int main(void){

    setup();

    while(1){
        for(int i = 0; i<text_length; i++){
            switch(display_text[i]){
                case 'a':
                    letter_a();
                    break;
                case 'b':
                    letter_b();
                    break;
                case 'c':
                    letter_c();
                    break;
                case 'd':
                    letter_d();
                    break;
                case 'e':
                    letter_e();
                    break;
                case 'f':
                    letter_f();
                    break;
                case 'g':
                    letter_g();
                    break;
                case 'h':
                    letter_h();
                    break;
                case 'i':
                    letter_i();
                    break;
                case 'j':
                    letter_j();
                    break;
                case 'k':
                    letter_k();
                    break;
                case 'l':
                    letter_l();
                    break;
                case 'm':
                    letter_m();
                    break;
                case 'n':
                    letter_n();
                    break;
                case 'o':
                    letter_o();
                    break;
                case 'p':
                    letter_p();
                    break;
                case 'q':
                    letter_q();
                    break;
                case 'r':
                    letter_r();
                    break;
                case 's':
                    letter_s();
                    break;
                case 't':
                    letter_t();
                    break;
                case 'u':
                    letter_u();
                    break;
                case 'v':
                    letter_v();
                    break;
                case 'w':
                    letter_w();
                    break;
                case 'x':
                    letter_x();
                    break;
                case 'y':
                    letter_y();
                    break;
                case 'z':
                    letter_z();
                    break;
            }
        }
        char_to_led(0b11111111);
        _delay_ms(1000);
        char_to_led(0);
        _delay_ms(1000);
    }
    return 0;

}

ISR(USART_RX_vect){
    unsigned char letter = UDR0;
    *p_display_text = letter;
    p_display_text++;
    text_length++;
    //char_to_led(UDR0);
}

/*
 * Maps the input 8-Bit to 8 OutputLEDs
 */
void char_to_led(uint8_t rx){
    // LED Mapping:
    // 0: PB 0
    // 1: PD 7
    // 2: PD 6
    // 3: PD 5
    // 4: PB 7
    // 5: PB 6
    // 6: PD 4
    // 7: PD 3

    // Get the k'th bit of n. From Stackoverflow
    //(n & ( 1 << k )) >> k
    // Clear Ports
    PORTB = 0;
    PORTD = 0;

    // TODO: Set LEDs in one instruction
    // Each LED
    PORTB |= (((rx & ( 1 << 0 )) >> 0) << PB0);
    PORTD |= (((rx & ( 1 << 1 )) >> 1) << PD7);
    PORTD |= (((rx & ( 1 << 2 )) >> 2) << PD6);
    PORTD |= (((rx & ( 1 << 3 )) >> 3) << PD5);
    PORTB |= (((rx & ( 1 << 4 )) >> 4) << PB7);
    PORTB |= (((rx & ( 1 << 5 )) >> 5) << PB6);
    PORTD |= (((rx & ( 1 << 6 )) >> 6) << PD4);
    PORTD |= (((rx & ( 1 << 7 )) >> 7) << PD3);
}

// Methods for printing letters
void letter_a(void){
    char_to_led(0);
    _delay_ms(mydelay);
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
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_b(void){
    char_to_led(0);
    _delay_ms(mydelay);
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
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_c(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00111110);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b00100010);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_d(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b00111110);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_e(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_f(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00001001);
    _delay_ms(mydelay);
    char_to_led(0b00001001);
    _delay_ms(mydelay);
    char_to_led(0b00001001);
    _delay_ms(mydelay);
    char_to_led(0b00000001);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_g(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00111110);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01010001);
    _delay_ms(mydelay);
    char_to_led(0b00110010);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_h(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_i(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_j(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00110000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b00111111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_k(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b00010100);
    _delay_ms(mydelay);
    char_to_led(0b00100010);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_l(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_m(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00000010);
    _delay_ms(mydelay);
    char_to_led(0b00000100);
    _delay_ms(mydelay);
    char_to_led(0b00000010);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_n(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00000100);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b00010000);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_o(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00111110);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b00111110);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_p(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00010001);
    _delay_ms(mydelay);
    char_to_led(0b00010001);
    _delay_ms(mydelay);
    char_to_led(0b00010001);
    _delay_ms(mydelay);
    char_to_led(0b00001110);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_q(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00111110);
    _delay_ms(mydelay);
    char_to_led(0b01000001);
    _delay_ms(mydelay);
    char_to_led(0b01010001);
    _delay_ms(mydelay);
    char_to_led(0b01100001);
    _delay_ms(mydelay);
    char_to_led(0b01111110);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_r(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00010001);
    _delay_ms(mydelay);
    char_to_led(0b00010001);
    _delay_ms(mydelay);
    char_to_led(0b00010001);
    _delay_ms(mydelay);
    char_to_led(0b01101110);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_s(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00100110);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b00110010);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_t(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00000001);
    _delay_ms(mydelay);
    char_to_led(0b00000001);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00000001);
    _delay_ms(mydelay);
    char_to_led(0b00000001);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_u(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00111111);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b00111111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_v(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00011111);
    _delay_ms(mydelay);
    char_to_led(0b00100000);
    _delay_ms(mydelay);
    char_to_led(0b01000000);
    _delay_ms(mydelay);
    char_to_led(0b00100000);
    _delay_ms(mydelay);
    char_to_led(0b00011111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_w(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0b00100000);
    _delay_ms(mydelay);
    char_to_led(0b00010000);
    _delay_ms(mydelay);
    char_to_led(0b00100000);
    _delay_ms(mydelay);
    char_to_led(0b01111111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_x(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01100011);
    _delay_ms(mydelay);
    char_to_led(0b00010100);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b00010100);
    _delay_ms(mydelay);
    char_to_led(0b01100011);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_y(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b00000111);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b01110000);
    _delay_ms(mydelay);
    char_to_led(0b00001000);
    _delay_ms(mydelay);
    char_to_led(0b00000111);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}

void letter_z(void){
    char_to_led(0);
    _delay_ms(mydelay);
    char_to_led(0b01100001);
    _delay_ms(mydelay);
    char_to_led(0b01010001);
    _delay_ms(mydelay);
    char_to_led(0b01001001);
    _delay_ms(mydelay);
    char_to_led(0b01000101);
    _delay_ms(mydelay);
    char_to_led(0b01000011);
    _delay_ms(mydelay);
    char_to_led(0);
    _delay_ms(mydelay);
}




