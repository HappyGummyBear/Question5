//
//  StackArray.cpp
//  LongestSequence
//
//  Created by Kirk Lopez on 11/8/20.
//

#include "StackArray.hpp"
StackArray::StackArray(){
    size = 0; // set size to 0
    CAPACITY = 10; // Default capacity to 10
    topOfStack = new int[CAPACITY];
}
StackArray::StackArray(int c){
    if(c > 0){ // If capacity is greater than 0 then create the object
        size = 0; // Size is zero
        CAPACITY = c; // Capacity set to c
        topOfStack = new int[CAPACITY]; // Point stack pointer to an array of capacity size
    }else{ // If size is smaller than 0 print message
        std::cout << "Invalid size. Size must be greater than 0" << std::endl;
    }
}

void StackArray::setSize(int s){
    if(s > 0){
        size = s;
    }else{
        std::cout << "Size must be bigger than 0" << std::endl;
    }
}
int StackArray::getSize(){
    return size;
}

void StackArray::growStack(){
    CAPACITY = CAPACITY*2; // Double capacity size
    int* temp = new int[CAPACITY]; // Create a temp object to hold new array
    for(int i=0;i<size;i++){ // Loop through current array
        *(temp+i) = *(topOfStack+i); // Copy from current array to new array
    }
    delete[] topOfStack; // Delete current array after copy
    topOfStack = temp; // Point stack to new array
    temp = nullptr; // Make temp point to nullptr
}
void StackArray::push(int p){
    if(size == CAPACITY-1){ // If array is about to be full
        growStack(); // Grow array
    }
    *(topOfStack+size) = p; // Add p to the stack
    ++size; // Add 1 to size
}
void StackArray::popOff(){ // Function to empty the stack
    if(size == 0){ // If stack is empty print message
        std::cout << "Stack is empty. Cannot pop. " << std::endl;
        return;
    }
    while(size != 0){ // Loop through stack till its empty
        *(topOfStack+size) = 0; // Set popped location to 0
        --size; // Move size down the stack
    }
}
int StackArray::pop(){
    if(size == 0){ // If stack is empty print message
        std::cout << "Stack is empty. Cannot pop. " << std::endl;
        return -1;
    }
    int *temp = (topOfStack+size-1); // Pointer to hold top item in top of the stack
    *(topOfStack+size) = 0; // Set popped location to 0
    --size; // Move size down the stack
    return *(temp); // Return popped item from temp pointer
}

void StackArray::printStack(){
    if(size == 0){ // If stack is empty, print message
        std::cout << "Stack is empty. There is nothing to print." << std::endl;
        return;
    }
    for(int i=size-1;i>=0;i--){ // Loop through stack and print items from the stack
        std::cout << *(topOfStack+i) << " ";
    }
    std::cout << std::endl;
}

void StackArray::printViaPop(){
    if(size == 0){ // If stack is empty print message
        std::cout << "Stack is empty. There is nothing to print." << std::endl;
        return;
    }
    while(size != 0){ // While there are items in the stack keep looping
        std::cout << pop() << " "; // Pop item from the stack
    }
    std::cout << std::endl;
    std::cout << "Stack is now empty" << std::endl; // When popping is finished print message
}
