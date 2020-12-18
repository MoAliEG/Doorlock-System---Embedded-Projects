
#include "../Dio_Src/Dio.h"
#include "Dio_Cfg.h"


const Dio_ChannelCfgTyp Dio_CfgArr [NUM_OF_CHANNELS] = 
{
    //SW_0
    {
        PORT_D,
        P0,
        STD_INPUT,
        DIO_PUL_DIS,
        DIO_DNT_CARE
    },
    //SW_1
    {
        PORT_D,
        P1,
        STD_INPUT,
        DIO_PUL_DIS,
        DIO_DNT_CARE
    },
    //SW_2
    {
        PORT_D,
        P2,
        STD_INPUT,
        DIO_PUL_DIS,
        DIO_DNT_CARE
    },
    //LED_0
    {
        PORT_D,
        P5,
        STD_OUTPUT,
        DIO_DNT_CARE,
        STD_LOW
    },
    //LED_1
    {
        PORT_D,
        P6,
        STD_OUTPUT,
        DIO_DNT_CARE,
        STD_LOW
    },
    //LED_2
    {
        PORT_D,
        P7,
        STD_OUTPUT,
        DIO_DNT_CARE,
        STD_LOW
    },
	//Seg7_En1
	{
		PORT_C,
		P2,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//Seg7_En2
	{
		PORT_C,
		P3,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//Seg7_DA
	{
		PORT_C,
		P4,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//Seg7_DB
	{
		PORT_C,
		P5,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//Seg7_DC
	{
		PORT_C,
		P6,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//Seg7_DD
	{
		PORT_C,
		P7,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//DIO_LCD_E
	{
		PORT_B,
		P3,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW	
	},
	//DIO_LCD_RW
	{
		PORT_B,
		P2,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW	
	},
	//DIO_LCD_RS
	{
		PORT_B,
		P1,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//DIO_LCD_D4
	{
		PORT_A,
		P4,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//DIO_LCD_D5
	{
		PORT_A,
		P5,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//DIO_LCD_D6
	{
		PORT_A,
		P6,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	//DIO_LCD_D7
	{
		PORT_A,
		P7,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_LOW
	},
	// DIO_ADC0
	{
		PORT_A,
		P0,
		STD_INPUT,
		DIO_PUL_DIS,
		DIO_DNT_CARE
	},
	// DIO_ADC1
	{
		PORT_A,
		P1,
		STD_INPUT,
		DIO_PUL_DIS,
		DIO_DNT_CARE
	},
	//DIO_KEYPAD_ROW0
	{
		PORT_C,
		P7,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_HIGH
	},
	//DIO_KEYPAD_ROW1
	{
		PORT_C,
		P6,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_HIGH
	},
	//DIO_KEYPAD_ROW2
	{
		PORT_C,
		P5,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_HIGH
	},
	//DIO_KEYPAD_ROW3
	{
		PORT_C,
		P4,
		STD_OUTPUT,
		DIO_DNT_CARE,
		STD_HIGH
	},
	//DIO_KEYPAD_COL0
    {
	    PORT_C,
	    P3,
	    STD_INPUT,
	    DIO_PUL_DIS,
	    DIO_DNT_CARE
    },
	//DIO_KEYPAD_COL1
	{
		PORT_C,
		P2,
		STD_INPUT,
		DIO_PUL_DIS,
		DIO_DNT_CARE
	},
	//DIO_KEYPAD_COL2
	{
		PORT_A,
		P1,
		STD_INPUT,
		DIO_PUL_DIS,
		DIO_DNT_CARE
	},
	//DIO_KEYPAD_COL3
	{
		PORT_A,
		P0,
		STD_INPUT,
		DIO_PUL_DIS,
		DIO_DNT_CARE
	}
};