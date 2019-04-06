//
//  PhysicalObjectClasses.cpp
//  text-game-redux
//  The methods for the PhysicalObject classes 
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "PhysicalObject.hpp"

// ------------------------------------------------
// PhysicalObject methods
// ------------------------------------------------

// ------- PhysicalObject ------- //
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


// ------- Item ------- //
string Item::derivedType(){
    return "PhysicalObject";
}


// ------- Money ------- //
string Money::derivedType(){
    return "PhysicalObject";
}
// setters
void Money::setWorth(double new_worth){
    worth = new_worth;
}
// getters
double Money::getWorth(){
    return worth;
}


// ------- ImmoveableObject ------- //
string Immovable::derivedType(){
    return "PhysicalObject";
}
