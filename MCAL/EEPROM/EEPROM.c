
/*
 * EEPROM.c
 *
 * Created: 27-Sep-18 06:42:24 AM
 *  Author: MO_Ali
 */ 
#include "EEPROM.h"

void EEPROM_Write (uint16 address , uint8 data)
{
	// 1. Wait until EEWE becomes zero.
		while(STD_GET_BIT(EECR,EEWE));
	// 2. Wait until SPMEN in SPMCR becomes zero.
		while(STD_GET_BIT(SPMCR,SPMEN));
	// 3. Write new EEPROM address to EEAR (optional).
		EEAR = address ;
	// 4. Write new EEPROM data to EEDR (optional).
		EEDR = data ;
	// 5. Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR.
		STD_SET_BIT(EECR,EEMWE);
	// 6. Within four clock cycles after setting EEMWE, write a logical one to EEWE.
		STD_SET_BIT(EECR,EEWE);
}

void EEPROM_Read(uint16 address , uint8* data)
{
	// 1. Wait until EEWE becomes zero (previous instruction)
		while(STD_GET_BIT(EECR,EEWE));
	// 2. Write EEPROM address to EEAR .
		EEAR = address ;
	// 3. write a logical one to EERE.
		STD_SET_BIT(EECR,EERE);
	// 4. Return BY Data
		*data = EEDR ;
}