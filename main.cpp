/**************************************
* Name: Bryson Shane
* Assignment: 4
* Purpose of file: This file is used to test
* our Int Stack datastructure. It will test the
* pop peek push isempty function.
***************************************/

#include "main.h"

int main() {
    /*********************************
    * This is the main function of the program.
    * The program creates a int stack, runs through a loop
    * that generates a random choice each loop and runs it
    * through a switch case acting upon that choice. It also
    * generates a random value to store into the stack if it's valid.
    *
    * @attrib TEST_RUN: the decision of how many test runs you want run. This is a constant
    * for convience.
    * 
    * @attrib stack: our int stack that is created.
    * @attrib rMultiplier: randomly executes the case statements random multiple times to test
    * counters of overflow count and underflow count.
    * 
    * @attrib randChoice: the random choice that is made in the switch case
    * @attrib randValue: the random value that will be stored in the stack
    * if case 1 is chosen with the random choice.
    * 
    * @attrib underCount: counter for Underflows
    * @attrib overCount: counter for Overflows
    * 
    * @return 0: shows successful execution of the program.
    *
    * @note srand(time(0)): This is setting the seed of the random function
    * to the time of the computer. So everytime you run the program, it generates
    * random numbers each time.
    *********************************/

    srand(time(0));

    const int TEST_RUN = 12;

    IntStack stack;

    int rMultiplier;
    int randChoice;
    int randValue;
    
    int underCount;
    int overCount;

    /********************************
    * Wanting to go a little more detail in this loop.
    * The main purpose of this loop is automate testing.
    * The loop starts at 0 and keeps going until it exceeds the TEST_RUN assigned amount.
    * Each run it will assign the randChoice a value of 1-4 which will determine which case will be used
    * in the switch statement since there's only 4 choices.
    * randValue is given a new value each loop iteration too a value ranging through 1-100 to be stored in the stack.
    * the counters are intialized to 0 each test to seperate results.
    * Case 1 test for a overflow, Case 2 test for a underflow, Case 3 test for a normal stack.
    *********************************/

    for (int currRun = 0; currRun < TEST_RUN; currRun++) {
        randChoice = (rand() % (4 - 1 + 1)) + 1;
        rMultiplier = rand() % 5 + 2;
        
        underCount = 0;
        overCount = 0;

        std::cout << "Test: " << currRun + 1 << std::endl << std::endl;
        std::cout << "Current Stack Size: " << stack.size() << std::endl << std::endl;

        switch (randChoice) {
        case 1:

            for (int fill = 0; fill < MAX_SIZE * rMultiplier; fill++)
            {
                randValue = (rand() % (100 - 1 + 1)) + 1;
                if (stack.push(randValue)) {
                    std::cout << "Value Pusheded: " << randValue << std::endl;
                }
                else {
                    std::cout << "Error: Stack Overflow." << std::endl;
                    overCount++;
                }
            }

            try {
                std::cout << "Value Popped: " << stack.pop() << std::endl << std::endl;
            }
            catch (int e) {
                std::cout << "Error, Stack Underflow." << std::endl << std::endl;
                underCount++;
            }

            try {
                std::cout << "Top Value: " << stack.peek() << std::endl;
            }
            catch (int e) {
                std::cout << "Error, Stack Underflow." << std::endl;
                underCount++;
            }

            if (stack.isEmpty()) {
                std::cout << "The stack is empty." << std::endl;
            }
            else {
                std::cout << "The stack is not empty." << std::endl;
            }

            std::cout << "Total amount of Overflows: " << overCount << std::endl;
            std::cout << "Total amount of Underflows: " << underCount << std::endl << std::endl;
           
            break;

        case 2:
        {
            for (int popped = 0; popped < MAX_SIZE * rMultiplier; popped++) {
                try {
                    std::cout << "Value Popped: " << stack.pop() << std::endl;
                }
                catch (int e) {
                    std::cout << "Error, Stack Underflow." << std::endl;
                    underCount++;
                }
            }

            try {
                std::cout << "Top Value: " << stack.peek() << std::endl;
            }
            catch (int e) {
                std::cout << "Error, Stack Underflow." << std::endl;
                underCount++;
            }


            if (stack.isEmpty()) {
                std::cout << "The stack is empty." << std::endl;
            }
            else {
                std::cout << "The stack is not empty." << std::endl;
            }

            randValue = (rand() % (100 - 1 + 1)) + 1;

            if (stack.push(randValue)) {
                std::cout << "Value Pusheded: " << randValue << std::endl;
            }
            else {
                std::cout << "Error: Stack Overflow." << std::endl;
                overCount++;
            }

            std::cout << "Total amount of Overflows: " << overCount << std::endl;
            std::cout << "Total amount of Underflows:  " << underCount << std::endl;
            break;
        }

        case 3:
            for (int fill = 0; fill < MAX_SIZE / 2; fill++)
            {
                randValue = (rand() % (100 - 1 + 1)) + 1;
                if (stack.push(randValue)) {
                    std::cout << "Value Pusheded: " << randValue << std::endl;
                }
                else {
                    std::cout << "Error: Stack Overflow." << std::endl;
                    overCount++;
                }
            }
      
            try {
                std::cout << "Value Popped: " << stack.pop() << std::endl << std::endl;
            }
            catch (int e) {
                std::cout << "Error, Stack Underflow." << std::endl << std::endl;
                underCount++;
            }

            try {
                std::cout << "Top Value: " << stack.peek() << std::endl;
            }
            catch (int e) {
                std::cout << "Error, Stack Underflow." << std::endl;
                underCount++;

            }

            if (stack.isEmpty()) {
                std::cout << "The stack is empty." << std::endl;
            }
            else {
                std::cout << "The stack is not empty." << std::endl;
            }

            std::cout << "Total amount of Overflows: " << overCount << std::endl;
            std::cout << "Total amount of Underflows: " << underCount << std::endl << std::endl;

            break;
        }
    }

    return 0;
}
    
