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
void Location::pureVirtualFunction(){
    cout << "This is not an abstract class\n";
}


// ------------------------------------------------
// Passage methods
// ------------------------------------------------

// ------- Passage ------- //
// checks
bool Passage::isHidden(){
    return hidden_state;
}

// setters
void Passage::setHiddenState(bool new_state){
    hidden_state = new_state;
}
void Passage::setLocation_1(Location* new_location){
    location_1 = new_location;
}
void Passage::setLocation_2(Location* new_location){
    location_2 = new_location;
}

// getters
Location* Passage::getLocation_1(){
    return location_1;
}
Location* Passage::getLocation_2(){
    return location_2;
}


// ------- OpenPassage ------- //
void OpenPassage::pureVirtualFunction(){
    cout << "This is not an abstract class\n";
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
void Trapdoor::pureVirtualFunction(){
    cout << "This is not an abstract class\n";
}


// ------- // RegularDoor ------- //
void RegularDoor::pureVirtualFunction(){
    cout << "This is not an abstract class\n";
}

