/*
 * Key_Pad.c
 *
 * Created: 25-Sep-18 07:02:08 AM
 *  Author: MO_Ali
 */ 
#include "Key_Pad.h"
#define ROW_NUM (4u)
#define COL_NUM (4u)

/*uint8 KEY_PAD [4][4] = {{ 'c' , '0' , '=' , '+' },
						{ '1' , '2' , '3' , '-' },
						{ '4' , '5' , '6' , '*' },
						{ '7' , '8' , '9' , '/'  }};*/

uint8 KEY_PAD [4][4] = {{ '1' , '2' ,	'3' ,		KEYPAD_BackSpace },
						{ '4' , '5' ,	'6' ,		KEYPAD_CLR },
						{ '7' , '8' ,	'9' ,	'C'	},
						{ '*' , '0' , '#' , KEYPAD_ENTER }};
							
uint8 Row_Loc = 0 , Col_Loc = 0 ,Keypad_index = 0; 
boolean G__KeyPad_Enter = 0 ;
boolean G__KeyPad_Last = 0 ;
uint8 G_KeyPad_S = 0 ;
uint8 KeyPad_ArrSave[16] ;
void Clr_SavedArr (void)
{
	uint8 i=0 ;
	for (i=0 ; i<16 ; i++)
	{
		KeyPad_ArrSave[i] = 0 ;
	}
	Row_Loc = 0 ;
	Col_Loc = 0 ;
	Keypad_index=0;
	G__KeyPad_Enter = 0;
}

