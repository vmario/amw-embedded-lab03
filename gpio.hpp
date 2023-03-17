/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Zarządzanie GPIO.
 */

#pragma once

/**
 * Numery pinów powiązane z LED-ami.
 */
enum PIN_LED {
	PIN_LED_FULL_BRIGHT = 2,
	PIN_LED_PWM = 3,
};

/**
 * Port LED-ów.
 */
#define DDR_LED DDRB

/**
 * Inicjalizuje porty GPIO.
 */
void gpioInitialize();