
#include "Timer0.h"
extern Timer0_CfgTyp Timer0_CfgArr[NUM_OF_TIMERS] ;

void Timer0_Init()
{
	
	Timer0_CfgTyp* CfgPtr = NULL ;
	CfgPtr = &Timer0_CfgArr[0] ;
	Dio_Write_Reg ( &TCCR0 , CS00 , STD_GET_BIT(CfgPtr->Pre_Scalar , 0) );
	Dio_Write_Reg ( &TCCR0 , CS01 , STD_GET_BIT(CfgPtr->Pre_Scalar , 1) );
	Dio_Write_Reg ( &TCCR0 , CS02 , STD_GET_BIT(CfgPtr->Pre_Scalar , 2) );
	
	
	Dio_Write_Reg ( &TCCR0 , WGM00 ,  STD_GET_BIT(CfgPtr->WaveGenMode , 0) );
	Dio_Write_Reg ( &TCCR0 , WGM01 ,  STD_GET_BIT(CfgPtr->WaveGenMode , 1) );
	
	Dio_Write_Reg ( &TCCR0 , COM00 , STD_GET_BIT(CfgPtr->COMMode , 0) );
	Dio_Write_Reg ( &TCCR0 , COM01 , STD_GET_BIT(CfgPtr->COMMode , 1) );
	
	
	//Enable Over_Flow & Compare Interrupts
		Dio_Write_Reg(&TIMSK , OCIE0 , 1); 
		Dio_Write_Reg(&TIMSK , TOIE0 , 1);
		//put initial vlaue 
		TCNT0 = 0 ;
}

void Timer0_IntComp(P2FvoidTyp fun)
{
	Timer0_CfgArr[0].OC_Han = fun ;
}
ISR(TIMER0_COMP_vect)
{
	(Timer0_CfgArr[0].OC_Han) () ;
	STD_CLR_FLAG(TIFR , OCF0);
}

void Timer0_IntOF(P2FvoidTyp fun)
{
	Timer0_CfgArr[0].OF_Han = fun ;
}
ISR(TIMER0_OVF_vect)
{
	(Timer0_CfgArr[0].OF_Han) () ;
	STD_CLR_FLAG(TIFR , TOV0);
}

void Timer0_Val (uint8 Val)
{
	TCNT0 = Val ;
}
uint8 Check_Timer0_Val()
{
	return TCNT0 ;
} 

void CLR_Timer0()
{
	TCNT0 = 0 ;
}

void Timer0_Comp (uint8 Val)
{
	OCR0 = Val ;
}