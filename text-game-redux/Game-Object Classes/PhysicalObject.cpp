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
// ----- setDetails ----- //
void PhysicalObject::setDetails(string new_details){
    details = new_details;
}
// ----- getDescription ----- //
string PhysicalObject::getDescription(){
    return description;
};
// ----- getDetails ----- //
string PhysicalObject::getDetails(){
    return details;
};
// ----- getLocation ----- //
Location* PhysicalObject::getLocation(){
    return location;
}
// ----- printDescription ----- //
void PhysicalObject::printDescription(){
    cout << description << endl;
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
    if(location->getCode() == INV) return true;
    else return false;
}
// ----- overridden ----- //
void Item::overridden(){}


// ------------------------------------------------
// Key methods
// ------------------------------------------------
// ----- canUnlock ----- //
bool Key::canUnlock(Passage* door){
    return (code == door->getKey() );
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
void ImmovableObject::overridden(){}
