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
string Passage::derivedType(){ // returns first level subclass name
    return "Passage";
}
// checks
bool Passage::isVisible(){
    if(hidden_state == VISIBLE) return true;
    else return false;
}
bool Passage::isLocked(){
    if(lock_state == LOCKED) return true;
    else return false;
}

// setters
void Passage::setLockState(bool state){
    lock_state = state;
}
void Passage::setHiddenState(bool new_state){
    hidden_state = new_state;
}
void Passage::setRoom_1(Location* new_location){
    room_1 = new_location;
}
void Passage::setRoom_2(Location* new_location){
    room_2 = new_location;
}
// getters
Location* Passage::getRoom_1(){
    return room_1;
}
Location* Passage::getRoom_2(){
    return room_2;
}

