/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Implementacja sterowania PWM.
 */

#include "pwm.hpp"

#include <avr/interrupt.h>

/**
 * Konfiguracja Timer/Counter0 w trybie Fast PWM.
 */
static constexpr uint8_t TIMER0_FAST_PWM = _BV(WGM01) | _BV(WGM00);

/**
 * Taktowanie Timer/Counter0 zegarem podzielonym przez 1024.
 */
static constexpr uint8_t TIMER0_PRESCALER_1024 = _BV(CS02) | _BV(CS00);

#if defined __AVR_ATmega32A__
/**
 * Konfiguracja OC0 w trybie odwróconym.
 * 
 * Używamy zanegowanego wyjścia ze względu na sterowanie LED-em za pomocą 0.
 */
static constexpr uint8_t TIMER0_INVERTING_MODE = _BV(COM01) | _BV(COM00);
#elif defined __AVR_ATmega1284P__
/**
 * Konfiguracja OC0A w trybie odwróconym.
 * 
 * Używamy zanegowanego wyjścia ze względu na sterowanie LED-em za pomocą 0.
 */
static constexpr uint8_t TIMER0_INVERTING_MODE = _BV(COM0A1) | _BV(COM0A0);
#else
#error Niezdefiniowany typ mikrokontrolera.
#endif

/**
 * Obsługa przerwania TIMER0_OVF.
 */
ISR(TIMER0_OVF_vect)
{
}

void pwmInitialize()
{
#if defined __AVR_ATmega32A__
	TCCR0 = TIMER0_FAST_PWM | TIMER0_INVERTING_MODE | TIMER0_PRESCALER_1024;
	OCR0 = 1;
#elif defined __AVR_ATmega1284P__
	TCCR0A = TIMER0_FAST_PWM | TIMER0_INVERTING_MODE;
	TCCR0B = TIMER0_PRESCALER_1024;
	OCR0A = 1;
#else
#error Niezdefiniowany typ mikrokontrolera.
#endif
}