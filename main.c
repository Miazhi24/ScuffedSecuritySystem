#include <avr/io.h>

#define F_CPU 16000000
#define BLINK_DELAY_MS 5000

#include <util/delay.h>

int main(void){
    DDRB |= 0B100000;
    while(1){
        PORTB |= 0B100000;
        _delay_ms(BLINK_DELAY_MS);
        PORTB &= ~ 0B100000;
        _delay_ms(BLINK_DELAY_MS);
    }
}