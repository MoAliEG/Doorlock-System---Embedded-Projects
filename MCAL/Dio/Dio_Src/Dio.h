#ifndef _DIO_H_
#define _DIO_H_

#include "../../../Std_Headers/Std_Macros.h"
#include "../../../Std_Headers/Std_Types.h"
#include "../../../Std_Headers/Controller.h"
#include "../Dio_Cfg/Dio_Cfg.h"

#define CHECKS 5



typedef enum{
	DIO_SW_0,
	DIO_SW_1,
	DIO_SW_2,
	DIO_LED_0,
	DIO_LED_1,
	DIO_LED_2,
	DIO_SEG7_En1,
	DIO_SEG7_En2,
	DIO_SEG7_DA,
	DIO_SEG7_DB,
	DIO_SEG7_DC,
	DIO_SEG7_DD,
	DIO_LCD0_E,
	DIO_LCD0_RW,
	DIO_LCD0_RS,
	DIO_LCD0_D4,
	DIO_LCD0_D5,
	DIO_LCD0_D6,
	DIO_LCD0_D7,
	DIO_ADC0,
	DIO_ADC1,
	DIO_KEYPAD_ROW0,
	DIO_KEYPAD_ROW1,
	DIO_KEYPAD_ROW2,
	DIO_KEYPAD_ROW3,
	DIO_KEYPAD_COL0,
	DIO_KEYPAD_COL1,
	DIO_KEYPAD_COL2,
	DIO_KEYPAD_COL3,
	NUM_OF_CHANNELS
}Dio_ChannelIdTyp;


Std_RetTyp Dio_SetDir(Dio_ChannelIdTyp ChannelId) ;
Std_RetTyp Dio_Write (Dio_ChannelIdTyp ChannelId , boolean u8Value);
Std_RetTyp Dio_Read  (Dio_ChannelIdTyp ChannelId , boolean* u8pValuePtr);
Std_RetTyp Dio_Init  (void);
Std_RetTyp Dio_Init_Channel (Dio_ChannelIdTyp ChannelId);
Std_RetTyp Dio_SetChannel (Dio_ChannelIdTyp ChannelId);
Std_RetTyp Dio_ClearChannel (Dio_ChannelIdTyp ChannelId);
Std_RetTyp Dio_ToggleChannel (Dio_ChannelIdTyp ChannelId);



extern const Dio_ChannelCfgTyp Dio_CfgArr [NUM_OF_CHANNELS];

#endif 