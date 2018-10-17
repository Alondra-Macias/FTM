/*
 * Switches.h
 *
 *  Created on: Sep 24, 2018
 *      Author: marga
 */

#ifndef SWITCHES_H_
#define SWITCHES_H_

#include "GPIO.h"
#include "NVIC.h"

/*Value used to manipulate corresponding pin for SW3 on port C*/
#define SW3_PORT_CONFIG 0x00000010
/*Value used to manipulate corresponding pin for SW2 on port A*/
#define SW2_PORT_PORT 0x00000040



#define SW2_port GPIO_C
#define SW3_port GPIO_A
/*Constant that represent the pin number for SW2*/
#define SW2_PIN 6
/*Constant that represent the pin number for SW2*3*/
#define SW3_PIN 4
/*! These constants are used to select between SW2 and SW3*/

#define BTN0_PIN 2
#define BTN1_PIN 3
#define BTN2_PIN 10
#define BTN3_PIN 11
#define BTN4_PIN 18
#define BTN5_PIN 19


#define BTN0_MASK 0XFFFFFFFD
#define BTN1_MASK 0XFFFFFFFB
#define BTN2_MASK 0XFFFFFBFF
#define BTN3_MASK 0XFFFFF7FF
#define BTN4_MASK 0XFFFBFFFF
#define BTN5_MASK 0XFFF7FFFF

#define BUTTONS_PORT GPIO_B

typedef enum{SW2,
			SW3
}SWITCH_name;

typedef enum
{
	BTN0,
	BTN1,
	BTN2,
	BTN3,
	BTN4,
	BTN5
}button_name_t;


/*!
 \brief
 	 	 This function configures both switches as GPIO inputs and enables them to interrupt on falling edge
 	 \return void
 */
void SW_setup(void);

/*!
 \brief
 	 	 Getter function of SW2 interruption flag
 	 \return uint8_t
 */
uint8_t sw2_get_intr_flag(void);


/*!
 \brief
 	 	 Getter function of SW3 interruption flag
 	 \return uint8_t
 */
uint8_t sw3_get_intr_flag(void);

/*!
 \brief
 	 	 Getter function of SW2 interruption flag
 	 \return void
 */
void sw2_clear_intr_flag(void);


/*!
 \brief
 	 	 Getter function of SW3 interruption flag
 	 \return void
 */
void sw3_clear_intr_flag(void);
/*!
 \brief
 	 	This function configures the priority of the interruption of sw2
 	 \return void
 */

void sw2_enable_interrupt(void);
/*!
 \brief
 	 	This function configures the priority of the interruption of sw3
 	 \return void
 */
void sw3_enable_interrupt(void);

button_name_t btn_get_pressed(void);


#endif /* SWITCHES_H_ */
