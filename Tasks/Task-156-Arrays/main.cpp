#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;
double value =0 ;

int main()
{
    unsigned short samples[100];

    for (unsigned int m=0; m<100; m++) {
        printf("%X ", samples[m]);
    }
    

    // Automatic headlamp 
    while (true) {

        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            samples[m] = ldrVal;
            value = value + ldrVal ;
            wait_us(10000);          // 10ms
        }

        // TASK a. Calculate the average value in samples
        int avrVal = value / 100 ;
        printf ("\nthe average is %X \n", avrVal ) ;
        printf ("in decimal it is %d \n", avrVal );
        // TASK b. Display to 1dp
        double avrVald = value / 100 ;
        printf ("with decimals it is %f\n", avrVald ) ;
        // TASK c. Switch green LED on when dark;
    if(avrVal > 35000 ){
        greenLED=1;
    }
    else{greenLED=0;}
    break;

    }  
}


