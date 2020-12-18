

#include "Timer0_Cfg.h"

Timer0_CfgTyp Timer0_CfgArr[NUM_OF_TIMERS] = 
{
	//Timer0
	{
		
		5, //CS00:2 Bit0:2
		2, //WGM00:01 Bit6,3
		0, //COM0:1 Bit4,5 
		DO_NOTHING,
		DO_NOTHING
	}
		
};

void DO_NOTHING()
{
	;
}