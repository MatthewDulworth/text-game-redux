//
//  Location.cpp
//  text-game-redux
//  The methods of the Location class
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






// ------------------------------------------------
// Room methods
// ------------------------------------------------

// ----- derivedType ----- //
string Room::derivedType(){
    return "Location";
}


// ************ setters ************ //

// ----- setExit ----- //
void Room::setExit(int direction, Passage* exit){
    exits[direction] = exit;
}
// ----- setAllExits ----- //
void Room::setAllExits(Passage* exit_north, Passage* exit_south, Passage* exit_east, Passage* exit_west, Passage* exit_up, Passage* exit_down){
    exits[NORTH] = exit_north;
    exits[SOUTH] = exit_south;
    exits[EAST] = exit_east;
    exits[WEST] = exit_west;
}
// ----- setFloor ----- //
void Room::setFloor(int new_floor){
    floor = new_floor;
}


// ************ getters ************ //

// ----- getFloor ----- //
int Room::getFloor(){
    return floor;
}
// ----- exitTo ----- //
Passage* Room::exitTo(int direction){
    return exits[direction];
}

// ------------------------------------------------






// ------------------------------------------------
// Elevator methods
// ------------------------------------------------

// returns first level subclass name
string Elevator::derivedType(){
    return "Location";
}

// ----- destructor ----- //
Elevator::~Elevator(){
    for(int i=0; i<FLOORS; i++){
        delete buttons[i];
    }
}

// buttonIsVisible
bool Elevator::buttonIsVisibile(int floor){
    if(buttons[floor]->isVisible() == true){
        return true;
    }
    else{
        return false;
    }
}

// ----- setters ----- //

// sets the direction the elevator doors open
void Elevator::setExit_direction(int direction){
    exit_direction = direction;
}

// sets
void Elevator::setExit(int new_floor, Passage* exit){
    exits[new_floor] = exit;
}

// sets the floor that the elevator is currently at
// sets the current exit
void Elevator::setCurrent_floor(int floor){
    current_floor = floor;
    current_exit = exits[current_floor];
}

//
void Elevator::initButtons() {
    
    for(int i=0; i<FLOORS; i++){
        buttons[i] = new ElevatorButton();
    }
    updateButtonsVisibility();
}

//
void Elevator::updateButtonsVisibility(){
    for(int i=0; i<FLOORS; i++){
        if(exits[i] != 0){
            if(exits[i]->isVisible() ){
                buttons[i]->setVisibleState(VISIBLE);
            } else {
                buttons[i]->setVisibleState(HIDDEN);
            }
        } else {
            buttons[i]->setVisibleState(HIDDEN);
        }
    }
}

// ----- getters ----- //

//
int Elevator::getCurrent_floor(){
    return current_floor;
}

//
int Elevator::getExit_direction(){
    return exit_direction;
}

//
Passage* Elevator::getCurrent_exit(){
    return current_exit;
}

// ------------------------------------------------






// ------------------------------------------------
// ElevatorButton
// ------------------------------------------------
bool ElevatorButton::isVisible(){
    if(visible_state == VISIBLE){
        return true;
    } else{
        return false;
    }
}

void ElevatorButton::setVisibleState(bool new_visible_state){
    visible_state = new_visible_state;
}

void ElevatorButton::setFloor(int new_floor){
    floor = new_floor;
}

int ElevatorButton::getFloor(){
    return floor;
}

// ------------------------------------------------







// ------------------------------------------------
// AdminLocation methods
// ------------------------------------------------
string AdminLocation::derivedType(){
    return "Location";
}

// ------------------------------------------------
