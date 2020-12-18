/*
 * Timer1.c
 *
 * Created: 21-Sep-18 06:09:49 PM
 *  Author: MO_Ali
 */ 
#include "Timer1.h"
extern Timer1_CfgTyp Timer1_CfgArr[NUM_OF_TIMERSS] ;

void Timer1_Init()
{
	
	Timer1_CfgTyp* CfgPtr = NULL ;
	CfgPtr = &Timer1_CfgArr[0] ;
	Dio_Write_Reg ( &TCCR1B , CS10 , STD_GET_BIT(CfgPtr->Pre_Scalar , 0) );
	Dio_Write_Reg ( &TCCR1B , CS11 , STD_GET_BIT(CfgPtr->Pre_Scalar , 1) );
	Dio_Write_Reg ( &TCCR1B , CS12 , STD_GET_BIT(CfgPtr->Pre_Scalar , 2) );
	
	
	Dio_Write_Reg ( &TCCR1A , WGM10 ,  STD_GET_BIT(CfgPtr->WaveGenMode , 0) );
	Dio_Write_Reg ( &TCCR1A , WGM11 ,  STD_GET_BIT(CfgPtr->WaveGenMode , 1) );
	Dio_Write_Reg ( &TCCR1B , WGM12 ,  STD_GET_BIT(CfgPtr->WaveGenMode , 2) );
	Dio_Write_Reg ( &TCCR1B , WGM13 ,  STD_GET_BIT(CfgPtr->WaveGenMode , 3) );
	
	Dio_Write_Reg ( &TCCR1A , COM1A0 , STD_GET_BIT(CfgPtr->COMMode , 0) );
	Dio_Write_Reg ( &TCCR1A , COM1A1 , STD_GET_BIT(CfgPtr->COMMode , 1) );
	Dio_Write_Reg ( &TCCR1A , COM1B0 , STD_GET_BIT(CfgPtr->COMMode , 0) );
	Dio_Write_Reg ( &TCCR1A , COM1B1 , STD_GET_BIT(CfgPtr->COMMode , 1) );
	
	
	//Enable Over_Flow & Compare Interrupts
	Dio_Write_Reg(&TIMSK , OCIE1A , 1);
	//Dio_Write_Reg(&TIMSK , OCIE1B , 1);
	//Dio_Write_Reg(&TIMSK , TOIE0 , 1);
	//enable global interrupt
	//TCNT0 = 0 ;
}


void Timer1_Val (uint16 Val)
{
	TCNT1 = Val ;
}
uint8 Check_Timer1_Val()
{
	return TCNT1 ;
}

void CLR_Timer1()
{
	TCNT1 = 0 ;
}

//

void Timer1_Comp (uint16 Val)
{
	OCR1A = Val ;
}
void Timer1_IntComp(P2FvoidTyp fun)
{
	Timer1_CfgArr[0].OC_Han = fun ;
}
/*ISR(TIMER1_COMPA_vect)
{
	counter++ ;
	FLAG1 = 1 ;
}*/
ISR(TIMER1_COMPA_vect)
{
	(Timer1_CfgArr[0].OC_Han) () ;
	STD_CLR_FLAG(TIFR , OCF1A);
}
/*void Timer1_IntOF(P2FvoidTyp fun)
{
	Timer0_CfgArr[0].OF_Han = fun ;
}
ISR(TIMER1_OVF_vect)
{
	(Timer0_CfgArr[0].OF_Han) () ;
	STD_CLR_FLAG(TIFR , TOV0);
}
*/
