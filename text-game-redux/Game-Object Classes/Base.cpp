//
//  BaseClass.cpp
//  text-game-redux
//  The methods for the Base class.
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Base.hpp"

// ------------------------------------------------
// Base methods
// ------------------------------------------------

// destructor
Base::~Base(){
    // nothing
}

// setters
void Base::setCode(int new_code){
    code = new_code;
}
void Base::setName(string new_name){
    name = new_name;
}

// getters
int Base::getCode() {
    return code;
}
string Base::getName() {
    return name;
}


