/*
 * main.c
 *
 *  Created on: 26 Sep 2023
 *      Author: Rashad
 */


#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/7-Segment/SEVEN_SEGMENT_Interface.h"
#include "avr/delay.h"


void StartProgram			 (void);


void main ()
{

	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);
	LCD_voidInit();
	StartProgram();
	_delay_ms(400);
	LCD_voidClearDisplay();
	SEGMENT_voidInitSegmentPort(DIO_PORTA);
	while (1)
	{
		for(s8 i=9;i>=0;i--)
		{

			LCD_voidWriteString("STOP ");
			LCD_voidGoTo_XY(1,0);
			LCD_voidWriteString("Remaining ");
			LCD_voidWrite_u32Number(i);
			LCD_voidWriteString(" Sec ");
			SEGMENT_voidPrintNumber(DIO_PORTA,COMMON_CATHODE,i);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);
			_delay_ms(1000);
			if(i== 0)
			{
				LCD_voidClearDisplay();
			}
		}
		for(s8 i=5;i>=0;i--)
		{

			LCD_voidWriteString("Ready    ");
			LCD_voidGoTo_XY(1,0);
			LCD_voidWriteString("Remaining ");
			LCD_voidWrite_u32Number(i);
			LCD_voidWriteString(" Sec ");
			SEGMENT_voidPrintNumber(DIO_PORTA,COMMON_CATHODE,i);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);
			_delay_ms(1000);
			if(i== 0)
			{
				LCD_voidClearDisplay();
			}

		}
		for(s8 i=6;i>=0;i--)
		{

			LCD_voidWriteString("Go    ");
			LCD_voidGoTo_XY(1,0);
			LCD_voidWriteString("Remaining ");
			LCD_voidWrite_u32Number(i);
			LCD_voidWriteString(" Sec ");
			SEGMENT_voidPrintNumber(DIO_PORTA,COMMON_CATHODE,i);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_LOW);
			_delay_ms(1000);

			if(i== 0)
			{
				LCD_voidClearDisplay();
			}
		}



	}

}
/*                      Welcome Massage                       */
void StartProgram (void)
{
	LCD_voidClearDisplay();
	LCD_voidGoTo_XY (0,1);
	LCD_voidWriteString (" Welcome To MY");
	LCD_voidGoTo_XY (1,0);
	LCD_voidWriteString (" Traffic System  ");
}



