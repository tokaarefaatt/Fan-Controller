/***********************************************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the AVR PWM driver
 *
 * Author: Toka Refaat
 *
 ***********************************************************************************************************/
#include "avr/io.h"
#include "pwm.h"
#include "gpio.h"
#include "common_macros.h"
/*
 * Description :
 * Triggering the Timer0 with PWM Mode:
 * 1. Setup the PWM mode with Non-Inverting.
 * 2. Setup the prescaler with F_CPU/8.
 * 3. Setup the compare value based on the required input duty cycle.
 * 4. Setup the direction for OC0 as output pin through the GPIO driver.
 * 5. The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; //Set Timer Initial value
	//OCR0  = duty_cycle; // Set Compare Value
	OCR0 = (uint8)(((uint16)(MAX_FOR_TIMER0_REGISTER*duty_cycle))/100);

	/*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/
	GPIO_setupPinDirection(TIMER0_PWM_PORT_NUM, TIMER0_PWM_PIN_NUM, PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
