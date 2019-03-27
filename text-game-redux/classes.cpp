//
//  classes.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//


#include <string>
#include <iostream>

#include "classes.hpp"
using namespace std;

// --------------------------------------------------
// Base class functions
// --------------------------------------------------
// returns the code of the game-object
int Base::getCode() {
    return code;
}

// returns the name of the game-object
string Base::getName() {
    return name;
}

// --------------------------------------------------
// Location class functions
// --------------------------------------------------
void Location::func(){
    cout << "func called";
}

// --------------------------------------------------
// Passage class functions
// --------------------------------------------------
void Passage::func(){
    cout << "func called";
}
