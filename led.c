/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>


#define gpio_base 0x10012000
#define gpio_input_enable_offset 0x04
#define gpio_output_enable_offset 0x08
#define gpio_output_value_offset 0x0C
#define gpio_input_value_offset 0x00

#define RED_LED_PIN 19
#define BLUE_LED_PIN 21
#define GREEN_LED_PIN 22


int delay(int microseconds)
{
	for(int i=0;i<microseconds;i++)
	{}
}

int main (void)
{

	//int* led_gpio_base=(int*)gpio_base;
	//int* led_gpio_input_enable=(int*)(gpio_base + gpio_input_enable_offset);
	int* led_gpio_output_enable=(int*)(gpio_base + gpio_output_enable_offset);
	//int* led_gpio_input_value=(int*)(gpio_base + gpio_input_value_offset);
	int* led_gpio_output_value=(int*)(gpio_base + gpio_output_value_offset);

	int leds=(1<<RED_LED_PIN) | (1<<BLUE_LED_PIN);

	*led_gpio_output_enable = leds; //enable output

	*led_gpio_output_value = 0 ;
	int count=0;

	while(1)
	{
		*led_gpio_output_value |= leds;
		delay(2000000);

		*led_gpio_output_value &= ~leds;
		delay(2000000);

	}


	return 0;
}

