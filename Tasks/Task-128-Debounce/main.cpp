#include "mbed.h"

DigitalIn ButtonA(PG_0);                    //Button A
DigitalIn BlueButton(USER_BUTTON);          //Blue user button
DigitalOut redLED(PC_2);                    //Red Traffic 1

int main()
{
    redLED = 0;

    while (true) {

        //Wait for a press
        while (BlueButton==0) { };
        wait_us(5000000);

        //Toggle LED
        redLED = !redLED;

        //Wait for release
        while (BlueButton==1) { };
        wait_us(5000000);
    }
}

//the code just turn on light when a is pressed
// works like 99% of the time for button a but for blue button it only works like 70% of the time
//works like 100 % of the time if there is a 100ms delay
//does work like 50% of the time when it  1 us
//it takes to long to work when it at 5s