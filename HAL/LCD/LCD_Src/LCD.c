

#include "LCD.h"
extern LCD_CfgTyp LCD_CfgArr[NUM_OF_LCDS] ;
uint8 LCD_Cursor_Pos = 1 ;
Std_RetTyp LCD_Init ()
{
	//if The LCD_Init is the first Initializer function make _delay_ms(15)
		_delay_ms(15);
	uint8 u8DisplayIdx ;
	LCD_CfgTyp* CfgPtr = NULL ;
	for ( u8DisplayIdx = 0u ; u8DisplayIdx < NUM_OF_LCDS  ; u8DisplayIdx++ )
	{
		CfgPtr = &LCD_CfgArr[u8DisplayIdx];
		if (CfgPtr->LCDMode == FourBitMode)
		{
			Dio_ClearChannel( CfgPtr->LCD_EnableId ); //Enable = 0
			LCD_Command(0x33);
			LCD_Command(0x32);
			LCD_Command(0x28);
			LCD_Command(0x0f);   //Display_ON , Cursor_ON
			LCD_Command(0x01);   //Clear_LCD
			STD_LCD_DELAY();
			STD_LCD_DELAY();
			LCD_Command(0x06);  //Shift_Cursor_Right
			LCD_Command(0x80);  //goto First_Line
		}
	}
	LCD_Cursor_Pos = 1 ;
}
void STD_LCD_DELAY ()
{
	_delay_ms((0.1));
}
void LCD_Command (uint8 CMD)
{
	uint8 u8DisplayIdx = 0 ;
	LCD_CfgTyp* CfgPtr = NULL ;
		CfgPtr = &LCD_CfgArr[u8DisplayIdx];
		if (CfgPtr->LCDMode == FourBitMode)
		{
			//send HIGH Nipple to data Pins 		
				Dio_Write_Bit(CfgPtr->LCDD7 , CMD);
				Dio_Write_Bit(CfgPtr->LCDD6 , CMD);
				Dio_Write_Bit(CfgPtr->LCDD5 , CMD);
				Dio_Write_Bit(CfgPtr->LCDD4 , CMD);
			//RS=0 For Command
				Dio_ClearChannel(CfgPtr->LCD_RsId);
			//RW=0 For Write
				Dio_ClearChannel(CfgPtr->LCD_RWId);
			//EN HIGH_TO_LOW Pulse 
				Dio_SetChannel(CfgPtr->LCD_EnableId);
				STD_LCD_DELAY();
				Dio_ClearChannel(CfgPtr->LCD_EnableId);
				STD_LCD_DELAY(); 
			//send LOW Nipple to data Pins 
				CMD = (CMD << 4) ;
				Dio_Write_Bit(CfgPtr->LCDD7 , CMD);
				Dio_Write_Bit(CfgPtr->LCDD6 , CMD);
				Dio_Write_Bit(CfgPtr->LCDD5 , CMD);
				Dio_Write_Bit(CfgPtr->LCDD4 , CMD);
			//EN HIGH_TO_LOW Pulse
				Dio_SetChannel(CfgPtr->LCD_EnableId);
				STD_LCD_DELAY();
				Dio_ClearChannel(CfgPtr->LCD_EnableId);
				STD_LCD_DELAY();
			}

	}
void LCD_SendData (uint8 DATA)
{
	uint8 u8DisplayIdx = 0 ;
	LCD_CfgTyp* CfgPtr = NULL ;
	//for ( u8DisplayIdx = 0u ; u8DisplayIdx < NUM_OF_LCDS  ; u8DisplayIdx++ )
	//{
	CfgPtr = &LCD_CfgArr[u8DisplayIdx];
	if (CfgPtr->LCDMode == FourBitMode)
	{
		//send HIGH Nipple to data Pins
			Dio_Write_Bit(CfgPtr->LCDD7 , DATA);
			Dio_Write_Bit(CfgPtr->LCDD6 , DATA);
			Dio_Write_Bit(CfgPtr->LCDD5 , DATA);
			Dio_Write_Bit(CfgPtr->LCDD4 , DATA);
		//RS=1 For DATA
			Dio_SetChannel(CfgPtr->LCD_RsId);
		//RW=0 For Write
			Dio_ClearChannel(CfgPtr->LCD_RWId);
		//EN HIGH_TO_LOW Pulse
			Dio_SetChannel(CfgPtr->LCD_EnableId);
			STD_LCD_DELAY();
			Dio_ClearChannel(CfgPtr->LCD_EnableId);
			STD_LCD_DELAY();
		//send LOW Nipple to data Pins
			DATA = (DATA << 4) ;
			Dio_Write_Bit(CfgPtr->LCDD7 , DATA);
			Dio_Write_Bit(CfgPtr->LCDD6 , DATA);
			Dio_Write_Bit(CfgPtr->LCDD5 , DATA);
			Dio_Write_Bit(CfgPtr->LCDD4 , DATA);
		//EN HIGH_TO_LOW Pulse
			Dio_SetChannel(CfgPtr->LCD_EnableId);
			STD_LCD_DELAY();
			Dio_ClearChannel(CfgPtr->LCD_EnableId);
			STD_LCD_DELAY();
	}
	if ((LCD_Cursor_Pos == 16) || (LCD_Cursor_Pos == 32));
	else LCD_Cursor_Pos++ ;
		
}


