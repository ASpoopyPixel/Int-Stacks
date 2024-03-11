/********************************
* Name: Bryson Shane
* Assignment: 4
* Purpose of the file:
* This contains the int stack datastructure class.
********************************/

#include "stack.h"

IntStack::IntStack() {
    /*********************************
    * This is the constructor for the Intstack.
    * It takes no parameters and intializes 
    * the top value to -1. This indicates the
    * stack is empty and will cause an underflow
    * in certain scenarios.
    * 
    * @attrib top: the current position of the stack.
    **********************************/
    
    top = -1;
}

IntStack::~IntStack() {
    /**********************
    * Deconstructor
    ***********************/
}

bool IntStack::push(int item) {
    /**************************
    * This is the push method for the for the stack.
    * If the value doesn't execeed the max_size of the stack, it will add
    * the value to the stack and return the pushed boolean value true. If it exceeds
    * it will throw an exception of the pushed value being false.
    * 
    * @param item: the value that's trying to be pushed into the stack
    * @attrib pushed: shows if the value was pushed or not
    * @return pushed: returns pushed being true if it successfully pushed the value.
    * @throw pushed: if the value wasn't pushed, pushed value will be false and it throws
    * and exception.
    ***************************/
    
    bool pushed = false;
    
    if (top < MAX_SIZE - 1) {
        stack[++top] = item;
        pushed = true;
    }
        return pushed;
    
}

int IntStack::pop() {
    /******************************
    * This is the pop method for the stack.
    * The method checks to to see if the stack is empty by calling
    * the isEmpty() method which checks if top is = -1 and if it is 
    * it returns true and will throw top which should have the value 
    * of -1 giving an exception of an Underflow.
    * If the isEmpty function returns false, it remove the value on the top and
    * return it.
    * 
    * @attrib topItem: stores the top value to be returned
    * @return topItem: returns the value on the top.
    * @throw top: Used to show a stack underflow. top will be the value of -1
    * if the stack is empty.
    *******************************/
    
    int topItem;

    if (!isEmpty()) {
        topItem = stack[top];
        top--;
        
    }
    else {
        throw top;
    }
    
    return topItem;
}

int IntStack::peek() {
    /*****************************
    * This is the peek method of a function.
    * This method checks to see what value is at the top position
    * of the stack and return it. If the stack is empty, the 
    * peek method will throw top which should have the value of -1 
    * meaning the stack is empty.
    * 
    * @return stack[top]: returns the top value of the stack.
    * @throw top: throws an exception if the stack is empty. 
    * it will have a value of -1.
    ******************************/
    
    if (isEmpty()) {
        throw top;
    }
    return stack[top]; 
}

bool IntStack::isEmpty() {
    /**************************
    * This method checks to see if the stack is empty.
    * Very simple of checking to see if the top value = -1
    * If it does the it returns a bool value of true if not
    * then the bool value is false.
    * 
    * @return top == -1: Checks if the stack is empty and returns true if it is
    * otherwise returns false.
    ***************************/
    
    return top == -1;
}

int IntStack::size() {
    /****************************
    * This is the stack size method.
    * While this wasn't needed in the program, it helped
    * severely in testing the program.
    * This is used to check the current size of the stack.
    * 
    * @return top + 1: adds one because the stack starts at 0 and returns
    * the current amount of objects in the stack.
    *****************************/
    
    return top + 1; 
}