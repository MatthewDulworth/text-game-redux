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
// ----- derivedType ----- //
string Action::derivedType(){
    return "Action";
}

// ------------------------------------------------
// Direction methods
// ------------------------------------------------
// ----- derivedType ----- //
string Direction::derivedType(){
    return "Direction";
}

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
// ----- derivedType ----- //
string Number::derivedType(){
    return "FloorButton";
}
