/*
     -----------------------------------Author:-Murtaza-------------------------------
     This project uses the TivaWare for C Series Peripheral Driver Library 
     The latest library can downloaded from the ti website 
*/
															
#include <stdint.h>
#include "tm4c1294ncpdt.h"
#include "gpio.h"

void delay(void);

int main(void)
{
    volatile uint32_t ui32Loop;

    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R9;     // enable clock gating for port K  
    ui32Loop = SYSCTL_RCGCGPIO_R;               // do a dummy read to insert a few cycles

    GPIO_PORTK_DIR_R |= GPIO_PIN_0;             // set the pin PK0 as output
    GPIO_PORTK_DEN_R |= GPIO_PIN_0;             // enable the pin PK0

    while(1)
    {
        GPIO_PORTK_DATA_R |= GPIO_PIN_0;        // Digital write high to PK0
        delay();
        GPIO_PORTK_DATA_R &= ~(GPIO_PIN_0);     // Digital write low to PK0
        delay();
    }
}

void delay()
{
	uint32_t ui32Loop;
   for(ui32Loop = 0; ui32Loop < 400000; ui32Loop++)
   {
   }
}