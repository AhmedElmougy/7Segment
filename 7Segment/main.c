/*
 * File        : main.c
 * Description : This file include main application program, it display a count from 00 to 99 on 2 7-segments 
 *               and display LED animation on string of 8 LEDs 
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 23/6/2019
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "MDIO_Interface.h"
#include "HLED_Interface.h"
#include "H7SEG_Interface.h"


int main(void)
{
	
	/*==========================================
	 * Initialization
	 *==========================================*/
	/*Initialize first 7Seg at PORTA*/
	H7SEG_u8Init(MDIO_PORTB);
	/*Initialize second 7Seg at PORTB*/
	H7SEG_u8Init(MDIO_PORTC);
	/*Initialize Led string*/
	HLED_u8InitLedString(MDIO_PORTA);
	
	/*==========================================
	 * Variables
	 *==========================================*/
	/*count stores first 7-segment value*/
	u8 count = 0;
	/*count_10 stores second 7-segment value*/
	u8 count_10 = 0;
	
	/*initialize 7-segments values with zeros*/
	H7SEG_u8DisplayNumber(MDIO_PORTB,count);
	H7SEG_u8DisplayNumber(MDIO_PORTC,count_10);
	
	/*infinite loop*/
	while (1) 
    {
		
		/*4 loops to cover all 8 LEDs*/
		for (u8 i=0;i<4;i++)
		{
			/*set LED string value*/
			HLED_u8LedStringOnOff(MDIO_PORTA,( (129>>i) | (129<<i) ) );
			/*wait 0.25 sec*/
			_delay_ms(250);
			
		}/*end of for*/
		
		
		/*increment first 7-segment value*/
		count++;
		
		/*when first 7-segment value reaches 10*/
		if (count == 10)
		{
			/*make first 7-segment value equal 0*/
			count = 0;
			/*increment second 7-segment value*/
			count_10++;
			
		}/*end of if*/
			
		/*when second 7-segment reaches 10*/
		if (count_10 == 10)
		{
			/*make first 7-segment value equal 0*/
			count = 0;
			/*make first 7-segment value equal 0*/
			count_10 = 0;
		}/*end of if*/
		
		/*display 7-segments values*/
		H7SEG_u8DisplayNumber(MDIO_PORTB,count);
		H7SEG_u8DisplayNumber(MDIO_PORTC,count_10);
		
	}/*end of infinite loop*/
	
}/*end of main()*/

