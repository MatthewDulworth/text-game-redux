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
    void overridden();
};


// ------------------------------------------------
// Direction
// ------------------------------------------------
class Direction : public Base {
public:
    // overridden
    void overridden();
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
    // overridden
    void overridden();
};

// ------------------------------------------------
// Number
// ------------------------------------------------
class Word : public Base {
public:
    // overridden
    void overridden();
};

#endif /* Direction_hpp */
