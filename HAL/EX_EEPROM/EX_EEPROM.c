/*
 * EX_EEPROM.c
 *
 * Created: 05-Oct-18 09:46:57 PM
 *  Author: MO_Ali
 */ 

#include "EX_EEPROM.h"

void EX_EEPROM_Write(uint16 address , uint8 data)
{
	I2C_Start();   // Send start 
	I2C_Write(EX_EEPROM_ADR_Write);  //Send SLA Address
	
	I2C_Write(address>>8);  // Send Data Address
	I2C_Write(address);
	
	I2C_Write(data);  //Send Data
	
	I2C_Stop();
}

void EX_EEPROM_Read (uint16 address , uint8* data)
{
	I2C_Start();  // Send Start 

	I2C_Write(EX_EEPROM_ADR_Write);  // //Send SLA Address
	
	I2C_Write(address>>8);  // Send Data Address
	I2C_Write(address);

	I2C_Start();  // Send Repeated Start
	I2C_Write(EX_EEPROM_ADR_Read);
	
	*data = I2C_Read(0);  // Read One Time
	I2C_Stop();  // Send Stop
}

void EX_EEPROM_WriteStr8Byte(uint16 address , uint8* data )
{
	I2C_Start();   // Send start
	I2C_Write(EX_EEPROM_ADR_Write);  //Send SLA Address
	
	I2C_Write(address>>8);  // Send Data Address
	I2C_Write(address);
	uint8 i = 0 ;
	for (i=0 ; data[i] != NULL ; i++)
	{
		I2C_Write(data[i]);  //Send Data
	}
	I2C_Write(data[i]) ;
	while (i<8)
	{
		I2C_Write(0xff) ;
		i++;
	}
	
	I2C_Stop();
	_delay_ms(5);
}

void EX_EEPROM_WriteStrSize (uint16 address , uint8* data ,uint8 size)
{
	I2C_Start();   // Send start
	I2C_Write(EX_EEPROM_ADR_Write);  //Send SLA Address
	
	I2C_Write(address>>8);  // Send Data Address
	I2C_Write(address);
	uint8 i = 0 ;
	for (i=0 ; i<size; i++)
	{
		I2C_Write(data[i]);  //Send Data
	}
	
	I2C_Stop();
	_delay_ms(5);
}
void EX_EEPROM_ReadStrSize (uint16 address , uint8* data , uint8 Size)
{
	uint8* Temp = NULL ;
	uint8 i = 0 ; 
	
	I2C_Start();   // Send start
	I2C_Write(EX_EEPROM_ADR_Write);  //Send SLA Address
	
	I2C_Write(address>>8);  // Send Data Address
	I2C_Write(address);
	
	I2C_Start();  // Send Repeated Start
	I2C_Write(EX_EEPROM_ADR_Read);
	
	for (i=0 ; i<(Size-1u) ; i++)
	{
		data[i] =  I2C_Read(1) ;
	}
	data[i] = I2C_Read (0); ;
	I2C_Stop();	
	_delay_ms(5);	
}

/*
void EX_EEPROM_CLR (void)
{
	I2C_Start();   // Send start
	I2C_Write(EX_EEPROM_ADR_Write);  //Send SLA Address
	
	I2C_Write(0x00);  // Send Data Address
	I2C_Write(0x00);
	uint8 i = 0 ;
	for (i=0 ; i<(0x1fffu) ; i++)
	{
		I2C_Write(0xff);  //Send Data
	}
	I2C_Stop();
}*/
Std_RetTyp EX_EEPROM_Comp(uint16 address , uint8* data2 )
{
	uint8 i = 0  ;
	Std_RetTyp Ret_Val = STD_OK;
	uint8 data1[8] ;
	EX_EEPROM_ReadStrSize (address , &data1 , 8u);
	for (i=0 ; i<8u ; i++)
	{
		
		if ( (data1[i]) != (data2[i]) )
		{
			Ret_Val = STD_NOT_OK ;
			break;
		}
		else
			continue;
	}
	return (Ret_Val);
}