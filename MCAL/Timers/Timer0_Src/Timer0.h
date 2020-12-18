/*
 * Timer0.h
 *
 * Created: 08-Aug-18 08:36:34 AM
 *  Author: Mohamed Ali
 */ 


#ifndef _TIMER0_H_
#define _TIMER0_H_

#include <avr/interrupt.h>
#include "../../../Std_Headers/Controller.h"
#include "../../../Std_Headers/Std_Types.h"
#include "../../../Std_Headers/Std_Macros.h"
#include "../../../Std_Headers/Amit_Kit.h"
#include "../../../MCAL/Dio/Dio_Src/Dio.h"
#include "../Timer0_Cfg/Timer0_Cfg.h"


void Timer0_Init() ;
void Timer0_Val (uint8 Val) ;
uint8 Check_Timer0_Val() ;
void Timer0_Comp (uint8 Val);

ISR(TIMER0_COMP_vect);
ISR(TIMER0_OVF_vect);

typedef enum {Timer0 , NUM_OF_TIMERS} Timer_IdTyp;



#endif 