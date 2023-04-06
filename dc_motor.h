 /***********************************************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the AVR DC Motor driver
 *
 * Author: Toka Refaat
 *
 ***********************************************************************************************************/
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/************************************************************************************************************
 *                                               Definitions                                               *
 ***********************************************************************************************************/
#define DC_Motor_IN1_PORT_NUM                  PORTB_ID
#define DC_Motor_IN1_PIN_NUM                   PIN0_ID

#define DC_Motor_IN2_PORT_NUM                  PORTB_ID
#define DC_Motor_IN2_PIN_NUM                   PIN1_ID

/************************************************************************************************************
 *                                            Types Declaration                                            *
 ***********************************************************************************************************/
typedef enum
{
	CW,CCW,STOP
}DcMotor_State;

/************************************************************************************************************
 *                                           Functions Prototypes                                          *
 ***********************************************************************************************************/
/*
 * Description :
 * Initialize the DC Motor:
 * 1. Setup the DC Motor pins directions by use the GPIO driver.
 * 2.  Setup the DC Motor pins to Logic Low.
 */
void DcMotor_Init(void);

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor
 *    based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /*DC_MOTOR_H_*/
