/*
 * Key_Pad.h
 *
 * Created: 25-Sep-18 07:02:23 AM
 *  Author: MO_Ali
 */ 


#ifndef _KEY_PAD_H_
#define _KEY_PAD_H_

#include "../../main.h"

#define KEYPAD_BackSpace ('A')
#define KEYPAD_CLR ('B')
#define KEYPAD_ENTER ('D')


extern uint8 KEY_PAD [4][4] ;
extern uint8 Row_Loc , Col_Loc ;
extern void KeyPad_Init (void);
extern uint16 KeyPad_Ret (void) ;
extern uint16 KeyPad_RetStr (void);
extern void Clr_SavedArr (void);
extern void KeyPad_ON (void);
extern uint8 KeyPad_ArrSave[16] ;
typedef enum {KeyPad_NotPressed = 0 , KeyPad_Pressed = 1} KeyPad_State;

extern boolean G__KeyPad_Enter ;		
extern boolean GBack_Flag  ;

#endif /* _KEY_PAD_H_ */