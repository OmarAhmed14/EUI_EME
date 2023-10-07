

/**
 * main.c
 */

#include "DIO.h"

int main(void)
{
    Port_Init();

    while (1){
        Dio_WritePort(5, 0x0E);
    }

}
