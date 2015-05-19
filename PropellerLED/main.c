/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-19
 * Description: Main file for the Propeller LED Display.
 */

#include <avr/io.h>

int main(void){
    DDRB = (1 << PB5);
    PORTB = (1 << PB5);
}