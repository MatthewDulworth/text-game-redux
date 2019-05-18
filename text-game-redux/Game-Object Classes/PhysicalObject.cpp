//
//  PhysicalObjectClasses.cpp
//  text-game-redux
//  The methods for the PhysicalObject classes 
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "PhysicalObject.hpp"
#include "Location.hpp"
#include "Passage.hpp"


// ------------------------------------------------------------------------------------------------------
// PhysicalObject classes
// ------------------------------------------------------------------------------------------------------

// ------------------------------------------------
// PhysicalObject methods
// ------------------------------------------------
// ----- setDescription ----- //
void PhysicalObject::setDescription(string new_description){
    description = new_description;
}
// ----- setLocation ----- //
void PhysicalObject::setLocation(Location* new_location){
    location = new_location;
}
// ----- getDescription ----- //
string PhysicalObject::getDescription(){
    return description;
};
// ----- getLocation ----- //
Location* PhysicalObject::getLocation(){
    return location;
}
// ----- printDescription ----- //
void PhysicalObject::printDescription(){
    cout << description;
}


// ------------------------------------------------
// Item methods
// ------------------------------------------------
// ----- moveTo ----- //
void Item::moveTo(Location* location){
    this->location = location;
}
// ----- isInInventory ----- //
bool Item::isInInventory(){
    if(location->getCode() == INVENTORY) return true;
    else return false;
}
// ----- derivedType ----- //
string Item::derivedType(){
    return "PhysicalObject";
}


// ------------------------------------------------
// Key methods
// ------------------------------------------------
// ----- canUnlock ----- //
bool Key::canUnlock(Passage* door){
    if(door_type == door->getDoor_type() )
        return true;
    else
        return false;
}
// ----- setDoor_Type ----- //
void Key::setDoor_Type(int type){
    door_type = type;
}
// ----- getDoor_type ----- //
int Key::getDoor_type(){
    return door_type;
}


// ------------------------------------------------
// Money methods
// ------------------------------------------------
// ----- setValue ----- //
void Money::setValue(double new_value){
    value = new_value;
}
// ----- getValue ----- //
double Money::getValue(){
    return value;
}


// ------------------------------------------------
// Immovable methods
// ------------------------------------------------
string ImmovableObject::derivedType(){
    return "PhysicalObject";
}
