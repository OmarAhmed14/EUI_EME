/*
 * DIO.c
 *
 *  Created on: Oct 7, 2023
 *      Author: OMAR
 */

#include"DIO.h"


void Port_Init (void)
{
    SYSCTL_RCGCGPIO_R |= 0x20;  /* Enable clock Port F */

    GPIO_PORTF_DEN_R |= 0x0E;   /* Digital Enable */

    GPIO_PORTF_DIR_R = 0x0E; /* PF1 , PF2 , PF3 are Outputs */

}

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType PIN_Level= STD_LOW;

    Dio_PortType Port = ChannelId/8;
    Dio_ChannelType PIN = ChannelId%8;

    switch (Port)
    {
    case PORTA:
        PIN_Level = ( (GPIO_PORTA_DATA_R >> PIN) & 1 );
        break;
    case PORTB:
        PIN_Level = ( (GPIO_PORTB_DATA_R >> PIN) & 1 );
        break;
    case PORTC:
        PIN_Level = ( (GPIO_PORTC_DATA_R >> PIN) & 1 );
        break;
    case PORTD:
        PIN_Level = ( (GPIO_PORTD_DATA_R >> PIN) & 1 );
        break;
    case PORTE:
        PIN_Level = ( (GPIO_PORTE_DATA_R >> PIN) & 1 );
        break;
    case PORTF:
        PIN_Level = ( (GPIO_PORTF_DATA_R >> PIN) & 1 );
        break;
    default:
        break;
    }

    return PIN_Level;
}

void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    Dio_PortType Port = ChannelId/8;
    Dio_ChannelType PIN = ChannelId%8;

    switch (Port)
    {
    case PORTA:
        switch (Level)
        {
        case STD_HIGH:
            GPIO_PORTA_DATA_R|= (1<<PIN);
            break;
        case STD_LOW:
            GPIO_PORTA_DATA_R &= ~(1<<PIN);
            break;
        default:
            break;
        }
        break;
        case PORTB:
            switch (Level)
            {
            case STD_HIGH:
                GPIO_PORTB_DATA_R|= (1<<PIN);
                break;
            case STD_LOW:
                GPIO_PORTB_DATA_R &= ~(1<<PIN);
                break;
            default:
                break;
            }
            break;
            case PORTC:
                switch (Level)
                {
                case STD_HIGH:
                    GPIO_PORTC_DATA_R|= (1<<PIN);
                    break;
                case STD_LOW:
                    GPIO_PORTC_DATA_R &= ~(1<<PIN);
                    break;
                default:
                    break;
                }
                break;
                case PORTD:
                    switch (Level)
                    {
                    case STD_HIGH:
                        GPIO_PORTD_DATA_R|= (1<<PIN);
                        break;
                    case STD_LOW:
                        GPIO_PORTD_DATA_R &= ~(1<<PIN);
                        break;
                    default:
                        break;
                    }
                    break;
                    case PORTE:
                        switch (Level)
                        {
                        case STD_HIGH:
                            GPIO_PORTE_DATA_R|= (1<<PIN);
                            break;
                        case STD_LOW:
                            GPIO_PORTE_DATA_R &= ~(1<<PIN);
                            break;
                        default:
                            break;
                        }
                        break;
                        case PORTF:
                            switch (Level)
                            {
                            case STD_HIGH:
                                GPIO_PORTF_DATA_R|= (1<<PIN);
                                break;
                            case STD_LOW:
                                GPIO_PORTF_DATA_R &= ~(1<<PIN);
                                break;
                            default:
                                break;
                            }
                            break;
                            default:
                                break;
    }
}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortType Port_Value= PORTA;

    switch (PortId)
    {
    case PORTA:
        Port_Value = GPIO_PORTA_DATA_R ;
        break;
    case PORTB:
        Port_Value = GPIO_PORTB_DATA_R ;
        break;
    case PORTC:
        Port_Value = GPIO_PORTC_DATA_R ;
        break;
    case PORTD:
        Port_Value = GPIO_PORTD_DATA_R ;
        break;
    case PORTE:
        Port_Value = GPIO_PORTE_DATA_R ;
        break;
    case PORTF:
        Port_Value = GPIO_PORTF_DATA_R ;
        break;
    default:
        break;
    }

    return Port_Value;

}

void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)
{
    switch (PortId)
    {
    case PORTA:
        GPIO_PORTA_DATA_R =Level ;
        break;
    case PORTB:
        GPIO_PORTB_DATA_R =Level;
        break;
    case PORTC:
        GPIO_PORTC_DATA_R =Level;
        break;
    case PORTD:
        GPIO_PORTD_DATA_R =Level;
        break;
    case PORTE:
        GPIO_PORTE_DATA_R =Level ;
        break;
    case PORTF:
        GPIO_PORTF_DATA_R =Level;
        break;
    default:
        break;
    }

}



