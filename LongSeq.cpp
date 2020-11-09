//
//  LongSeq.cpp
//  LongestSequence
//
//  Created by Kirk Lopez on 11/8/20.
//

#include "LongSeq.hpp"

LongSeq::LongSeq(){} // Default constructor

void LongSeq::endSearch(){
    if(count > longest->size){ // If the count is greater than the stack length then replace the longest stack
        longest->popOff(); // Pop all the elements out of the stack
        while(current->size > 0){ // Pop the elements from the current stack to the longest stack
            longest->push(current->pop());
        }
        count = 0; // Make count 0
    }
    else{ // If count is too small then empty the stack and print message
        std::cout << "Current stack too small" << std::endl;
        current->popOff(); // Empty stack
        count = 0; // Make count 0
        return; // End function
    }
}
void LongSeq::findLongest(int* array, int size){ // Function to find longest sequence in an array (using stacks)
    for(int i=0;i<size;i++){ // Push all the objects into the stack
        if(count == 0){ // If stack is empty, push first element into the stack
            current->push(*array+i);
            ++count;
        }
        else if(*(array+i) >= *(current->topOfStack+current->size-1)){ // Add if element is greater than the top of the stack
            current->push(*(array+i));
            ++count;
        }
        else if(*(array+i) < *(current->topOfStack+current->size-1)){ // If element is less than top of stack, stop looping
            endSearch(); // End the search at this element and check the stack
        }
    }
    endSearch(); // When loop ends check stack incase stack is the longest sub sequence
    std::cout << std::endl;
    std::cout << "Longest sub sequence is: " << longest->size << std::endl;
}

