

#include "Leds.h"
#include "../Leds_Cfg/Leds_Cfg.h"
extern const Led_CfgTyp Led_Cfgarr [NUM_OF_LEDS];
Std_RetTyp Leds_Init (void){
	uint8 u8LedIdx ;
	const Led_CfgTyp* CfgPtr = NULL ; 
	for (u8LedIdx=0 ; u8LedIdx<NUM_OF_LEDS; u8LedIdx++){
		CfgPtr = &Led_Cfgarr[u8LedIdx];
		if (CfgPtr->isActive == Active_High) Dio_ClearChannel(CfgPtr->LedId);
		else Dio_SetChannel(CfgPtr->LedId);
	}
	return STD_OK;
}

Std_RetTyp LED_ON (Led_IdTyp LedId){
	Std_RetTyp RetVal = STD_OK ;
	Led_CfgTyp* CfgPtr = NULL ;
	CfgPtr = &Led_Cfgarr[LedId];
	if (LedId >= NUM_OF_LEDS) RetVal = STD_NOT_OK ;
	else
	{
		if(CfgPtr->isActive == Active_High) Dio_SetChannel(CfgPtr->LedId);
		else Dio_ClearChannel(CfgPtr->LedId);
	}
	return RetVal;
}

Std_RetTyp LED_OFF (Led_IdTyp LedId){
	Std_RetTyp RetVal = STD_OK ;
	Led_CfgTyp* CfgPtr = NULL ;
	CfgPtr = &Led_Cfgarr[LedId];
	if (LedId >= NUM_OF_LEDS) RetVal = STD_NOT_OK ;
	else
	{
		if(CfgPtr->isActive == Active_High) Dio_ClearChannel(CfgPtr->LedId);
		else Dio_SetChannel(CfgPtr->LedId);
	}
	return RetVal;
}

Std_RetTyp LED_TGL (Led_IdTyp LedId){
	Std_RetTyp RetVal = STD_OK ;
	Led_CfgTyp* CfgPtr = NULL ;
	CfgPtr = &Led_Cfgarr[LedId];
	if (LedId >= NUM_OF_LEDS) RetVal = STD_NOT_OK ;
	else Dio_ToggleChannel(CfgPtr->LedId);
	return RetVal;
}