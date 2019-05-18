//
//  TypeChecks.cpp
//  text-game-redux
//  Checks the class type of an object
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "TypeChecks.hpp"
#include <typeinfo>

// ------------------------------------------------
// Location classes
// ------------------------------------------------


// ------------------------------------------------
// Passage classes
// ------------------------------------------------



// ------------------------------------------------
// PhysicalObject classes
// ------------------------------------------------
bool isPhysical_object(int code){
    if(code >= PHYSICAL_OBJECTS_min && code<PHYSICAL_OBJECTS_max){
        return true;
    }
    else return false;
}


// ------------------------------------------------
// Setup classes
// ------------------------------------------------
bool isNumber(int code){
    if(code >= NUMBERS_min && code<NUMBERS_max){
        return true;
    }
    else return false;
}

bool isAction(int code){
    if(code >= ACTIONS_min && code<ACTIONS_max){
        return true;
    }
    else return false;
}

bool isDirection(int code){
    if(code >= DIRECTIONS_min && code < DIRECTIONS_max){
        return true;
    }
    else return false;
}



// ------- getTargetLocation ------- //
// creates a target location
Location* getTargetLocation(Passage* passage, Location* location){
    Location* target_location = 0;
    
    if(location == passage->getLocation_1()){
        target_location = passage->getLocation_2();
    }
    
    else if(location == passage->getLocation_2()){
        target_location = passage->getLocation_1();
    }
    
    return target_location;
}


