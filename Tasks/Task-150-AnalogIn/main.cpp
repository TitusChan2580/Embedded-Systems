#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//led pins
DigitalOut red(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellow(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut green(TRAF_GRN1_PIN);     //Green Traffic 1



//Fun output stuff
LCD_16X2_DISPLAY disp;
Buzzer buzz;
LatchedLED ledDisp(LatchedLED::STRIP);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
AnalogIn ldr(AN_LDR_PIN);
AnalogIn mic(MIC_AN_PIN);

int main()
{

    //Test LED Bar Display
    ledDisp.enable(true);

    ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;

    ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;
    
    ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }     
    ledDisp = 0;


    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        unsigned short lightVal = ldr.read_u16();
        signed int micVal   = mic.read_u16(); 

        //Write to terminal
        printf("--------------------------------\n");
        printf("Potentiometer: %d\n", potVal);
        if (potVal > 0x8000){
            yellow = 1;
        }
        else{
            yellow = 0;
        }
        printf("Light Dependant Resistor: %d\n", lightVal);
        if (lightVal < 2000){
            green = 1 ;
        }
        else{
            green = 0 ;
        }
        int count = micVal - 0x8000 ;
        printf("Microphone: %d\n", count);   
        if (micVal > 0x8000){
            red = 1;
        }
        else{
            red=0 ;
        }

        //Wait 0.25 seconds
        wait_us(500000);

    }
}

//when u shine a light at the ldr the vaule shown on the screen and it decreaces with more light so down so the resistance goes down
//when u sturn the poiteniomter the falue increaces
//when u brush the microphone the value increaces
//i think the reason y we dont get constant values is because it travels as a wave there for like a wave it has ups and downs
//when light is shone on the ldr it  the resistance goes downtherefore the brighter it is the lower the value and the darker it si the higher the value
//able to obtain 0 and ffff but it is basiclly impossible to get  to 8000
//when the room the value of the microphone is close to 0
// the smallest value i got was 13
//able to see it wavering between a negative and a possitive value
// am able to make the led flicker