uint16 KeyPad_Ret (void)
{
	uint16 Ret_Val  = atoi(KeyPad_ArrSave) ; 
	Clr_SavedArr ();
	return Ret_Val ;
}
uint16 KeyPad_RetStr (void)
{
	uint16* Ret_Val  = &KeyPad_ArrSave ;
	Clr_SavedArr ();
	return Ret_Val ;
}
void AllData_Clear (void)
{
	LCD_CLR();
	Clr_SavedArr();
}
void STD_KeyPad_DELAY (void)
{
	_delay_ms(20);
}
KeyPad_State Key_Statue (void)
{
	uint8 i = 0 , COL_Val[COL_NUM];
	KeyPad_State Ret_Val = KeyPad_NotPressed ;
	Dio_Read(DIO_KEYPAD_COL0 , &COL_Val[0] );
	Dio_Read(DIO_KEYPAD_COL1 , &COL_Val[1] );
	Dio_Read(DIO_KEYPAD_COL2 , &COL_Val[2] );
	Dio_Read(DIO_KEYPAD_COL3 , &COL_Val[3] );
	for (i=0 ; i<COL_NUM ; i++)
	{
		if ( COL_Val[i] == STD_LOW)
		{
			Ret_Val = KeyPad_Pressed ;
			Col_Loc = i ;
		}
		else
			continue;
	}
	return Ret_Val ;
}
void KeyPad_Init (void)
{
	G__KeyPad_Enter = 0 ;
	G_KeyPad_S = 0 ;
	G__KeyPad_Last = 1;
	/* ground all Rows */
	Dio_ClearChannel(DIO_KEYPAD_ROW0);
	Dio_ClearChannel(DIO_KEYPAD_ROW1);
	Dio_ClearChannel(DIO_KEYPAD_ROW2);
	Dio_ClearChannel(DIO_KEYPAD_ROW3);
	/* Put High on Cols */
	Dio_SetChannel(DIO_KEYPAD_COL0);
	Dio_SetChannel(DIO_KEYPAD_COL1);
	Dio_SetChannel(DIO_KEYPAD_COL2);
	Dio_SetChannel(DIO_KEYPAD_COL3);
	//
	Clr_SavedArr ();	
}
void KeyPad_ON (void)
{
	if ((Key_Statue() == KeyPad_NotPressed) && (G__KeyPad_Last == 1))
	{
		/* ground all Rows */
			Dio_ClearChannel(DIO_KEYPAD_ROW0);
			Dio_ClearChannel(DIO_KEYPAD_ROW1);
			Dio_ClearChannel(DIO_KEYPAD_ROW2);
			Dio_ClearChannel(DIO_KEYPAD_ROW3);
		/* Put High on Cols */	
			Dio_SetChannel(DIO_KEYPAD_COL0);
			Dio_SetChannel(DIO_KEYPAD_COL1);
			Dio_SetChannel(DIO_KEYPAD_COL2);
			Dio_SetChannel(DIO_KEYPAD_COL3);
		//
			G__KeyPad_Last = 0 ;
			
	}
	else if ((G__KeyPad_Last == 0) && (Key_Statue() == KeyPad_Pressed)) /* check if any Key Pressed */
		{
			STD_KeyPad_DELAY() ; /* call the debounce */
			if (Key_Statue() == KeyPad_Pressed)
			{
				G_KeyPad_S = 1 ;
				G__KeyPad_Last = 1 ;
			}
			else
				G_KeyPad_S = 0;
		}
	if (1 == G_KeyPad_S)
	{
		G_KeyPad_S = 0 ;
		while(1)
		{
			/* Ground Row 0 (ONLY) then Check The Columns */
			
			Dio_ClearChannel (DIO_KEYPAD_ROW0) ;
			Dio_SetChannel (DIO_KEYPAD_ROW1) ;
			Dio_SetChannel (DIO_KEYPAD_ROW2) ;
			Dio_SetChannel (DIO_KEYPAD_ROW3) ;
			
			if (Key_Statue() == KeyPad_Pressed)
			{
				Row_Loc = 0;
				break;
			}
			
			/*************************************************************/
			
			/* Clear Row 1 (ONLY) then Check The Columns */
			
			Dio_SetChannel (DIO_KEYPAD_ROW0) ;
			Dio_ClearChannel (DIO_KEYPAD_ROW1) ;
			Dio_SetChannel (DIO_KEYPAD_ROW2) ;
			Dio_SetChannel (DIO_KEYPAD_ROW3) ;
			
			if (Key_Statue() == KeyPad_Pressed)
			{
				Row_Loc = 1;
				break;
			}
			
			/*************************************************************/
			
			/* Clear Row 2 (ONLY) then Check The Columns */
			
			Dio_SetChannel (DIO_KEYPAD_ROW0) ;
			Dio_SetChannel (DIO_KEYPAD_ROW1) ;
			Dio_ClearChannel (DIO_KEYPAD_ROW2) ;
			Dio_SetChannel (DIO_KEYPAD_ROW3) ;
			
			if (Key_Statue() == KeyPad_Pressed)
			{
				Row_Loc = 2;
				break;
			}
			
			/*************************************************************/
			
			/* Clear Row 3 (ONLY) then Check The Columns */
			
			Dio_SetChannel (DIO_KEYPAD_ROW0) ;
			Dio_SetChannel (DIO_KEYPAD_ROW1) ;
			Dio_SetChannel (DIO_KEYPAD_ROW2) ;
			Dio_ClearChannel (DIO_KEYPAD_ROW3) ;
			
			if (Key_Statue() == KeyPad_Pressed)
			{
				Row_Loc = 3;
				break;
			}
		}	
		
		KeyPad_ArrSave[Keypad_index] = KEY_PAD[Row_Loc][Col_Loc];  /* Sava the Data */
		
		/***************** if Back Space Detected **********************/
		if (KeyPad_ArrSave[Keypad_index] == KEYPAD_BackSpace)
		{
			LCD_BackSpace();
			KeyPad_ArrSave[Keypad_index--] = 0 ;
		}
		/***************************************************************************************/	
	
		/***************** if Clear Detected**********************/
		else if (KeyPad_ArrSave[Keypad_index] == KEYPAD_CLR)
		{
			LCD_ClrLine();
			Clr_SavedArr();
		}
		/***************************************************************************************/
	
		/***************** if ENTER Detected**********************/
		else if (KeyPad_ArrSave[Keypad_index] == KEYPAD_ENTER)
		{
			G__KeyPad_Enter = 1 ;
			KeyPad_ArrSave[Keypad_index++] = NULL ;
			while(Keypad_index <16)
			{
				KeyPad_ArrSave[Keypad_index++] = 0xff ;
			}
		}
		/***************************************************************************************/
	
		else 
		{
			LCD_DisplayChar(KeyPad_ArrSave[Keypad_index++]) ;
		}	
	}
}