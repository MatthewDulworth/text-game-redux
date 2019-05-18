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

// ------------------------------------------------
// PhysicalObject methods
// ------------------------------------------------
// setters
void PhysicalObject::setDescription(string new_description){
    description = new_description;
}
void PhysicalObject::setLocation(Location* new_location){
    location = new_location;
}

// getters
string PhysicalObject::getDescription(){
    return description;
};
Location* PhysicalObject::getLocation(){
    return location;
}
//
void PhysicalObject::printDescription(){
    cout << description;
}

// ------------------------------------------------
// Item methods
// ------------------------------------------------
string Item::derivedType(){
    return "PhysicalObject";
}
bool Item::isInInventory(){
    if(location->getCode() == INVENTORY)
        return true;
    else
        return false;
}
void Item::moveTo(Location* location){
    this->location = location;
}


// ------------------------------------------------
// Key methods
// ------------------------------------------------
void Key::setDoor_Type(int type){
    door_type = type;
}
int Key::getDoor_type(){
    return door_type;
}
bool Key::canUnlock(Passage* door){
    if(door_type == door->getDoor_type() )
        return true;
    else
        return false;
}

// ------------------------------------------------
// Money methods
// ------------------------------------------------
// setters
void Money::setWorth(double new_worth){
    worth = new_worth;
}
// getters
double Money::getWorth(){
    return worth;
}


/// ------------------------------------------------
// Immovable methods
// ------------------------------------------------
string ImmovableObject::derivedType(){
    return "PhysicalObject";
}
