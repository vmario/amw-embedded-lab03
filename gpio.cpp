/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Implementacja zarządzania GPIO.
 */

#include "gpio.hpp"

void gpioInitialize()
{
	DDR_LED = _BV(PIN_LED_FULL_BRIGHT) | _BV(PIN_LED_PWM);
}
