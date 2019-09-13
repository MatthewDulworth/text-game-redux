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
#include "GeneralFunctions.hpp"
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
// ----- incrementEnteredCount ----- //
void Location::incrementEnteredCount(){
    entered_count++;
}
// ----- locationHasBeenEntered ----- //
bool Location::locationHasBeenEntered(){
    return (entered_count > 0) ? true : false;
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
// ElevatorCallButton methods
// ------------------------------------------------
bool ElevatorCallButton::isVisible(){
    if(visibility == VISIBLE)return true;
    else return false;
}
void ElevatorCallButton::setVisibility(bool state){
    visibility = state;
}
void ElevatorCallButton::setElevator(Elevator* new_elevator){
    elevator = new_elevator;
}
Elevator* ElevatorCallButton::getElevator(){
    return elevator;
}
// ------------------------------------------------




// ------------------------------------------------
// Room methods
// ------------------------------------------------
Room::Room(){
    entered_count = 0;
}
Room::~Room(){
    for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
        delete call_buttons[i];
    }
}
// ----- initCallButtons ----- //
void Room::initCallButtons(){
    
    for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
        Passage* current_passage = exits[i];
        
        if(current_passage != 0){
            Location* target_location = getTargetLocation(current_passage, this);
            
            if(isType<Elevator>(target_location)){
                call_buttons[i] = new ElevatorCallButton();
                call_buttons[i]->setElevator(static_cast<Elevator*>(target_location));
                if(current_passage->isVisible()){
                    call_buttons[i]->setVisibility(VISIBLE);
                }
                else{
                     call_buttons[i]->setVisibility(HIDDEN);
                }
            }
            else{
                call_buttons[i] = 0;
            }
        }
        else {
            call_buttons[i] = 0;
        }
    }
}
// ----- hasVisibleButton ----- //
bool Room::hasVisibleButton(int direction){
    if(call_buttons[direction] != 0){
        if(call_buttons[direction]->isVisible()){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

// ----- setExit ----- //
void Room::setExit(int direction, Passage* exit){
    exits[direction] = exit;
}
// ----- setAllExits ----- //
void Room::setAllExits(Passage* exit_north, Passage* exit_south, Passage* exit_east, Passage* exit_west){
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
ElevatorCallButton* Room::getButton(int direction){
    return call_buttons[direction];
}
// ----- overridden ----- //
void Room::overridden(){}
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
// ----- setVisibility ----- //
void ElevatorFloorButton::setVisibility(bool visibility){
    this->visibility = visibility;
}
// ----- setFloor ----- //
void ElevatorFloorButton::setFloor(int new_floor){
    floor = new_floor;
}
// ----- getFloor ----- //
int ElevatorFloorButton::getFloor(){
    return floor;
}
// ------------------------------------------------




// ------------------------------------------------
// Elevator methods
// ------------------------------------------------
Elevator::Elevator(){
    entered_count = 0;
}
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
// ----- getFloors ----- //
int Elevator::getFloors(){
    int floors = 0;
    
    for(int i=FLOORS_min; i<FLOORS_max; i++){
        if(floor_buttons[i]->isVisible()){
            floors++;
        }
    }
    return floors;
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
// ----- overridden ----- //
void Elevator::overridden(){}
// ------------------------------------------------




// ------------------------------------------------
// AdminLocation methods
// ------------------------------------------------
void AdminLocation::overridden(){}

// ------------------------------------------------
