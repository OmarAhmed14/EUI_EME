#include "DIO.h"
#include "systick_timer.h"
#include "lcd.h"

uint32_t MIN=0;
extern uint32_t SEC;


int main(void)
{
    __asm(" CPSIE I "); /*ENABLES GLOBAL INTERRUPTS*/

    NVIC_EN0_R |= (1<<30); //ENABLES INTERRUPT NUMBER 30 (PORTF)
    /*GPIO INITIALIZATION*/
    DIO_Init(PORTA,0xFC,0x00);
    DIO_Init(PORTB,0x13,0x00);
    DIO_Init(PORTE,0x3F,0x00);
    DIO_Init(PORTF,0X0E,0X11);
    /*GPIO Port F Interrupt Enable*/
    DIOPortFInterrupt(); 
    /*LCD INITIALIZATION*/
    lcd_init();
    lcd_moveCursor(0,0);
    /*SYSTICK TIMER INITIALIZATION*/
    ST_SetReloadValue(0XF423FF); /*RELOAD TIME=15999999 clocks = 1 sec*/
    ST_Init();
    lcd_string("00:00");
    while(1){
        if(SEC>=60){
            SEC=0;
            MIN++;
            lcd_clearScreen();
            lcd_string("00:00");
            lcd_moveCursor(0,0);
        }
        if(MIN>9){
            lcd_moveCursor(0,0);
            lcd_printLong(MIN);
        }
        else if(MIN>0 && MIN<=9){
            lcd_moveCursor(1,0);
            lcd_printLong(MIN);
        }

        lcd_moveCursor(2,0);
        lcd_string(":");
        if(SEC>9 && SEC<60){
            lcd_moveCursor(3,0);
            lcd_printLong(SEC);
            lcd_string(" ");
        }
        else if(SEC>0 && SEC<=9){
            lcd_moveCursor(4,0);
            lcd_printLong(SEC);
            lcd_string(" ");
        }
    }
}
