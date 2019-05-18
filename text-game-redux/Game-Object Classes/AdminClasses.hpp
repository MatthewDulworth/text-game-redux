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

// ------------------------------------------------------------------------------------------------------
// Admin Classes
// ------------------------------------------------------------------------------------------------------

// ------------------------------------------------
// Action
// ------------------------------------------------
class Action : public Base {
public:
    // getters
    string derivedType();
};


// ------------------------------------------------
// Direction
// ------------------------------------------------
class Direction : public Base {
public:
    // getters
    string derivedType();
};


// ------------------------------------------------
// Number
// ------------------------------------------------
class Number : public Base {
private:
    string synonym;
public:
    // setters
    void setSynonym(string synonym);
    // getters
    string getSynonym();
    string derivedType();
};

#endif /* Direction_hpp */
