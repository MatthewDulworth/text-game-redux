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
#include "PhysicalObject.hpp"
#include "typeChecks.hpp"
#include <algorithm>


// ------------------------------------------------------------------------------------------------------
// Location classes methods
// ------------------------------------------------------------------------------------------------------

// ------------------------------------------------
// Location methods
// ------------------------------------------------
// ----- addObject ----- //
void Location::addObject(PhysicalObject* object){
    contents.push_back(object);
}
// ----- removeObject ----- //
void Location::removeObject(PhysicalObject* object){
    contents.erase(std::remove(contents.begin(), contents.end(), object ), contents.end() );
}
// ----- setDescription ----- //
void Location::setDescription(string new_description){
    description = new_description;
}
// ----- getDescription ----- //
string Location::getDescription(){
    return description;
}
// ------------------------------------------------




// ------------------------------------------------
// Room methods
// ------------------------------------------------
// ----- initCallButtons ----- //
void Room::initCallButtons(){
    
    for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
        Passage* current_passage = exits[i];
        
        if(current_passage != 0){
            Location* target_location = getTargetLocation(current_passage, this);
            
            if(isType<Elevator>(target_location)){
                call_buttons[i] = true;
            }
            else{
                call_buttons[i] = false;
            }
        }
        
    }
}
// ----- hasCallButton ----- //
bool Room::hasCallButton(int direction){
    if(call_buttons[direction] == true){
        return true;
    }
    else return false;
}

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
// ----- getFloor ----- //
int Room::getFloor(){
    return floor;
}
// ----- getExit ----- //
Passage* Room::getExit(int direction){
    return exits[direction];
}
// ----- derivedType ----- //
string Room::derivedType(){
    return "Location";
}
// ------------------------------------------------




// ------------------------------------------------
// ElevatorFloorButton
// ------------------------------------------------
// ----- isVisible ----- //
bool ElevatorFloorButton::isVisible(){
    if(visibility == VISIBLE){
        return true;
    } else{
        return false;
    }
}
// ----- 
void ElevatorFloorButton::setVisibility(bool visibility){
    this->visibility = visibility;
}

void ElevatorFloorButton::setFloor(int new_floor){
    floor = new_floor;
}

int ElevatorFloorButton::getFloor(){
    return floor;
}

// ------------------------------------------------




// ------------------------------------------------
// Elevator methods
// ------------------------------------------------
// ----- destructor ----- //
Elevator::~Elevator(){
    for(int i=FLOORS_min; i<FLOORS_max; i++){
        delete floor_buttons[i];
    }
}
// ----- initButtons ----- //
void Elevator::initButtons() {
    
    for(int i=FLOORS_min; i<FLOORS_max; i++){
        floor_buttons[i] = new ElevatorFloorButton();
    }
    updateButtonsVisibility();
}

// ----- buttonIsVisible ----- //
bool Elevator::buttonIsVisibile(int floor){
    if(floor_buttons[floor]->isVisible() == true){
        return true;
    }
    else{
        return false;
    }
}
// ----- updateButtonVisibility ----- //
void Elevator::updateButtonsVisibility(){
    for(int i=FLOORS_min; i<FLOORS_max; i++){
        
        if(exits[i] != 0){
            if(exits[i]->isVisible() ){
                floor_buttons[i]->setVisibility(VISIBLE);
            } else {
                floor_buttons[i]->setVisibility(HIDDEN);
            }
        } else {
            floor_buttons[i]->setVisibility(HIDDEN);
        }
        
    }
}
// ----- setExit_direction ----- //
void Elevator::setExit_direction(int direction){
    exit_direction = direction;
}
// ----- setExit ----- //
void Elevator::setExit(int new_floor, Passage* exit){
    exits[new_floor] = exit;
}
// ----- setCurrent_floor ----- //
void Elevator::setCurrent_floor(int floor){
    current_floor = floor;
    current_exit = exits[current_floor];
}
// ----- getCurrent_floor ----- //
int Elevator::getCurrent_floor(){
    return current_floor;
}
// ----- getExit_direction ----- //
int Elevator::getExit_direction(){
    return exit_direction;
}
// ----- getCurrentFloorNumber ----- //
int Elevator::getCurrentFloorNumber(){
    return (current_floor - 100 + 1);
}
// ----- getCurrent_exit ----- //
Passage* Elevator::getCurrent_exit(){
    return current_exit;
}
// ----- derivedType ----- //
string Elevator::derivedType(){
    return "Location";
}
// ------------------------------------------------




// ------------------------------------------------
// AdminLocation methods
// ------------------------------------------------
// ----- derivedType ----- //
string AdminLocation::derivedType(){
    return "Location";
}

// ------------------------------------------------
