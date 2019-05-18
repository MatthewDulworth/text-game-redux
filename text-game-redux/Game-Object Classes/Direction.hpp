//
//  Direction.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#ifndef Direction_hpp
#define Direction_hpp

#include "Base.hpp"
#include <vector>

// ------------------------------------------------
// Direction
// ------------------------------------------------
class Direction : public Base {
public:
    string derivedType();
};

// ------------------------------------------------
// Number
// ------------------------------------------------
class Number : public Base {
private:
    string synonym;
public:
    string derivedType();
    void setSynonym(string synonym);
    string getSynonym();
};

#endif /* Direction_hpp */
