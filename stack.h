/********************************
* Name: Bryson Shane
* Assignment: 4
* Purpose of the file: Contains the prototypes and constructors/deconstructors
* for the int stack datastructure. 
*********************************/
#ifndef STACK_CLASS_H
#define STACK_CLASS_H
#define MAX_SIZE 10
class IntStack {
    /**********************************
    * This is the class defines the Intstack datastructure.
    * contains only only constructor.
    * 
    * @attrib MAX_SIZE: the size of the intstack.
    * @attrib stack[MAX_SIZE]: the creation of the intstack, size
    * is declared by MAX_SIZE which can be easily changed.
    * 
    * @attrib top: declares the highest position of the stack.
    ***********************************/
public:
    
    /**************************
    *Constructors/Deconstructors
    ***************************/

    IntStack();
    ~IntStack();

    /**************************
    * Setters/Mutators
    ***************************/
    bool push(int);
    int pop();
    
    /**************************
    * Getters
    ***************************/
    int peek();
    bool isEmpty();
    int size();

private:
    int stack[MAX_SIZE];
    int top; 
};

#endif // !STACK_CLASS_H
