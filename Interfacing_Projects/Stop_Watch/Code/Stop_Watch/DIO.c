/*
 * DIO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mina Adel
 */

#include "DIO.h"
#include "data_types.h"

/************************Global Variables******************/
uint32_t ST_Current_Val=0;
/*********************************************************/

/**DIO_Init: FUNCTION THAT INITIALIZES THE PORT WITH THE REQUIRED INPUT AND OUTPUT PINS**/
void DIO_Init(PORT_NAME PORT,uint8_t OUTPUT_PINS,uint8_t INPUT_PINS){

    switch(PORT){
    case(PORTA):
            SYSCTL_RCGCGPIO_R |= 0x00000001;
            while(SYSCTL_RCGCGPIO_R&0x00000001==0){};
            GPIO_PORTA_LOCK_R =0x4C4F434B;
            GPIO_PORTA_CR_R=(OUTPUT_PINS|INPUT_PINS);
            GPIO_PORTA_DIR_R|=(OUTPUT_PINS);
            GPIO_PORTA_DIR_R&=~(INPUT_PINS);
            GPIO_PORTA_PUR_R|=(INPUT_PINS);
            GPIO_PORTA_DEN_R=(OUTPUT_PINS|INPUT_PINS);
            break;
    case(PORTB):
            SYSCTL_RCGCGPIO_R |= 0x00000002;
            while(SYSCTL_RCGCGPIO_R&0x00000002==0){};
            GPIO_PORTB_LOCK_R =0x4C4F434B;
            GPIO_PORTB_CR_R=(OUTPUT_PINS|INPUT_PINS);
            GPIO_PORTB_DIR_R|=(OUTPUT_PINS);
            GPIO_PORTB_DIR_R&=~(INPUT_PINS);
            GPIO_PORTB_PUR_R|=(INPUT_PINS);
            GPIO_PORTB_DEN_R=(OUTPUT_PINS|INPUT_PINS);
            break;
    case(PORTC):
            SYSCTL_RCGCGPIO_R |= 0x00000004;
            while(SYSCTL_RCGCGPIO_R&0x00000004==0){};
            GPIO_PORTC_LOCK_R =0x4C4F434B;
            GPIO_PORTC_CR_R=(OUTPUT_PINS|INPUT_PINS);
            GPIO_PORTC_DIR_R|=(OUTPUT_PINS);
            GPIO_PORTC_DIR_R&=~(INPUT_PINS);
            GPIO_PORTC_PUR_R|=(INPUT_PINS);
            GPIO_PORTC_DEN_R=(OUTPUT_PINS|INPUT_PINS);
            break;
    case(PORTD):
            SYSCTL_RCGCGPIO_R |= 0x00000008;
            while(SYSCTL_RCGCGPIO_R&0x00000008==0){};
            GPIO_PORTD_LOCK_R =0x4C4F434B;
            GPIO_PORTD_CR_R=(OUTPUT_PINS|INPUT_PINS);
            GPIO_PORTD_DIR_R|=(OUTPUT_PINS);
            GPIO_PORTD_DIR_R&=~(INPUT_PINS);
            GPIO_PORTD_PUR_R|=(INPUT_PINS);
            GPIO_PORTD_DEN_R=(OUTPUT_PINS|INPUT_PINS);
            break;
    case(PORTE):
            SYSCTL_RCGCGPIO_R |= 0x00000010;
            while(SYSCTL_RCGCGPIO_R&0x00000010==0){};
            GPIO_PORTE_LOCK_R =0x4C4F434B;
            GPIO_PORTE_CR_R=(OUTPUT_PINS|INPUT_PINS);
            GPIO_PORTE_DIR_R|=(OUTPUT_PINS);
            GPIO_PORTE_DIR_R&=~(INPUT_PINS);
            GPIO_PORTE_PUR_R|=(INPUT_PINS);
            GPIO_PORTE_DEN_R=(OUTPUT_PINS|INPUT_PINS);
            break;
    case(PORTF):
            SYSCTL_RCGCGPIO_R |= 0x00000020;
            while(SYSCTL_RCGCGPIO_R&0x00000020==0){};
            GPIO_PORTF_LOCK_R =0x4C4F434B;
            GPIO_PORTF_CR_R=(OUTPUT_PINS|INPUT_PINS);
            GPIO_PORTF_DIR_R|=(OUTPUT_PINS);
            GPIO_PORTF_DIR_R&=~(INPUT_PINS);
            GPIO_PORTF_PUR_R|=(INPUT_PINS);
            GPIO_PORTF_DEN_R=(OUTPUT_PINS|INPUT_PINS);
            break;
    default:
        break;
    }
}

void DIOPortFInterrupt (void)
{
    GPIO_PORTF_IS_R &=~(0x11);//EDGE SENSITIVE FOR SW1 and SW2
    GPIO_PORTF_IEV_R &=~(0x11);//FALLING EDGE SENSITIVE FOR SW1 and SW2
    GPIO_PORTF_IM_R|=(0x11);//WHEN INTERRUPT IS TRIGGERED, IT GOES TO THE ISR FOR SW1 and SW2
    GPIO_PORTF_ICR_R|=(0x11);//CLEAR THE INTERRUPT FLAG JUST IN CASE FOR SW1 and SW2
}

void PORTF_HANDLER(void){
    delay_us(200);//Debouncing Delay
    /*If SW2 was pressed*/
    if(GPIO_PORTF_RIS_R&0x01){
        if(GET_BIT(NVIC_ST_CTRL_R,0)){//IF THE ENABLE PIN IS HIGH
            /*************PAUSE*****************/
            ST_DeInit();/*Disable the SysTick Timer*/
            ST_Current_Val=NVIC_ST_CURRENT_R;/*Get the Current value and store it*/
        }
        else{
            /************RESUME****************/
            NVIC_ST_CURRENT_R=ST_Current_Val;/*Place the stored value in the Current Register*/
            SET_BIT(NVIC_ST_CTRL_R,0);/*enable the SysTick Timer*/
        }
    }
    /*If SW1 was pressed*/
    else if(GPIO_PORTF_RIS_R&0x10){
        SET_BIT(NVIC_ST_CTRL_R,0);/*enable the SysTick Timer*/
    }
    GPIO_PORTF_ICR_R|=(0x11);//CLEAR THE INTERRUPT FLAG FOR SW1 and SW2
}

