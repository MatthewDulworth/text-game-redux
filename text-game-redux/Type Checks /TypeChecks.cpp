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

// ------- Room ------- //
bool isRoom(Base* unkown_object){
    Room* known_object;
    if( (known_object = dynamic_cast<Room*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Elevator ------- //
bool isElevator(Base* unkown_object){
    Elevator* known_object;
    if( (known_object = dynamic_cast<Elevator*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- AdminLocation ------- //
bool isAdminLocation(Base* unkown_object){
    AdminLocation* known_object;
    if( (known_object = dynamic_cast<AdminLocation*>(unkown_object)) )
        return true;
    else
        return false;
}


// ------------------------------------------------
// Passage classes
// ------------------------------------------------

// ------- Passage ------- //
bool isPassage(Base* unkown_object){
    Passage* known_object;
    if( (known_object = dynamic_cast<Passage*>(unkown_object)) )
        return true;
     else
        return false;
}


// ------------------------------------------------
// PhysicalObject classes
// ------------------------------------------------

// ------- PhysicalObject ------- //
bool isPhysical_object(Base* unkown_object){
    PhysicalObject* known_object;
    if( (known_object = dynamic_cast<PhysicalObject*>(unkown_object)) ){
        return true;
    }
    else return false;
}
bool isPhysical_object(int code){
    if(code >= PHYSICAL_OBJECTS_min && code<PHYSICAL_OBJECTS_max){
        return true;
    }
    else return false;
}

// ------- Item ------- //
bool isItem(Base* unkown_object){
    Item* known_object;
    if( (known_object = dynamic_cast<Item*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Key ------- //
bool isKey(Base* unkown_object){
    Key* known_object;
    if( (known_object = dynamic_cast<Key*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Money ------- //
bool isMoney(Base* unkown_object){
    Money* known_object;
    if( (known_object = dynamic_cast<Money*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- ImmoveableObject ------- //
bool isImmoveableObject(Base* unkown_object){
    ImmovableObject* known_object;
    if( (known_object = dynamic_cast<ImmovableObject*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------------------------------------------------
// Setup classes
// ------------------------------------------------

// ------- Number ------- //
bool isNumber(Base* unknown_object){
    Number* known_object;
    if( (known_object = dynamic_cast<Number*>(unknown_object)) ){
        return true;
    }
    else return false;
}
bool isNumber(int code){
    if(code >= NUMBERS_min && code<NUMBERS_max){
        return true;
    }
    else return false;
}


// ------- Action ------- //
bool isAction(Base* unknown_object){
    Action* known_object;
    if( (known_object = dynamic_cast<Action*>(unknown_object)) )
        return true;
    else
        return false;
}
bool isAction(int code){
    if(code >= ACTIONS_min && code<ACTIONS_max){
        return true;
    }
    else return false;
}

// ------- Direction ------- //
bool isDirection(Base* unkown_object){
    Direction* known_object;
    if( (known_object = dynamic_cast<Direction*>(unkown_object)) )
        return true;
    else
        return false;
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
