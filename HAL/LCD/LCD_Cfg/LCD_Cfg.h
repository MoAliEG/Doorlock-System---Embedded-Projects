

#ifndef _LCD_CFG_H_
#define _LCD_CFG_H_

#include "../LCD_Src/LCD.h"

typedef enum {FourBitMode , EightBitMode} LCD_MODE ;
	
typedef struct {
		Dio_ChannelIdTyp LCD_EnableId ;
		Dio_ChannelIdTyp LCD_RWId ;
		Dio_ChannelIdTyp LCD_RsId ;
		Dio_ChannelIdTyp LCDD4 ;
		Dio_ChannelIdTyp LCDD5 ;
		Dio_ChannelIdTyp LCDD6 ;
		Dio_ChannelIdTyp LCDD7 ;
		LCD_MODE LCDMode ;
	} LCD_CfgTyp ;


#endif /* LCD_CFG_H_ */