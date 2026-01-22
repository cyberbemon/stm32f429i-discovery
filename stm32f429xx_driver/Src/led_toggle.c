/*
 * led_toggle.c
 *
 *  Created on: 2 Dec 2025
 *      Author: johny
 */

#include <stdint.h>
#include "stm32f429xx.h"
#include "stm32f429xx_gpio_driver.h"

void delay(void)
{
	for (uint32_t i =0; i <500000; i++);
}

/* simple test application to see if we can toggle the leds
 * */
int main(void) {
	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOG;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;


	GPIO_PeriClockControl(GPIOG, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_13);
		delay();
	}

	return 0;
}
