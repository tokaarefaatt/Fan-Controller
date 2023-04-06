/***********************************************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the AVR DC Motor driver
 *
 * Author: Toka Refaat
 *
 ***********************************************************************************************************/
#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "pwm.h"

/*
 * Description :
 * Initialize the DC Motor:
 * 1. Setup the DC Motor pins directions by use the GPIO driver.
 * 2.  Setup the DC Motor pins to Logic Low.
 */
void DcMotor_Init(void)
{
	/*Setting INPUT1 Pin of the DC Motor to output pin*/
	GPIO_setupPinDirection(DC_Motor_IN1_PORT_NUM , DC_Motor_IN1_PIN_NUM , PIN_OUTPUT);
	/*Setting INPUT1 Pin of the DC Motor to low*/
	GPIO_writePin(DC_Motor_IN1_PORT_NUM, DC_Motor_IN1_PIN_NUM, LOGIC_LOW);

	/*Setting INPUT2 Pin of the DC Motor to output pin*/
	GPIO_setupPinDirection(DC_Motor_IN2_PORT_NUM , DC_Motor_IN2_PIN_NUM , PIN_OUTPUT);
	/*Setting INPUT1 Pin of the DC Motor to low*/
	GPIO_writePin(DC_Motor_IN2_PORT_NUM, DC_Motor_IN2_PIN_NUM, LOGIC_LOW);
}

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor
 *    based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start(speed);

	switch (state)
	{
	case CW:
		GPIO_writePin(DC_Motor_IN1_PORT_NUM, DC_Motor_IN1_PIN_NUM, LOGIC_LOW);
		GPIO_writePin(DC_Motor_IN2_PORT_NUM, DC_Motor_IN2_PIN_NUM, LOGIC_HIGH);
		break;

	case CCW:
		GPIO_writePin(DC_Motor_IN1_PORT_NUM, DC_Motor_IN1_PIN_NUM, LOGIC_HIGH);
		GPIO_writePin(DC_Motor_IN2_PORT_NUM, DC_Motor_IN2_PIN_NUM, LOGIC_LOW);
		break;

	case STOP:
		GPIO_writePin(DC_Motor_IN1_PORT_NUM, DC_Motor_IN1_PIN_NUM, LOGIC_LOW);
		GPIO_writePin(DC_Motor_IN2_PORT_NUM, DC_Motor_IN2_PIN_NUM, LOGIC_LOW);
		break;
	}
}
