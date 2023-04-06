/***********************************************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Toka Refaat
 *
 ***********************************************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/************************************************************************************************************
 *                                               Definitions                                               *
 ***********************************************************************************************************/
#define MAX_ADC_BITS                          1023
#define ADC_REF_VOLTAGE_VALUE                 2.56

/************************************************************************************************************
 *                                            Types Declaration                                            *
 ***********************************************************************************************************/
/*enum for the reference voltage*/
typedef enum{
	AREF, AVCC, Reserved, INTERNAL_VOLTAGE
}ADC_ReferenceVolatge;

/*enum for the division factor i.e. ADC Prescalar Select Bits*/
typedef enum{
	DIV_FACTOR_2,
	DIV_FACTOR_2_,
	DIV_FACTOR_4,
	DIV_FACTOR_8,
	DIV_FACTOR_16,
	DIV_FACTOR_32,
	DIV_FACTOR_64,
	DIV_FACTOR_128
}ADC_Prescaler;

/*a pointer to the configuration structure with type ADC_ConfigType.*/
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/************************************************************************************************************
 *                                           Functions Prototypes                                          *
 ***********************************************************************************************************/
/*
 * Description :
 * Initialize the ADC Driver
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /*ADC_H_*/
