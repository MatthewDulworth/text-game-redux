//
//  MapSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "Location.hpp"
#include "Passage.hpp"
#include "Player.hpp"

// ------------------------------------------------------------------------------------------------------
// mapSetup
// ------------------------------------------------------------------------------------------------------
// popluates the loctions and passages arrays
void Game::mapSetup(){
    
    
    // --------------------------------------------------------------------------------------
    // create new objects
    // --------------------------------------------------------------------------------------
    
    // ------------------------------------------------
    // locations
    // ------------------------------------------------
    // admin locations
    locations[INVENTORY] = new AdminLocation();
    locations[TRASH] = new AdminLocation();
    
    // first floor
    locations[BEDROOM] = new Room();
    locations[BATHROOM] = new Room();
    locations[BEDROOM_HALLWAY] = new Room();
    locations[ELEVATOR_ONE] = new Elevator();
    

    // ------------------------------------------------
    // passages
    // ------------------------------------------------
    for(int i = PASSAGES_min; i<PASSAGES_max; i++){
        passages[i] = new Passage();
    }
    
    
    // ------------------------------------------------
    // player
    // ------------------------------------------------
    player = new Player(locations[BEDROOM]);
    
    
    // --------------------------------------------------------------------------------------
    // rooms
    // --------------------------------------------------------------------------------------
    // BEDROOM
    Room* bedroom = static_cast<Room*>(locations[BEDROOM]);
    bedroom->setCode(BEDROOM);
    bedroom->setName("BEDROOM");
    bedroom->setDescription("bedroom");
    bedroom->setFloor(FIRST_FLOOR);
    bedroom->setExit(SOUTH, passages[BEDROOM_to_BEDROOM_HALLWAY]);
    // BATHROOM
    Room* bathroom = static_cast<Room*>(locations[BATHROOM]);
    bathroom->setCode(BATHROOM);
    bathroom->setName("BATHROOM");
    bathroom->setDescription("bathroom");
    bathroom->setFloor(FIRST_FLOOR);
    bathroom->setExit(EAST, passages[BEDROOM_to_BATHROOM]);
    
    // BEDROOM_HALLWAY
    Room* bedroom_hallway = static_cast<Room*>(locations[BEDROOM_to_BEDROOM_HALLWAY]);
    bedroom_hallway->setCode(BEDROOM_HALLWAY);
    bedroom_hallway->setName("BEDROOM HALLWAY");
    bedroom_hallway->setDescription("hallway");
    bedroom_hallway->setFloor(FIRST_FLOOR);
    bedroom_hallway->setExit(NORTH, passages[BEDROOM_to_BEDROOM_HALLWAY]);
    
    // --------------------------------------------------------------------------------------
    // elevators
    // --------------------------------------------------------------------------------------
    // ELEVATOR_ONE
    Elevator* elevator_one = static_cast<Elevator*>(locations[ELEVATOR_ONE]);
    elevator_one->setCode(ELEVATOR_ONE);
    elevator_one->setName("ELEVATOR ONE");
    elevator_one->setExit_direction(WEST);
    elevator_one->setExit(FIRST_FLOOR, passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]);
    elevator_one->setCurrent_floor(FIRST_FLOOR);
    elevator_one->initButtons();

    
    // --------------------------------------------------------------------------------------
    // passages
    // --------------------------------------------------------------------------------------
    // BEDROOM_to_BEDROOM_HALLWAY
    passages[BEDROOM_HALLWAY]->setCode(BEDROOM_HALLWAY);
    passages[BEDROOM_HALLWAY]->setLockState(UNLOCKED);
    passages[BEDROOM_HALLWAY]->setVisibility(VISIBLE);
    passages[BEDROOM_HALLWAY]->setLocation_1(bedroom);
    passages[BEDROOM_HALLWAY]->setLocation_2(bedroom_hallway);
    passages[BEDROOM_HALLWAY]->setKey_type(ACCESS_LVL_1);
    // BEDROOM_to_BATHROOM
    passages[BEDROOM_to_BATHROOM]->setCode(BEDROOM_to_BATHROOM);
    passages[BEDROOM_to_BATHROOM]->setLockState(UNLOCKED);
    passages[BEDROOM_to_BATHROOM]->setVisibility(VISIBLE);
    passages[BEDROOM_to_BATHROOM]->setLocation_1(bedroom);
    passages[BEDROOM_to_BATHROOM]->setLocation_2(bathroom);
    passages[BEDROOM_to_BATHROOM]->setKey_type(ACCESS_LVL_1);
    // BEDROOM_HALLWAY_to_ELEVATOR_ONE
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setCode(BEDROOM_HALLWAY_to_ELEVATOR_ONE);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setLockState(LOCKED);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setVisibility(VISIBLE);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setLocation_1(bedroom_hallway);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setLocation_2(elevator_one);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setKey_type(ACCESS_LVL_2);

    
    // --------------------------------------------------------------------------------------
    // admin locations
    // --------------------------------------------------------------------------------------
    // ----- set adminlocations ----- //
    // INVENTORY
    locations[INVENTORY]->setCode(INVENTORY);
    locations[INVENTORY]->setName("INVENTORY");
    locations[INVENTORY]->setDescription("the players inventory");
    // TRASH
    locations[TRASH]->setCode(TRASH);
    locations[TRASH]->setName("TRASH");
    locations[TRASH]->setDescription( "trash for unneeded physical objects");
}
