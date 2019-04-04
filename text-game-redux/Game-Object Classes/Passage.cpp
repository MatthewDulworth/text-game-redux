//
//  Passage.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Passage.hpp"

// ------------------------------------------------
// Passage methods
// ------------------------------------------------
// checks
bool Passage::isVisible(){
    if(hidden_state == VISIBLE) return true;
    else return false;
}
bool Passage::isLocked(){
    return false;
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


// ------------------------------------------------
// OpenPassage methods
// ------------------------------------------------
string OpenPassage::derivedType(){ // returns first level subclass name
    return "Passage";
}


// ------------------------------------------------
// ClosedPassage methods
// ------------------------------------------------
string ClosedPassage::derivedType(){ // returns first level subclass name
    return "Passage";
}
// checks
bool ClosedPassage::isLocked(){
    if(lock_state == LOCKED) return true;
    else return false;
}
// setters
void ClosedPassage::setLockState(bool state){
    lock_state = state;
}

