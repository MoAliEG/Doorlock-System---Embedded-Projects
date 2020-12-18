

#include "Switches.h"
extern Switch_CfgTyp Switch_CfgArr [NUM_OF_SWITCHES];
boolean Last_Val[NUM_OF_SWITCHES] ;
Std_RetTyp Switches_Init (void){
	Std_RetTyp Ret_Val ;
	boolean ReadVal ;
	uint8 u8SwitchIdx ;
	const Switch_CfgTyp* CfgPtr = NULL ;
	for (u8SwitchIdx=0 ; u8SwitchIdx<NUM_OF_SWITCHES; u8SwitchIdx++){
		CfgPtr = &Switch_CfgArr[u8SwitchIdx];
		//Initialize State & Last_Value
			State_Read[u8SwitchIdx] = Not_Pressed;
			Last_Val[u8SwitchIdx] = STD_LOW ;
				
		//Check Initial Value
			Dio_Read(CfgPtr->SwitchId , &ReadVal);
			if ((CfgPtr->isActive == Active_High) && (ReadVal == STD_HIGH))
				Ret_Val = STD_NOT_OK;
			else if ((CfgPtr->isActive == Active_Low) && (ReadVal == STD_LOW))
				Ret_Val = STD_NOT_OK;
	}
	
	return Ret_Val ;
}

boolean SW_State (Switch_IdTyp SwitchId){
	boolean Read_Val ;
	boolean Ret_State_Val ;
	Switch_CfgTyp* CfgPtr = NULL ;
	CfgPtr = &Switch_CfgArr[SwitchId];
	Dio_Read(CfgPtr->SwitchId ,&Read_Val);
	if(CfgPtr->isActive == Active_High)
	{
		if( Read_Val == STD_HIGH ) Ret_State_Val = STD_HIGH ;
		else Ret_State_Val = STD_LOW ;
	}
	else
	{
		if( Read_Val == STD_LOW ) Ret_State_Val = STD_HIGH ;
		else Ret_State_Val = STD_LOW ;
	}
	
	return Ret_State_Val;
}
boolean SW_Pressed (Switch_IdTyp SwitchId)
{
	boolean Ret_Val = STD_TRUE ;
	
	switch (State_Read[SwitchId])
	{
		case Not_Pressed :
			if(SW_State(SwitchId))
			{
				State_Read[SwitchId] = Pre_Pressed;
				Ret_Val = STD_FALSE ;
			}
			else
			{
				State_Read[SwitchId] = Not_Pressed;
				Ret_Val = STD_FALSE ;
			}
			break;
		case Pre_Pressed :
			if(SW_State(SwitchId) )
			{
				State_Read[SwitchId]  = Pressed ;
				Ret_Val = STD_TRUE ;
			}
			else 
			{
				State_Read[SwitchId]  = Not_Pressed;
				Ret_Val = STD_FALSE ;
			}
			break;
		case Pressed :
			if(SW_State(SwitchId))
			{
				State_Read[SwitchId]  = Pressed;
				Ret_Val = STD_TRUE ;
			}
			else
			{
				State_Read[SwitchId]  = Post_Pressed;
				Ret_Val = STD_TRUE ;
			}
			break;
		case Post_Pressed :
			if( SW_State(SwitchId) )
			{
				State_Read[SwitchId]  = Pressed;
				Ret_Val = STD_TRUE ;
			}
			else
			{
				State_Read[SwitchId]  = Not_Pressed;
				Ret_Val = STD_FALSE ;
			}
			break;
	}
	return Ret_Val ;
}

boolean SW_Pressed_Once (Switch_IdTyp SwitchId)
{
	boolean Ret_Val  = STD_TRUE;
	switch (State_Read[SwitchId])
	{
		case Not_Pressed :
			if (SW_State(SwitchId))
			{
				State_Read[SwitchId] = Pre_Pressed;
				Ret_Val = STD_FALSE ;
			}
			else
			{
				Last_Val[SwitchId] = STD_LOW ;
				State_Read[SwitchId] = Not_Pressed;
				Ret_Val = STD_FALSE ;
			}
			break;
		case Pre_Pressed :
			if(( SW_State(SwitchId) == STD_TRUE ) && (Last_Val[SwitchId] == STD_LOW))
			{
				Last_Val[SwitchId] = STD_HIGH ;
				State_Read[SwitchId]  = Pressed ;
				Ret_Val = STD_TRUE ;
			}
			else
			{
				State_Read[SwitchId]  = Not_Pressed;
				Ret_Val = STD_FALSE ;
			}
			break;
		case Pressed :
			State_Read[SwitchId]  = Not_Pressed;
			Ret_Val = STD_FALSE ;
			break;
		case Post_Pressed :        // just for warning
			State_Read[SwitchId]  = Not_Pressed;
			break;
			
		}
		_delay_ms(5);
		return Ret_Val ;
}
boolean SW_Not_Pressed (Switch_IdTyp SwitchId) 
{
	return ( !(SW_Pressed(SwitchId)) );
}