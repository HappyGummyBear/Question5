//
//  StackArray.hpp
//  LongestSequence
//
//  Created by Kirk Lopez on 11/8/20.
//

#ifndef StackArray_hpp
#define StackArray_hpp
#include <iostream>

class StackArray{
public:
    int size;
    int CAPACITY;
    int* topOfStack;
    
    StackArray(); // Default constructor
    StackArray(int c); // Constructor to set capacity
    
    void setSize(int s); // Set size
    int getSize(); // Get size
    
    void growStack(); // Function to double stack capacity and copy array to new stack
    void push(int p); // Add to the stack
    int pop(); // Remove top item from the stack
    void popOff(); // Function to pop all the elements out of the stack
    void printStack(); // Print the stack using a loop
    void printViaPop(); // Print the stack using pop function. Will empty the stack
};
#endif /* StackArray_hpp */
