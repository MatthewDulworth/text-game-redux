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

// ------------------------------------------------
// Key methods
// ------------------------------------------------
string Key::derivedType(){
    return "PhysicalObject";
}
bool Key::canUnlock(Passage* door){
    for(int i=0; i<doors.size(); i++){
        if(door == doors.at(i) ){
            return true;
        }
    }
    return false;
}

// ------------------------------------------------
// Money methods
// ------------------------------------------------
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


/// ------------------------------------------------
// Immovable methods
// ------------------------------------------------
string ImmovableObject::derivedType(){
    return "PhysicalObject";
}
