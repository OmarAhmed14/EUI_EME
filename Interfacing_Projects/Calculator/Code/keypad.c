/*
 * KeyPad.c
 *
 *  Created on: Aug 18, 2023
 *      Author: EUI-Support
 */

#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "data_types.h"

uint8_t KeyPad[4][4] = {'1', '2', '3', '+',
                        '4', '5', '6', '-',
                        '7', '8', '9', '/',
                        '*', '0', '#', '='};

void KeyPad_Init (void)
{
    // Init Port D // Coloums (D0 >> D3)
    SYSCTL_RCGCGPIO_R |= 0X8;
    while ((SYSCTL_RCGCGPIO_R &0x8)==0);
    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    //GPIO_PORTD_DIR_R |= 0xE;
    GPIO_PORTD_DIR_R &=~ 0xF;
    GPIO_PORTD_CR_R = 0xF;
    GPIO_PORTD_PUR_R = 0xF;
    GPIO_PORTD_DEN_R = 0xF;

    GPIO_PORTD_IM_R &=~ 0xF;

    NVIC_EN0_R|=(1<<3);

    GPIO_PORTD_IS_R &=~ 0xF;
    GPIO_PORTD_IEV_R &=~ 0xF;

    GPIO_PORTD_IM_R |=0xF;

    //Init Port E // Rows (E0 >> E3)
    SYSCTL_RCGCGPIO_R |= 0X10;
    while ((SYSCTL_RCGCGPIO_R &0x10)==0);
    GPIO_PORTE_LOCK_R = 0x4C4F434B;
    GPIO_PORTE_DIR_R |= 0xF;
    GPIO_PORTE_CR_R = 0xF;
    GPIO_PORTE_DEN_R = 0xF;
}
