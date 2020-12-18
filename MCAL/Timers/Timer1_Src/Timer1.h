/*
 * Timer1.h
 *
 * Created: 21-Sep-18 06:09:37 PM
 *  Author: alkab
 */ 


#ifndef _TIMER1_H_
#define _TIMER1_H_

#include <avr/interrupt.h>
#include "../../../Std_Headers/Controller.h"
#include "../../../Std_Headers/Std_Types.h"
#include "../../../Std_Headers/Std_Macros.h"
#include "../../../Std_Headers/Amit_Kit.h"
#include "../../../MCAL/Dio/Dio_Src/Dio.h"
#include "../Timer1_Cfg/Timer1_Cfg.h"


void Timer1_Init() ;
void Timer1_Val (uint16 Val) ;
uint8 Check_Timer1_Val() ;
void Timer1_Comp (uint16 Val);

ISR(TIMER1_COMP_vect);
ISR(TIMER1_OVF_vect);

typedef enum {Timer1 , NUM_OF_TIMERSS} Timer1_IdTyp;




#endif /* TIMER1_H_ */