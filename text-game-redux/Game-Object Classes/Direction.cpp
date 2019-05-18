//
//  Direction.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Direction.hpp"

// ------------------------------------------------
// Direction Methods
// ------------------------------------------------
string Direction::derivedType(){
    return "Direction";
}

// ------------------------------------------------
// Direction Methods
// ------------------------------------------------
string Number::derivedType(){
    return "FloorButton";
}

void Number::setSynonym(string synonym){
    this->synonym = synonym;
}

string Number::getSynonym(){
    return synonym;
}
