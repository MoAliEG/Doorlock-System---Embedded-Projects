/*
 * RTC.h
 *
 * Created: 05-Oct-18 11:51:16 AM
 *  Author: MO_Ali
 */ 


#ifndef _RTC_H_
#define _RTC_H_

#include "../../main.h"

typedef struct
{
  uint8 sec;
  uint8 min;
  uint8 hour;
  uint8 weekDay;
  uint8 date;
  uint8 month;
  uint8 year;  
}rtc_t;
/**************************************************************************************************/


/***************************************************************************************************
                             Commonly used Ds1307 macros/Constants
***************************************************************************************************
  Below values are fixed and should not be changed. Refer Ds1307 DataSheet for more info*/

#define C_Ds1307ReadMode_U8   0xD1u  // DS1307 ID
#define C_Ds1307WriteMode_U8  0xD0u  // DS1307 ID

#define C_Ds1307SecondRegAddress_U8   0x00u   // Address to access Ds1307 SEC register
#define C_Ds1307DateRegAddress_U8     0x04u   // Address to access Ds1307 DATE register
#define C_Ds1307ControlRegAddress_U8  0x07u   // Address to access Ds1307 CONTROL register
/**************************************************************************************************/




/***************************************************************************************************
                             Function Prototypes
***************************************************************************************************/
extern void RTC_Init(void);
extern void RTC_SetDateTime(rtc_t *rtc);
extern void RTC_GetDateTime(rtc_t *rtc);
extern void RTC_SendString(uint8* STR);
extern void RTC_CLR(void) ;
/**************************************************************************************************/



#endif /* RTC_H_ */