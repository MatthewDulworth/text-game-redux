//
//  OffsetArray.h
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/16/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef OffsetArray_h
#define OffsetArray_h

#include <iostream>
#include <stdexcept>
#include <string>


// array class with offset starting index
// source: https://stackoverflow.com/questions/2289548/array-indexing-starting-at-a-number-not-0

// template class
template <class T, int lower, int upper>
class OffsetArray {
private:
    // array of size upper minus lower
    T data[upper-lower];
    
public:
    // overloaded index [] operator
    T &operator[](int index) {
        if (index < lower || index >= upper)
            throw range_error("Index out of range");
        return data[index-lower];
    }
    // idk fam
    T* begin() {
        return data;
    }
    T* end() {
        return data + (upper-lower);
    }
};

#endif /* OffsetArray_h */
