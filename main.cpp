//
//  main.cpp
//  LongestSequence
//
//  Created by Kirk Lopez on 11/8/20.
//

#include "StackArray.hpp"
#include "LongSeq.hpp"

int main() {
    int size = 100; // Size of the array
    int* array = new int[size](); //Create array to pass
    for(int i=1;i<size;i++){
        *(array+i) = i; // Fill the array
    }
    *(array+25) = 0; // Add places to break up the rising sequence
    *(array+75) = 0;
    *(array+10) = 0;
    
    LongSeq test = LongSeq(); // Create the object to find the sequence
    test.findLongest(array, size); // Function to find the sequence
    test.longest->printViaPop(); // Print the stack
    return 0;
}
