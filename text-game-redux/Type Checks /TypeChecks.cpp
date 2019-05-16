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

// ------- Item ------- //
bool isItem(Base* unkown_object){
    Item* known_object;
    if( (known_object = dynamic_cast<Item*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Item ------- //
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
    else{
        return false;
    }
}

// ------- Action ------- //
bool isAction(Base* unknown_object){
    Action* known_object;
    if( (known_object = dynamic_cast<Action*>(unknown_object)) )
        return true;
    else
        return false;
}

// ------- Direction ------- //
bool isDirection(Base* unkown_object){
    Direction* known_object;
    if( (known_object = dynamic_cast<Direction*>(unkown_object)) )
        return true;
    else
        return false;
}
