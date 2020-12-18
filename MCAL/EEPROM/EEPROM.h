/*
 * EEPROM.h
 *
 * Created: 27-Sep-18 06:42:56 AM
 *  Author: alkab
 */ 


#ifndef _EEPROM_H_
#define _EEPROM_H_

#include "../../main.h"

extern void EEPROM_Write (uint16 address , uint8 data);
extern void EEPROM_Read(uint16 address , uint8* data);

#endif /* _EEPROM_H_ */