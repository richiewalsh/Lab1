#include "mbed.h"
#include <cstdio>
/*
I tried moving the btn.fall(&fall) around in the main but it either didnt get rid of 
the error or caused the loop to never be entered.
By taking the printf statement out of the fall function and putting the btn.fall(&fall)
back at the start of the main, I get the desired output.
*/
// Initialise variables
InterruptIn btn(PC_13);
volatile int flag = 0; //Volatile necessary so that flag value is consistent and can be changed anywhere in the code 

// define function for when button has been pressed
void fall(){
// cause activation of the if loop in main when function has been triggered
flag = 1;

}

// main() runs in its own thread in the OS
int main()
{
    // Call function when button is pressed
    btn.fall(&fall);
    while (true) {
        // enter loop when flag gets set by fall function
        if(flag == 1){

            printf("Button has been pressed.\r\n");
            // reset flag
            flag = 0;
        }

    }
}