void LCD_SetPosition(uint8 row , uint8 col)
{
	uint8 First_Char_Adr[] = {0x80 , 0xC0};
	LCD_Command(First_Char_Adr[row-1] + (col-1) );
	LCD_Cursor_Pos = ((row-1)*16) + col ;
	STD_LCD_DELAY();
}
void LCD_BackCursor (void)
{
	LCD_Cursor_Pos-- ;
	uint8 row = 1 , col = 1 ;
	if(LCD_Cursor_Pos <= 16)
	{
		row = 1;
		col = LCD_Cursor_Pos;
	}
	else if ((LCD_Cursor_Pos > 16) && (LCD_Cursor_Pos <= 32 ))
	{
		row = 2 ;
		col = LCD_Cursor_Pos-16;
	}
	LCD_SetPosition(row,col);
}
void LCD_BackSpace (void)
{
	if (((LCD_Cursor_Pos >8) && (LCD_Cursor_Pos <=16)) || ((LCD_Cursor_Pos >24) && (LCD_Cursor_Pos <=32)))
	{
		LCD_BackCursor();
		LCD_DisplayString(" ");
		LCD_BackCursor();
	}
	else ;
}

void LCD_ClrLine(void)
{
	uint8 i = 0 ;
	if ((LCD_Cursor_Pos >8) && (LCD_Cursor_Pos <=16))
	{
		while((LCD_Cursor_Pos >8) && (LCD_Cursor_Pos <=16))
		{
			LCD_BackCursor();
			LCD_DisplayString(" ");
			LCD_BackCursor();
		}
	}
	else if ((LCD_Cursor_Pos >24) && (LCD_Cursor_Pos <=32))
	{
		while((LCD_Cursor_Pos >24) && (LCD_Cursor_Pos <=32))
		{
			LCD_BackCursor();
			LCD_DisplayString(" ");
			LCD_BackCursor();
		}
	}
	else ;
}

void LCD_DisplayString (uint8* STR)
{
	uint8 i =0 ;
	for(i=0 ; STR[i] != NULL ; i++)    //CHECK
	{
		LCD_SendData(STR[i]);
	}             
}
void LCD_DisplayStringL (uint8* STR , uint8 Length)
{
	uint8 i =0 ;
	for(i=0 ; ((STR[i] != NULL) && (i<Length)) ; i++)    //CHECK
	{
		LCD_SendData(STR[i]);
	}
}
void LCD_DisplayChar (uint8 CHAR)
{
	LCD_SendData(CHAR);
	
	STD_LCD_DELAY();
}
void LCD_DisplayNum (uint16 Num)
{
	uint8 buffer[16] , i = 0;
	//LCD_SendData(util_Dec2Ascii(Num));
	//ftoa (Num,buffer,0u);
	itoa(Num, buffer , 10) ;
	for(i=0 ; buffer[i] != '\0' ; i++)    //CHECK
	{
		LCD_SendData(buffer[i]);
	}
}
void LCD_DisplayFlo (f32 flo , uint8 frac)
{
	uint8 buffer[20] , i = 0;
	ftoa(flo, buffer , frac) ; 
	for(i=0 ; buffer[i] != NULL ; i++)    //CHECK
	{
		LCD_SendData(buffer[i]);
	}
}
void LCD_CLR(void) 
{
	LCD_Command(0x01);
	LCD_Cursor_Pos = 0 ;
	_delay_ms(2);
}

void LCD_Home (void)
{
	LCD_Command(0x02);
	LCD_Cursor_Pos = 0 ;
	_delay_ms(2);
}
void LCD_Cursor_Blink(void)
{
	LCD_Command(0x0f);
}
void LCD_Cursor_NotBlink(void)
{
	LCD_Command(0x0e);
}
/*CreateCustomCharacter(uint8 *pucPattern,const uint8 cLocation) {
	
	uint8 iLoop=0;
	
	LCD_Command(0x40+(cLocation*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_DisplayString(pucPattern[iLoop]); //Pass the bytes of pattern on LCD
}*/