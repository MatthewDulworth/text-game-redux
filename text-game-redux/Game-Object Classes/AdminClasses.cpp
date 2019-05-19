//
//  Direction.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "AdminClasses.hpp"

// ------------------------------------------------
// Action methods
// ------------------------------------------------
void Action::overridden(){}
// ----- setSynonym ----- //
void Action::setSynonym(string synonym){
    this->synonym = synonym;
}
// ----- getSynonym ----- //
string Action::getSynonym(){
    return synonym;
}


// ------------------------------------------------
// Direction methods
// ------------------------------------------------
void Direction::overridden(){}

// ------------------------------------------------
// Number methods
// ------------------------------------------------
// ----- setSynonym ----- //
void Number::setSynonym(string synonym){
    this->synonym = synonym;
}
// ----- getSynonym ----- //
string Number::getSynonym(){
    return synonym;
}
// ----- overridden ----- //
void Number::overridden(){}

// ------------------------------------------------
// Word methods
// ------------------------------------------------
void Word::overridden(){}
