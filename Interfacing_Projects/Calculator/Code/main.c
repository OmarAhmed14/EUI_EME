#include "DIO.h"
#include "lcd.h"
/**
 * LCD PINOUT:
 * ***********
 * RS= PA2
 * RW= PA3
 * E= PA4
 *
 * D0= PA7
 * D1= PA6
 * D2= PA5
 * D3= PB4
 * D4= PE5
 * D5= PE4
 * D6= PB1
 * D7= PB0
 * **/

void Printdata(unsigned char data);
void delay_ms(unsigned int n);
void delay_us( unsigned int n);
void GPIO_PORTD_handler (void);
void KeyPad_Init (void);
uint32_t Write_Num_LCD (uint8_t index);
void Write_Operation_LCD (void);
void calculate(void);

uint8_t ROW=0, COL=0 ,i,flag=0,PressedBTN=0xFF,INT;
uint32_t Num1,Num2,Result;
uint8_t index=0;

void GPIO_PORTD_handler (void)
{
    delay_ms(200);//Debouncing Delay

    INT =GPIO_PORTD_RIS_R;

    COL =i;
    flag =1;

    GPIO_PORTD_ICR_R = 0xF;
}
double result;
//uint32_t x=1;
extern uint8_t KeyPad[4][4];

void main(void)
{
    /*Initialize the Keypad and enable global interrupts.*/
    __asm("    CPSIE I");
    KeyPad_Init ();
    /*Initialize the required pins for the LCD*/
    DIO_Init(PORTA,0xFC,0x00);
    DIO_Init(PORTB,0x13,0x00);
    DIO_Init(PORTE,0x3F,0x00);
    delay_ms(50);
    lcd_init();
    lcd_cmd(0x80); //Move Cursor to top left

    while(1){
        while (!flag)
        {

            for (i=0;i<4;i++)
            {
                GPIO_PORTD_IM_R &=~ 0xF;
                GPIO_PORTE_DATA_R = ~(0x01<<i);
                GPIO_PORTD_IM_R |=0xF;
                delay_us(100);
            }
        }

        switch (INT)
        {
        case 0x1:
            ROW=0;
            break;
        case 0x2:
            ROW=1;
            break;
        case 0x4:
            ROW=2;
            break;
        case 0x8:
            ROW=3;
            break;
        }

        PressedBTN =KeyPad[ROW][COL];


       if (!(PressedBTN == '+' || PressedBTN == '-' || PressedBTN == '*' || PressedBTN == '/'||PressedBTN == '=')){
           Write_Num_LCD (index);
       }

       else if((PressedBTN == '+' || PressedBTN == '-' || PressedBTN == '*' || PressedBTN == '/' )){
           Write_Operation_LCD();
       }

       else if(PressedBTN == '='){
           calculate();
           delay_ms(5000);//Delay for 5 seconds
           lcd_cmd(0x01);//Clear the display
       }
        flag =0;

    }
}





void delay_ms(unsigned int n)
{
    int i,j;
    for(i=0;i<n;i++){for(j=0;j<3180;j++);}
}

void delay_us( unsigned int n)
{
    int i,j;
    for(i=0;i<n;i++){for(j=0;j<3;j++);}
}

