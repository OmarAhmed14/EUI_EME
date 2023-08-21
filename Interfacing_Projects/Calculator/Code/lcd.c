#include "data_types.h"
#include "lcd.h"



void lcd_data(unsigned char data)
{
    //    STEPS:
    Printdata(data);                        //     1.Pass the 8-bit data to the datalines of LCD.
    CLEAR_BIT(GPIO_PORTA_DATA_R,3);         //     * 2.Turn off the R/W to select WRITE mode on the LCD
    SET_BIT(GPIO_PORTA_DATA_R,2);           //     * 3.Turn on the RS to select DATA mode on the LCD
    SET_BIT(GPIO_PORTA_DATA_R,4);           //     * 4.Turn on the EN pin on the LCD
    delay_ms(5);                            //     * 5.Wait for 5ms.
    CLEAR_BIT(GPIO_PORTA_DATA_R,4);         //     * 6.Turn off the EN pin on the LCD
}

void lcd_cmd(unsigned char cmd)
{
    //    STEPS:
    Printdata(cmd);                        //     1.Pass the 8-bit data to the datalines of LCD.
    CLEAR_BIT(GPIO_PORTA_DATA_R,3);         //     * 2.Turn off the R/W to select WRITE mode on the LCD
    CLEAR_BIT(GPIO_PORTA_DATA_R,2);           //     * 3.Turn off the RS to select COMMAND mode on the LCD
    SET_BIT(GPIO_PORTA_DATA_R,4);           //     * 4.Turn on the EN pin on the LCD
    delay_ms(5);                            //     * 5.Wait for 5ms.
    CLEAR_BIT(GPIO_PORTA_DATA_R,4);         //     * 6.Turn off the EN pin on the LCD
}

void lcd_string(unsigned char *str)
{
    char i;
    for(i=0;str[i]!=0;i++){
        lcd_data(str[i]);
    }
}

void lcd_init(void)
{
    lcd_cmd(0x38);    //    8-bit mode using 16x2 LCD
    delay_ms(20);
    lcd_cmd(0x06);   //    Auto-incrementing the cursor when the LCD prints the data
    delay_ms(20);
    lcd_cmd(0x0F);    //    cursor on, blinking on, and display on.
    delay_ms(20);
    lcd_cmd(0x01);    //    clear screen
}
void lcd_moveCursor(uint8_t x,uint8_t y)
{
    lcd_cmd(0x80 + x + (y*40));
}

void Printdata(unsigned char data) /*data = 8-bit hexadecimal data*/
{

    /*zeroth bit = D0 = PA7*/
    if((data&0x01)==0x01)   {GPIO_PORTA_DATA_R  |= (1<<7);}
    else                    {GPIO_PORTA_DATA_R &=~(1<<7);}
    /*first bit = D1 = PA6*/
    if((data&0x02)==0x02)   {GPIO_PORTA_DATA_R  |= (1<<6);}
    else                    {GPIO_PORTA_DATA_R &=~(1<<6);}
    /*second bit = D2 = PA5*/
    if((data&0x04)==0x04)   {GPIO_PORTA_DATA_R  |= (1<<5);}
    else                    {GPIO_PORTA_DATA_R &=~(1<<5);}
    /*third bit = D3 = PB4*/
    if((data&0x08)==0x08)   {GPIO_PORTB_DATA_R  |= (1<<4);}
    else                    {GPIO_PORTB_DATA_R &=~(1<<4);}
    /*fourth bit = D4 = PE5*/
    if((data&0x10)==0x10)   {GPIO_PORTE_DATA_R  |= (1<<5);}
    else                    {GPIO_PORTE_DATA_R &=~(1<<5);}
    /*fifth bit = D5 = PE4*/
    if((data&0x20)==0x20)   {GPIO_PORTE_DATA_R  |= (1<<4);}
    else                    {GPIO_PORTE_DATA_R &=~(1<<4);}
    /*sixth bit = D6 = PB1*/
    if((data&0x40)==0x40)   {GPIO_PORTB_DATA_R  |= (1<<1);}
    else                    {GPIO_PORTB_DATA_R &=~(1<<1);}
    /*seventh bit = D7 = PB0*/
    if((data&0x80)==0x80)   {GPIO_PORTB_DATA_R  |= (1<<0);}
    else                    {GPIO_PORTB_DATA_R &=~(1<<0);}
}
