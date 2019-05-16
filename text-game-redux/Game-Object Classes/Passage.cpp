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
bool Passage::isUnlocked(){
    if(lock_state == UNLOCKED) return true;
    else return false;
}

// setters
void Passage::setLockState(bool state){
    lock_state = state;
}
void Passage::setHiddenState(bool new_state){
    hidden_state = new_state;
}
void Passage::setDoor_type(int type){
    door_type = type;
}
void Passage::setLocation_1(Location* new_location){
    location_1 = new_location;
}
void Passage::setLocation_2(Location* new_location){
    location_2 = new_location;
}
// getters
int Passage::getDoor_type(){
    return door_type;
}
Location* Passage::getLocation_1(){
    return location_1;
}
Location* Passage::getLocation_2(){
    return location_2;
}

