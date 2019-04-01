//
//  Location.cpp
//  text-game-redux
//  The methods of the Location clasw
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Location.hpp"
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

// ------- AdminLocation ------- //
string AdminLocation::derivedType(){
    return "Location";
}




