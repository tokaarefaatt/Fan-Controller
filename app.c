#include "adc.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "lcd.h"

void Fan_Controller(void)
{
	if(LM35_getTemperature() < 30)
	{
		DcMotor_Rotate(STOP, 0);
		LCD_displayStringRowColumn(0,3,"Fan is OFF");
		LCD_displayStringRowColumn(1,3,"Temp = ");
		LCD_intgerToString(LM35_getTemperature());
		LCD_displayString(" ");
	}
	else if((LM35_getTemperature() >= 30) && (LM35_getTemperature() < 60))
	{
		DcMotor_Rotate(CW, 25);
		LCD_displayStringRowColumn(0,3,"Fan is ON ");
		LCD_displayStringRowColumn(1,3,"Temp = ");
		LCD_intgerToString(LM35_getTemperature());
		LCD_displayString(" ");
	}
	else if((LM35_getTemperature() >= 60) && (LM35_getTemperature() < 90))
	{
		DcMotor_Rotate(CW, 50);
		LCD_displayStringRowColumn(0,3,"Fan is ON ");
		LCD_displayStringRowColumn(1,3,"Temp = ");
		LCD_intgerToString(LM35_getTemperature());
		LCD_displayString(" ");
	}
	else if((LM35_getTemperature() >= 90) && (LM35_getTemperature() < 120))
	{
		DcMotor_Rotate(CW, 75);
		LCD_displayStringRowColumn(0,3,"Fan is ON ");
		LCD_displayStringRowColumn(1,3,"Temp = ");
		LCD_intgerToString(LM35_getTemperature());
		LCD_displayString(" ");
	}
	else if(LM35_getTemperature() >= 120)
	{
		DcMotor_Rotate(CW, 100);
		LCD_displayStringRowColumn(0,3,"Fan is ON ");
		LCD_displayStringRowColumn(1,3,"Temp = ");
		LCD_intgerToString(LM35_getTemperature());
		LCD_displayString(" ");
	}
}
int main (void)
{
	/* Configuring the ADC*/
	ADC_ConfigType adc_config = {INTERNAL_VOLTAGE, DIV_FACTOR_8};
	ADC_init(&adc_config);

	/* Initializing the LCD */
	LCD_init();

	/* Initializing the DC Motor */
	DcMotor_Init();

	while (1)
	{
		Fan_Controller();
	}
}
