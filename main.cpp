#include "mbed.h"

// Initialise button
InterruptIn btn(PC_13);

// define function for when button has been pressed
void fall(){

printf("Button has been pressed");

}

// main() runs in its own thread in the OS
int main()
{
    while (true) {

    }
}

