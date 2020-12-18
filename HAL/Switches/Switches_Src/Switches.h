

#ifndef _SWITCHES_H_
#define _SWITCHES_H_
#include "../../../Std_Headers/Controller.h"
#include "../../../Std_Headers/Std_Types.h"
#include "../../../Std_Headers/Std_Macros.h"
#include "../../../Std_Headers/Amit_Kit.h"
#include "../../../MCAL/Dio/Dio_Src/Dio.h"
#include "../../Switches/Switches_Cfg/Switches_Cfg.h"

typedef enum { Switch_0=0 , Switch_1 , Switch_2 , NUM_OF_SWITCHES } Switch_IdTyp ;
typedef enum { Not_Pressed=0 , Pre_Pressed , Pressed ,  Post_Pressed } State_Typ ;

volatile static State_Typ State_Read[NUM_OF_SWITCHES] ;



extern Std_RetTyp Switches_Init (void);
boolean SW_State (Switch_IdTyp SwitchId);
extern boolean SW_Pressed (Switch_IdTyp SwitchId);
extern boolean SW_Pressed_Once (Switch_IdTyp SwitchId);

#endif /* SWITCHES_H_ */