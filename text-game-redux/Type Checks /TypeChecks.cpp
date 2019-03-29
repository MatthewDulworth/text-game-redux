//
//  TypeChecks.cpp
//  text-game-redux
//  Checks the class type of an object
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "TypeChecks.hpp"

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

// ------- Room ------- //
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

// ------- Room ------- //
bool isDeadend(Base* unkown_object){
    Deadend* known_object;
    if( (known_object = dynamic_cast<Deadend*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Trapdoor ------- //
bool isTrapdoor(Base* unkown_object){
    Trapdoor* known_object;
    if( (known_object = dynamic_cast<Trapdoor*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- RegularDoor ------- //
bool isRegularDoor(Base* unkown_object){
    RegularDoor* known_object;
    if( (known_object = dynamic_cast<RegularDoor*>(unkown_object)) )
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
    Immovable* known_object;
    if( (known_object = dynamic_cast<Immovable*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------------------------------------------------
// Setup classes
// ------------------------------------------------

// ------- Action ------- //
bool isAction(Base* unkown_object){
    Action* known_object;
    if( (known_object = dynamic_cast<Action*>(unkown_object)) )
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
