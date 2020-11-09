//
//  LongSeq.hpp
//  LongestSequence
//
//  Created by Kirk Lopez on 11/8/20.
//

#ifndef LongSeq_hpp
#define LongSeq_hpp

#include <stdio.h>
#include "StackArray.hpp"
class LongSeq{
public:
    StackArray* longest = new StackArray(); // Stack that will hold the longest sub sequence
    StackArray* current = new StackArray(); // Stack that will be used to check the current sub sequences
    int count = 0; // Count of the number of elements in the current stack
    
    LongSeq(); // Default constructor
    
    void endSearch(); // Function to stop the search and check if sequence is the longest
    void findLongest(int* array, int size); // Function that takes in the array and size of the array that will be checked
};
#endif /* LongSeq_hpp */
