//
//  createRoom.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 9/12/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "Location.hpp"
#include "Passage.hpp"

// ------------------------------------------------------------------------------------------------------
// createMapElements
// ------------------------------------------------------------------------------------------------------
void Game::createMapElements(){
    // cycles through all the AdminLocation codes in the locations array and creates an AdminLocation object there
    for(int i=LOCATIONS_min; i<LOCATIONS_min+ADMINS; i++){
        locations[i] = new AdminLocation();
    }
   
    // cycles through all the Room codes in the locations array and creates a Room object there
    for(int i=LOCATIONS_min+ADMINS; i<LOCATIONS_min+ADMINS+ROOMS; i++){
        locations[i] = new Room();
    }

    // cycles through all the Elevator codes in the locations array and creates an Elevator object there
    for(int i=LOCATIONS_min+ADMINS+ROOMS; i<LOCATIONS_max; i++){
        locations[i] = new Elevator();
    }
    
    // cycles through the passages array and creates passage for each element
    for(int i=PASSAGES_min; i<PASSAGES_max; i++){
        passages[i] = new Passage();
    }
}


// ------------------------------------------------------------------------------------------------------
// setupAdminLocation
// ------------------------------------------------------------------------------------------------------
void Game::setupAdminLocation(int code, string name, string description){
    
    AdminLocation* location = static_cast<AdminLocation*>(locations[code]);
    
    // assign attributes
    location->setCode(code);
    location->setName(name);
    location->setDescription(description);
}


// ------------------------------------------------------------------------------------------------------
// setupRoom
// ------------------------------------------------------------------------------------------------------
void Game::setupRoom(int code, string name, string description, int floor, int exit_north, int exit_south, int exit_east, int exit_west){
    
    // casat to Room from Location
    Room* room = static_cast<Room*>(locations[code]);
    
    // assign attributes
    room->setCode(code);
    room->setName(name);
    room->setDescription(description);
    room->setFloor(floor);
    
    // assign exits
    int exits[DIRECTIONS] = {exit_north, exit_south, exit_east, exit_west};
    
    for(int i=0; i<DIRECTIONS; i++){
        
        if(exits[i] == 0){
            room->setExit(i+DIRECTIONS_min, 0);
        }
        else{
            room->setExit(i+DIRECTIONS_min, passages[exits[i]]);
        }
    }
}


// ------------------------------------------------------------------------------------------------------
// setupElevator
// ------------------------------------------------------------------------------------------------------
void Game::setupElevator(int code, string name, string description, int startingFloor, int exitDirection, Passage* exits[FLOORS]){
    
    // cast from Location to Elevator
    Elevator* elevator = static_cast<Elevator*>(locations[code]);
    
    // assign aattributes
    elevator->setCode(code);
    elevator->setName(name);
    elevator->setDescription("an elevator");
    elevator->setCurrent_floor(startingFloor);
    elevator->setExit_direction(exitDirection);
    
    // set exits
    for(int i=0; i<FLOORS; i++){
        elevator->setExit(i+FLOORS_min, exits[i]);
    }
}


// ------------------------------------------------------------------------------------------------------
// setupPassage
// ------------------------------------------------------------------------------------------------------
void Game::setupPassage(int code, bool lockState, bool visibility, Location *location_1, Location *location_2){
    Passage* passage = passages[code];
    
    passage->setCode(code);
    passage->setLockState(lockState);
    passage->setVisibility(visibility);
    passage->setLocation_1(location_1);
    passage->setLocation_2(location_2);
}


// ------------------------------------------------------------------------------------------------------
// initCallButtons
// ------------------------------------------------------------------------------------------------------
void Game::initCallButtons(){
    for(int i=LOCATIONS_min; i<LOCATIONS_max; i++){
        if(isType<Room>(locations[i])){
            static_cast<Room*>(locations[i])->initCallButtons();
        }
    }
}
