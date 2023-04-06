/***********************************************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Toka Refaat
 *
 ***********************************************************************************************************/
#include <avr/io.h>
#include "adc.h"
#include "common_macros.h"

/************************************************************************************************************
 *                                          Functions Definitions                                          *
 ***********************************************************************************************************/

/*
 * Description :
 * Initialize the ADC Driver
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	/* ADMUX Register Bits Description:
	 * REFS1:1, REFS0=1 to choose to connect Internal reference voltage by input 2.56V
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */

	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr -> ref_volt) <<6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (Config_Ptr -> prescaler);
}

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel
	 * Choose the correct channel by setting the channel number in MUX4:0 bits*/
	ADMUX = (ADMUX & 0xE0) | channel_num;

	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA, ADSC);

	/* Polling: Wait for conversion to complete, ADIF becomes '1' */
	while (BIT_IS_CLEAR(ADCSRA, ADIF));

	/* Clear ADIF by write '1' to it :) */
	SET_BIT(ADCSRA, ADIF);

	/* Read the digital value from the data register */
	return ADC;
}

