/**
 * Author: https://github.com/Loris1123
 * Created: 2015-05-28
 * Description: Main file of the Propeller LED Display.
 */


#include <avr/io.h>

int main(void) {

    DDRD = (1 << PD5); // Set Pin5 of PortD as Output (LED)

    while(1){
        PORTD = (1 << PD5);  // Enable LED
    }
    return 0;
}