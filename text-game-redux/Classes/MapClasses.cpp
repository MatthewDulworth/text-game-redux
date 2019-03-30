//
//  MapClasses.cpp
//  text-game-redux
//  The methods of the Location and Passage classes
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "MapClasses.hpp"
using namespace std;

// ------------------------------------------------
// Location methods
// ------------------------------------------------

// ------- Location ------- //
// sets the description of the location
void Location::setDescription(string new_description){
    description = new_description;
}
// returns the description of the location
string Location::getDescription(){
    return description;
}
// prints the description
void Location::printDescription(){
    cout << description;
}


// ------- Room ------- //
string Room::derivedType(){ // returns first level subclass name
    return "Location";
}
// sets a single exit from the room
void Room::setExit(int direction, Passage* exit){
    
}
// sets all exits from the room
void Room::setAllExits(Passage* exit_north, Passage* exit_south, Passage* exit_east, Passage* exit_west, Passage* exit_up, Passage* exit_down){
    
}

// ------- Framework ------- //
string AdminLocation::derivedType(){
    return "Location";
}


// ------------------------------------------------
// Passage methods
// ------------------------------------------------

// ------- Passage ------- //
bool Passage::isHidden(){ // returns true of the passage is hidden
    if(hidden_state == HIDDEN) return true;
    else return false;
}
// setters
void Passage::setHiddenState(bool new_state){
    hidden_state = new_state;
}
void Passage::setRoom_1(Room* new_location){
    room_1 = new_location;
}
void Passage::setRoom_2(Room* new_location){
    room_2 = new_location;
}
// getters
Room* Passage::getRoom_1(){
    return room_1;
}
Room* Passage::getRoom_2(){
    return room_2;
}


// -------  OpenPassage ------- //
string Deadend::derivedType(){ // returns first level subclass name
    return "Passage";
}


// ------- OpenPassage ------- //
string OpenPassage::derivedType(){ // returns first level subclass name
    return "Passage";
}


// ------- ClosedPassage ------- //
bool ClosedPassage::isLocked(){
    if(lock_state == LOCKED) return true;
    else return false;
}
bool ClosedPassage::isOpen(){
    if(open_state == OPEN) return true;
    else return false;
}


// ------- Trapdoor ------- //
string Trapdoor::derivedType(){ // returns first level subclass name
    return "Passage";
}


// ------- // RegularDoor ------- //
string RegularDoor::derivedType(){ // returns first level subclass name
    return "Passage";
}

