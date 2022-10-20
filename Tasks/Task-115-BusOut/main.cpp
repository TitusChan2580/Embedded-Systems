#include "mbed.h"
#define WAIT_TIME_MS 1000 


 //DigitalOut redLED(PC_2,1);
 //DigitalOut yellowLED(PC_3,1);
 //DigitalOut greenLED(PC_6,1);


// for 0 1 2 3 4 5 6 7 they all increace in binary units



//BusOut lights(PC_2, PC_3, PC_6);
BusOut lights(PC_2, PC_3, PC_6, PB_0, PB_7, PB_14);

int main()
{
    //All OFF
    lights = 0b000;

    while (true)
    {
        int count = 31;
        while (count >= 0) 
        {
            printf("count = %d\n", count);
            lights = count;
            wait_us(250000);

            count = count - 1;
        }
    }
}