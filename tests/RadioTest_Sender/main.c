#include <avr/io.h>

int main() {

    DDRD = (1 << PD5); // Set Pin5 of PortD as Output (LED)

    while(1){
        PORTD = (1 << PD5);  // Enable LED
    }
    return 0;
}