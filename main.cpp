/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Pętla główna.
 */

#include "gpio.hpp"

#include <avr/interrupt.h>

#include <stdlib.h>

enum BRIGHTNESS {
	BRIGHTNESS_UP,
	BRIGHTNESS_DOWN,
};

/**
 * Inicjalizacja przerwań.
 */
void interruptsInitialize()
{
}

/**
 * Obsługa przerwania INT0.
 */
ISR(TIMER0_OVF_vect)
{
	static enum BRIGHTNESS brightness;
	
	if (brightness == BRIGHTNESS_UP) {
		OCR0++;
	} else {
		OCR0--;
	}

	if (OCR0 == 0xff) {
		brightness = BRIGHTNESS_DOWN;
	} else if (OCR0 == 0x00) {
		brightness = BRIGHTNESS_UP;
	}
}

/**
 * Pętla główna.
 */
void mainLoop()
{
}

/**
 * Funkcja główna.
 */
int main()
{
	gpioInitialize();
	interruptsInitialize();
	TCCR0 = _BV(WGM01) | _BV(WGM00) | _BV(CS02) | _BV(COM01) | _BV(COM00);
	//OCR0 = 1;
	TIMSK = _BV(TOIE0);
	sei();

	while (true) {
		mainLoop();
	}

	return EXIT_SUCCESS;
}