//
//  Location.cpp
//  text-game-redux
//  The methods of the Location clasw
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Location.hpp"
#include "Passage.hpp"

// ------------------------------------------------
// Location methods
// ------------------------------------------------
// sets the description of the location
void Location::setDescription(string new_description){
    description = new_description;
}
// returns the description of the location
string Location::getDescription(){
    return description;
}


// ------------------------------------------------
// Room methods
// ------------------------------------------------
string Room::derivedType(){ // returns first level subclass name
    return "Location";
}
// sets a single exit from the room
void Room::setExit(int direction, Passage* exit){
    exits[direction] = exit;
}
// sets all exits from the room
void Room::setAllExits(Passage* exit_north, Passage* exit_south, Passage* exit_east, Passage* exit_west, Passage* exit_up, Passage* exit_down){
    exits[NORTH] = exit_north;
    exits[SOUTH] = exit_south;
    exits[EAST] = exit_east;
    exits[WEST] = exit_west;
}
void Room::setFloor(int new_floor){
    floor = new_floor;
}
int Room::getFloor(){
    return floor;
}
// sets a single exit from the room 
Passage* Room::exitTo(int direction){
    return exits[direction];
}


// ------------------------------------------------
// Elevator methods
// ------------------------------------------------
string Elevator::derivedType(){
    return "Location";
}
// setters
void Elevator::setExit_direction(int direction){
    exit_direction = direction;
}
void Elevator::setExit(int new_floor, Passage* exit){
    exits[new_floor] = exit;
}
void Elevator::setFloor(int floor){
    current_exit = exits[floor];
    
    if(this == exits[floor]->getRoom_1() ){
        Room* room_2 = static_cast<Room*>(exits[floor]->getRoom_2() );
        this->floor = room_2->getFloor();
    }
    else if (this == exits[floor]->getRoom_2() ) {
        Room* room_1 = static_cast<Room*>(exits[floor]->getRoom_1() );
        this->floor = room_1->getFloor();
    }
}
void Elevator::setLowest_floor(int floor){
    lowest_floor = floor;
}
void Elevator::setHighest_floor(int floor){
    highest_floor = floor;
}
void Elevator::setAllButtons(){
    
    for(int i=0; i<FLOORS; i++){
        if(i>=lowest_floor && i<=highest_floor){
            buttons[i]->setVisibleState(VISIBLE);
        } else {
            buttons[i]->setVisibleState(HIDDEN);
        }
    }
}

// getters
int Elevator::getFloor(){
    return floor;
}
int Elevator::getExit_direction(){
    return exit_direction;
}
Passage* Elevator::getCurrent_exit(){
    return current_exit;
}


// ------------------------------------------------
// FloorButton
// ------------------------------------------------
bool FloorButton::isVisible(){
    if(visible_state == VISIBLE){
        return true;
    } else{
        return false;
    }
}

void FloorButton::setVisibleState(bool new_visible_state){
    visible_state = new_visible_state;
}

void FloorButton::setFloor(int new_floor){
    floor = new_floor;
}

int FloorButton::getFloor(){
    return floor;
}



// ------------------------------------------------
// AdminLocation methods
// ------------------------------------------------
string AdminLocation::derivedType(){
    return "Location";
}
