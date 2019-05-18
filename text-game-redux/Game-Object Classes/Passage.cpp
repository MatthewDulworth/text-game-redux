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
// ----- isVisible ----- //
bool Passage::isVisible(){
    if(visibility == VISIBLE) return true;
    else return false;
}
// ----- isUnlocked ----- //
bool Passage::isUnlocked(){
    if(lock_state == UNLOCKED) return true;
    else return false;
}
// ----- setLockState ----- //
void Passage::setLockState(bool state){
    lock_state = state;
}
// ----- setVisibility ----- //
void Passage::setVisibility(bool state){
    visibility = state;
}
// ----- setKey_type ----- //
void Passage::setKey_type(int type){
    key_type = type;
}
// ----- setLocation_1 ----- //
void Passage::setLocation_1(Location* new_location){
    location_1 = new_location;
}
// ----- setLocation_2 ----- //
void Passage::setLocation_2(Location* new_location){
    location_2 = new_location;
}
// ----- getKey_type ----- //
int Passage::getKey_type(){
    return key_type;
}
// ----- getLocation_1 ----- //
Location* Passage::getLocation_1(){
    return location_1;
}
// ----- getLocation_2 ----- //
Location* Passage::getLocation_2(){
    return location_2;
}
// ----- overridden ----- //
void Passage::overridden(){}
