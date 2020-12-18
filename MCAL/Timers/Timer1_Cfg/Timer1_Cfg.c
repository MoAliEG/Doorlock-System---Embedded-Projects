/*
 * Timer1_Cfg.c
 *
 * Created: 21-Sep-18 06:08:37 PM
 *  Author: alkab
 */ 

#include "Timer1_Cfg.h"
extern void DO_NOTHING();
Timer1_CfgTyp Timer1_CfgArr[NUM_OF_TIMERSS] =
{
	//Timer0
	{
		
		1, //CS00:2 Bit0:2
		4, //WGM00:01 Bit6,3
		0, //COM0:1 Bit4,5
		DO_NOTHING,
		DO_NOTHING
	}
	
};