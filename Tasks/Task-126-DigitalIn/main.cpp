#include "mbed.h"
DigitalIn ButtonC(PG_2, PinMode::PullDown); //Button C
DigitalIn ButtonD(PG_3, PinMode::PullDown); //Button D
DigitalIn ButtonB(PG_1);// button B
DigitalIn ButtonA(PG_0); //Button A
DigitalOut redLED(PC_2); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    int btnB;
    //turn off red led
    redLED = 0 ; 
    int btnA;
    // Turn OFF the red LED
    redLED = 0;

    while (true) {
    
        // Wait for the button to be pressed
        do {
            btnA = ButtonA&&ButtonB&&ButtonC&&ButtonD; //Read button A
        } while (btnA == 0);


        //Toggle the red LED
        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);

        // Wait for the button to be released
        do {
            btnA = ButtonA&&ButtonB&&ButtonC&&ButtonD; //Read button A
        } while (btnA == 1);

        //Wait for noise to settle
        wait_us(10000);
    }
}

// whn button a is pressed a redlight is turned on