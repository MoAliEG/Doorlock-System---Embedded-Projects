

#ifndef _LEDS_H_
#define _LEDS_H_
#include "../../../Std_Headers/Controller.h"
#include "../../../Std_Headers/Std_Types.h"
#include "../../../Std_Headers/Std_Macros.h"
#include "../../../Std_Headers/Amit_Kit.h"
#include "../../../MCAL/Dio/Dio_Src/Dio.h"
#include "../Leds_Cfg/Leds_Cfg.h"

typedef enum {LED_0 , LED_1 , LED_2 , NUM_OF_LEDS} Led_IdTyp;
Std_RetTyp Leds_Init (void);
Std_RetTyp LED_ON (Led_IdTyp LedId);
Std_RetTyp LED_OFF (Led_IdTyp LedId);
Std_RetTyp LED_TGL (Led_IdTyp LedId);



#endif /* LEDS_H_ */