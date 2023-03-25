/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Pętla główna.
 */

#include "gpio.hpp"
#include "pwm.hpp"

#include <stdlib.h>

/**
 * Funkcja główna.
 */
int main()
{
	gpioInitialize();
	pwmInitialize();

	while (true) {
	}

	return EXIT_SUCCESS;
}