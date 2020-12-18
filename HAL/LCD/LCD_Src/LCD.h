

#ifndef _LCD_H_
#define _LCD_H_

/*
#include "../../../Std_Headers/Controller.h"
#include "../../../Std_Headers/Std_Types.h"
#include "../../../Std_Headers/Std_Macros.h"
#include "../../../Std_Headers/Amit_Kit.h"
#include "../../../MCAL/Dio/Dio_Src/Dio.h"*/
#include "../../../main.h"
#include "../LCD_Cfg/LCD_Cfg.h"

void LCD_DisplayString (uint8* STR);
void LCD_DisplayChar (uint8 CHAR);
void LCD_SetPosition(uint8 row , uint8 col);

extern Std_RetTyp LCD_Init () ;

void LCD_SendData (uint8 DATA);
void LCD_Command (uint8 CMD);
void STD_LCD_DELAY ();
extern void LCD_CLR() ;
extern void LCD_Home ();
extern void LCD_Cursor_Blink();
extern void LCD_Cursor_NotBlink();

extern void LCD_DisplayString (uint8* STR);
extern void LCD_DisplayStringL (uint8* STR , uint8 Length);
extern void LCD_DisplayChar (uint8 CHAR);
extern void LCD_SetPosition(uint8 row , uint8 col);
extern void LCD_DisplayNum (uint16 Num);
extern void LCD_DisplayFlo (f32 flo , uint8 frac);
extern void LCD_BackSpace (void);
extern void LCD_ClrLine(void);

extern uint8 LCD_Cursor_Pos;

typedef enum {LCD_0 , NUM_OF_LCDS} LCD_IdTyp ;




#endif /* LCD_H_ */