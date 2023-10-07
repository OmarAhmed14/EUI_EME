/*
 * DIO.h
 *
 *  Created on: Oct 7, 2023
 *      Author: OMAR
 */

#ifndef DIO_H_
#define DIO_H_

#include"tm4c123gh6pm.h"
#include "Imported_data_Types.h"

typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
}PORT_NUM;

#define STD_HIGH   1
#define STD_LOW    0

void Port_Init (void);

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level);

#endif /* DIO_H_ */
