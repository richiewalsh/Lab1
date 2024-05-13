#include "mbed.h"
#include <cstdio>
/*
Error in output:
++ MbedOS Error Info ++
Error Status: 0x80010133 Code: 307 Module: 1
Error Message: Mutex: 0x200015FC, Not allowed in ISR context
Location: 0x8009371
Error Value: 0x200015FC
Current Thread: main Id: 0x20001DB8 Entry: 0x8006943 StackSize: 0x1000 StackMem: 0x20000580 SP: 0x2009FF4C 
For more info, visit: https://mbed.com/s/error?error=0x80010133&tgt=B_L4S5I_IOT01A
-- MbedOS Error Info --

*/
// Initialise variables
InterruptIn btn(PC_13);
volatile int flag = 0; //Volatile necessary so that flag value is consistent and can be changed anywhere in the code 

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

