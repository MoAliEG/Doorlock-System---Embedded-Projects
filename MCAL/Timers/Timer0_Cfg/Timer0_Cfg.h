

#ifndef _TIMER0CFG_H_
#define _TIMER0CFG_H_



#include "../Timer0_Src/Timer0.h"

typedef void (*P2FvoidTyp) (void) ;
void DO_NOTHING();
typedef struct 
{
	const uint8 Pre_Scalar;
	const uint8 WaveGenMode;
	const uint8 COMMode ;
	P2FvoidTyp OC_Han ;
	P2FvoidTyp OF_Han ;
	
	} Timer0_CfgTyp ;



#endif 