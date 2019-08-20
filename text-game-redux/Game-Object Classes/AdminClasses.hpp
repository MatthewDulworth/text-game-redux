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
#include <string>
#include <vector>

// ------------------------------------------------------------------------------------------------------
// Admin Classes
// ------------------------------------------------------------------------------------------------------

// ------------------------------------------------
// Action
// ------------------------------------------------
class Action : public Base {
private:
    typedef Base super;
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
// Direction
// ------------------------------------------------
class Direction : public Base {
private:
    typedef Base super;
public:
    // overridden
    void overridden();
};


// ------------------------------------------------
// Number
// ------------------------------------------------
class Number : public Base {
private:
    typedef Base super;
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
// CommandWord
// ------------------------------------------------
class CommandWord : public Base {
private:
    typedef Base super;
public:
    // overridden
    void overridden();
};

// ------------------------------------------------
// Word
// ------------------------------------------------
class Word {
private:
    int code;
    vector<string> synonyms;
public:
    void setCode(int code);
    void addSynonym(string word);
    int getCode();
    string getSynonym(int i);
};

#endif /* Direction_hpp */
