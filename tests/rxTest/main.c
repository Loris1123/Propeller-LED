/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-08
 * Description: Main file for the rx-Test
 */


#include <avr/io.h>

int main(void) {

    DDRB = (1 << PB5); // Set Pin5 of PortD as Output (LED)
    while(1){
        PORTB = (1 << PB5);  // Enable LED
    }
    return 0;
}