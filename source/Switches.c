/**
	\file
	\brief
		This is the source file for the Switches Module.
		It contains all the implementation for configuration functions and runtime functions.
	\authors  Alondra Macias, Margarita Jauregui
	\date	30/09/2018
 */
#include "Switches.h"

static BooleanType sw2_intr_flag = FALSE;
static BooleanType sw3_intr_flag = FALSE;

/*
 \brief
 	 	 This function configures both switches as GPIO inputs and enables them to interrupt on falling edge
 	 \return void
 */
void SW_setup(void)
{
		/*Configuration to set switches and buttons as MUX-ALT1 (GPIO) with pull-up resistor enabled and interruption on falling edge*/
		gpio_pin_control_register_t sw_config = GPIO_MUX1 | GPIO_PE | GPIO_PS | INTR_FALLING_EDGE;

		/*Enables clock gating for the corresponding port for SW2*/
		GPIO_clock_gating(SW2_port);
		/*Enables clock gating for the corresponding port for SW3*/
		GPIO_clock_gating(SW3_port);
		/*Enables clock gating for the corresponding port for buttons*/
		GPIO_clock_gating(BUTTONS_PORT);
		/*Configures SW2 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(SW2_port, SW2_PIN, &sw_config);
		/*Configures SW3 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(SW3_port, SW3_PIN, &sw_config);
		/*Configures BTN0 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(BUTTONS_PORT, BTN0_PIN, &sw_config);
		/*Configures BTN1 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(BUTTONS_PORT, BTN1_PIN, &sw_config);
		/*Configures BTN2 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(BUTTONS_PORT, BTN2_PIN, &sw_config);
		/*Configures BTN3 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(BUTTONS_PORT, BTN3_PIN, &sw_config);
		/*Configures BTN4 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(BUTTONS_PORT, BTN4_PIN, &sw_config);
		/*Configures BTN5 as ALT1, with Pull up resistor enabled and intr falling edge */
		GPIO_pin_control_register(BUTTONS_PORT, BTN5_PIN, &sw_config);


		/*configures Sw2 as input*/
		GPIO_data_direction_pin(SW2_port, GPIO_INPUT, SW2_PIN);
		/*configures Sw3 as input*/
		GPIO_data_direction_pin(SW3_port, GPIO_INPUT, SW3_PIN);
		/*configures BTN0 as input*/
		GPIO_data_direction_pin(BUTTONS_PORT, GPIO_INPUT, BTN0_PIN);
		/*configures BTN1 as input*/
		GPIO_data_direction_pin(BUTTONS_PORT, GPIO_INPUT, BTN1_PIN);
		/*configures BTN2 as input*/
		GPIO_data_direction_pin(BUTTONS_PORT, GPIO_INPUT, BTN2_PIN);
		/*configures BTN3 as input*/
		GPIO_data_direction_pin(BUTTONS_PORT, GPIO_INPUT, BTN3_PIN);
		/*configures BTN4 as input*/
		GPIO_data_direction_pin(BUTTONS_PORT, GPIO_INPUT, BTN4_PIN);
		/*configures BTN5 as input*/
		GPIO_data_direction_pin(BUTTONS_PORT, GPIO_INPUT, BTN5_PIN);




		NVIC_setBASEPRI_threshold(PRIORITY_12);// se activen desde el nivel del 0 al 12
		/*Enables and sets a particular interrupt and its priority*/
		NVIC_enableInterruptAndPriotity(PORTC_IRQ,PRIORITY_5); //active y conf la prioridad del puerto c de nivel 5
		/*Enables and sets a particular interrupt and its priority*/
		NVIC_enableInterruptAndPriotity(PORTA_IRQ,PRIORITY_5); //mas importante que el 5
		/*Enables and sets a particular interrupt and its priority*/
		NVIC_enableInterruptAndPriotity(PORTB_IRQ,PRIORITY_7); //mas importante que el 5

		EnableInterrupts;

}



button_name_t btn_get_pressed(void)
{
	button_name_t btn_pressed;
	uint32_t data_read = GPIO_read_port(BUTTONS_PORT);
	switch (data_read)
	{
		case (BTN0_MASK):
			btn_pressed = BTN0;
			break;
		case (BTN1_MASK):
			btn_pressed = BTN1;
			break;
		case (BTN2_MASK):
			btn_pressed = BTN2;
			break;
		case (BTN3_MASK):
			btn_pressed = BTN3;
			break;
		case (BTN4_MASK):
			btn_pressed = BTN4;
			break;
		case (BTN5_MASK):
			btn_pressed = BTN5;
			break;
		default:
			break;
	}
	return btn_pressed;
}

uint8_t sw2_get_intr_flag(void)
{
	return sw2_intr_flag;
}

uint8_t sw3_get_intr_flag(void)
{
	return sw2_intr_flag;
}

void sw2_clear_intr_flag(void)
{
	sw2_intr_flag = FALSE;
}

void sw3_clear_intr_flag(void)
{
	sw3_intr_flag = FALSE;
}

void sw2_enable_interrupt(void)
{
	NVIC_enableInterruptAndPriotity(PORTC_IRQ, PRIORITY_5);
}

void sw3_enable_interrupt(void)
{
	NVIC_enableInterruptAndPriotity(PORTA_IRQ, PRIORITY_5);
}


