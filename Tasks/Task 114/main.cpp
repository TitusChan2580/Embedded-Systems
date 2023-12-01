#include "mbed.h"
DigitalOut red(PC_2,1);
DigitalOut yellow(PC_3,1);
DigitalOut green(PC_6,1);
// main() runs in its own thread in the OS
int main()
{
    red = 1 ;
    yellow = 1 ;
    green = 1 ;
    wait_us (1000000) ;
    red = 0 ;
    yellow = 0 ;
    green = 0 ;

    while (true) {
        red = 1 ;
        wait_us (1000000) ;
        yellow = 1 ;
        wait_us (1000000) ;
        red = 0 ;
        yellow = 0 ;
        green = 1 ;
        wait_us (1000000) ;
        green = 0 ;
        int count = 1 ;
        while (count <= 4) {
            yellow = 1 ;
            wait_us (250000) ;
            yellow = 0 ;
            wait_us (250000) ;
            count = count + 1 ;
        }

    }
}
//test
