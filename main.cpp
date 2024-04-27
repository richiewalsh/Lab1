#include "mbed.h"
#include <cstdio>

// Initialise variables
InterruptIn btn(PC_13);
volatile int flag = 0;

// define function for when button has been pressed
void fall(){

printf("Button has been pressed\n");
// cause activation of the if loop in main when function has been triggered
flag = 1;

}

// main() runs in its own thread in the OS
int main()
{
    // Call function when button is pressed
    btn.fall(&fall);
    while (true) {

        if(flag == 1){

            printf("Button has been pressed\n");
            // reset flag
            flag = 0;
        }

    }
}

