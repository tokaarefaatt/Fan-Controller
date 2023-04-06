/***********************************************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Toka Refaat
 *
 ***********************************************************************************************************/
#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/************************************************************************************************************
 *                                               Definitions                                               *
 ***********************************************************************************************************/
/*Represent the max number for timer0 count*/
#define MAX_FOR_TIMER0_REGISTER             255

#define TIMER0_PWM_PORT_NUM                 PORTB_ID
#define TIMER0_PWM_PIN_NUM                  PIN3_ID

/************************************************************************************************************
 *                                           Functions Prototypes                                          *
 ***********************************************************************************************************/

/*
 * Description :
 * Triggering the Timer0 with PWM Mode:
 * 1. Setup the PWM mode with Non-Inverting.
 * 2. Setup the prescaler with F_CPU/8.
 * 3. Setup the compare value based on the required input duty cycle.
 * 4. Setup the direction for OC0 as output pin through the GPIO driver.
 * 5. The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /*PWM_H_*/

