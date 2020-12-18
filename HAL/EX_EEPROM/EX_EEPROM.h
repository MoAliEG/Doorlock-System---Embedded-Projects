/*
 * EX_EEPROM.h
 *
 * Created: 05-Oct-18 09:47:07 PM
 *  Author: MO_Ali
 */ 


#ifndef _EX_EEPROM_H_
#define _EX_EEPROM_H_

#include "../../main.h"

#define EX_EEPROM_ADR_Write (0xa0)
#define EX_EEPROM_ADR_Read (0xa1)

extern void EX_EEPROM_Write(uint16 address , uint8 data);
extern void EX_EEPROM_Read (uint16 address , uint8* data);
extern void EX_EEPROM_WriteStr8Byte(uint16 address , uint8* data );
extern void EX_EEPROM_WriteStrSize (uint16 address , uint8* data ,uint8 size);
extern void EX_EEPROM_ReadStrSize (uint16 address , uint8* data , uint8 Size);
extern void EX_EEPROM_CLR (void);
extern uint8 EX_EEPROM_Comp(uint16 address , uint8* data2 );


#endif /* _EX_EEPROM_H_ */