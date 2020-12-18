

#ifndef _LEDS_CFG_H_
#define _LEDS_CFG_H_

#include "..\Leds_Src\Leds.h"

typedef struct
{
	Dio_ChannelIdTyp LedId;
	boolean isActive ;
}Led_CfgTyp; 

#ifndef Active_High
#define Active_High (1u)
#endif
#ifndef Active_Low
#define Active_Low (0u)
#endif

#endif /* LEDS_CFG_H_ */