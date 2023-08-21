/*
 * lcd.h
 *
 *  Created on: Aug 20, 2023
 *      Author: EUI-Support
 */

#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
void Printdata(unsigned char data);
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char cmd);
void lcd_string(unsigned char *str);
void lcd_moveCursor(uint8_t x,uint8_t y);
void lcd_init(void);
void delay_ms(unsigned int n);
void delay_us( unsigned int n);



#endif /* LCD_H_ */
