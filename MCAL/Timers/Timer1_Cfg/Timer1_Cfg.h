/*
 * Timer1_Cfg.h
 *
 * Created: 21-Sep-18 06:08:55 PM
 *  Author: Mo_Ali
 */ 

#include "../Timer1_Src/Timer1.h"

typedef void (*P2FvoidTyp) (void) ;

#ifndef _TIMER1_CFG_H_
#define _TIMER1_CFG_H_

typedef struct
{
	const uint8 Pre_Scalar;
	const uint8 WaveGenMode;
	const uint8 COMMode ;
	P2FvoidTyp OC_Han ;
	P2FvoidTyp OF_Han ;
	
} Timer1_CfgTyp ;



#endif /* TIMER1_CFG_H_ */