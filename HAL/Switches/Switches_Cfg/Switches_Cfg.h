

#ifndef _SWITCHESCFG_H_
#define _SWITCHESCFG_H_
#include "../Switches_Src/Switches.h"

typedef struct 
{
	Dio_ChannelIdTyp SwitchId;
	boolean isActive ; 
	}Switch_CfgTyp;
	
#ifndef Active_High
#define Active_High (1u)
#endif

#ifndef Active_Low
#define Active_Low (0u)
#endif


#endif /* SWITCHESCFG_H_ */