/*
 * Imported_data_Types.h
 *
 *  Created on: Oct 7, 2023
 *      Author: OMAR
 */

#ifndef IMPORTED_DATA_TYPES_H_
#define IMPORTED_DATA_TYPES_H_

typedef unsigned char Dio_ChannelType  ;    /* Numeric ID of a DIO channel */
typedef unsigned char Dio_PortType     ;    /* Numeric ID of a DIO port. */
typedef unsigned char Dio_LevelType    ;    /* These are the possible levels a DIO channel can have (input or output) */
typedef unsigned char Dio_PortLevelType;    /* If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port. */


#endif /* IMPORTED_DATA_TYPES_H_ */
