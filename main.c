/*
 * main.c
 */
#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "M4MemMap.h"

void Delay(void)

{
    volatile long i=0;

for (i=0;i<300000;i++);
}

int main(void) {
    uint8_t Button1=0,Button2=0;
        GPIO_Init();
        while(1)
        {
            GPIO_Read(3,&Button1);
            GPIO_Read(4,&Button2);
            while( Button1==0x00)
                {
                        GPIO_Write(0,0xFF);
                        Delay();
                        GPIO_Write(0,0x00);
                        GPIO_Write(1,0xFF);
                        Delay();
                        GPIO_Write(1,0x00);
                        GPIO_Write(2,0xFF);
                        Delay();
                        GPIO_Write(2,0x00);
                        GPIO_Read(4,&Button2);
                        if (Button2==0x00)
                        {break;}

                }
            while( Button2==0x00)
                {
                   GPIO_Write(0,0x00);
                   GPIO_Write(1,0x00);
                   GPIO_Write(2,0x00);
                   GPIO_Read(3,&Button1);
                   if (Button1==0x00)
                   {break;}
                 }
        }
}
