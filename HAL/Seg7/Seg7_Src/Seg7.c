

#include "Seg7.h"
#include "../Seg7_Cfg/Seg7_Cfg.h"

/*Global Variables*/

static uint8 G_au8Seg7Buffer[SEG7_NUM_OF_DIS] = {0};

Std_RetTyp Seg7_Init(void)
{
    uint8 u8DisplayIdx;
	const Seg7_CfgTyp * CfgPtr = NULL;

    for (u8DisplayIdx = 0u; u8DisplayIdx < SEG7_NUM_OF_DIS ; u8DisplayIdx++)
    {
		CfgPtr = &Seg7_CfgArr[u8DisplayIdx];
		
		Dio_ClearChannel(CfgPtr->EnablePinId);
        G_au8Seg7Buffer[u8DisplayIdx] = CfgPtr->InitValue;
    }
	
	(void) Seg7_UpdateDisplays();

    return STD_OK;
}

Std_RetTyp Seg7_WriteBuffer(Seg7_IdTyp Seg7Id, uint8 u8DisplayValue)
{
    Std_RetTyp RetVal = STD_OK;

    if ((Seg7Id >= SEG7_NUM_OF_DIS)
        ||(u8DisplayValue > 9u))
    {
        RetVal = STD_NOT_OK;
    }
    else
    {
        G_au8Seg7Buffer[Seg7Id] = u8DisplayValue;
    }

    return RetVal;
}

Std_RetTyp Seg7_UpdateDisplays(void)
{
    Std_RetTyp RetVal = STD_OK;
    uint8 u8displayIdx;
    uint8 u8DisplayValue;
    const Seg7_CfgTyp * CfgPtr = NULL;
    
    for (u8displayIdx = 0; u8displayIdx < SEG7_NUM_OF_DIS; u8displayIdx++)
    {
        CfgPtr = &Seg7_CfgArr[u8displayIdx];
        u8DisplayValue = G_au8Seg7Buffer[u8displayIdx];
        
        Dio_Write(CfgPtr->Seg7AId , STD_GET_BIT(u8DisplayValue,0u));
        Dio_Write(CfgPtr->Seg7BId , STD_GET_BIT(u8DisplayValue,1u));
        Dio_Write(CfgPtr->Seg7CId , STD_GET_BIT(u8DisplayValue,2u));
        Dio_Write(CfgPtr->Seg7DId , STD_GET_BIT(u8DisplayValue,3u));

        Dio_Write(CfgPtr->EnablePinId , STD_HIGH);
        _delay_ms(5);
        Dio_Write(CfgPtr->EnablePinId , STD_LOW);
    }

    return RetVal;
}
