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
#include "Caretaker.hpp"

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
    static AdminLocation inventory, trash;
    locations[INVENTORY] = &inventory;
    locations[TRASH] = &trash;
    
    // first floor
    static Room bedroom, bathroom, bedroom_hallway;
    static Elevator elevator_one;
    
    // fill array;
    locations[BEDROOM] = &bedroom;
    locations[BATHROOM] = &bathroom;
    locations[BEDROOM_HALLWAY] = &bedroom_hallway;
    locations[ELEVATOR_ONE] = &elevator_one;
    
    
    // ------------------------------------------------
    // passages
    // ------------------------------------------------
    for(int i = PASSAGES_min; i<PASSAGES_max; i++){
        passages[i] = new Passage();
    }
    
    
    // ------------------------------------------------
    // charecters
    // ------------------------------------------------
    player = new Player(&bedroom);
    marvin = new Caretaker("Marvin", '$');
    
    
    // --------------------------------------------------------------------------------------
    // rooms
    // --------------------------------------------------------------------------------------
    // BEDROOM
    bedroom.setCode(BEDROOM);
    bedroom.setName("BEDROOM");
    bedroom.setDescription("bedroom");
    bedroom.setFloor(FIRST_FLOOR);
    bedroom.setExit(SOUTH, passages[BEDROOM_to_BEDROOM_HALLWAY]);
    bedroom.setExit(EAST, passages[BEDROOM_to_BATHROOM]);
    
    // BATHROOM
    bathroom.setCode(BATHROOM);
    bathroom.setName("BATHROOM");
    bathroom.setDescription("bathroom");
    bathroom.setFloor(FIRST_FLOOR);
    bathroom.setExit(WEST, passages[BEDROOM_to_BATHROOM]);
    
    // BEDROOM_HALLWAY
    bedroom_hallway.setCode(BEDROOM_HALLWAY);
    bedroom_hallway.setName("BEDROOM HALLWAY");
    bedroom_hallway.setDescription("hallway");
    bedroom_hallway.setFloor(FIRST_FLOOR);
    bedroom_hallway.setExit(NORTH, passages[BEDROOM_to_BEDROOM_HALLWAY]);
    bedroom_hallway.setExit(EAST, passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]);
    

    // --------------------------------------------------------------------------------------
    // passages
    // --------------------------------------------------------------------------------------
    // BEDROOM_to_BEDROOM_HALLWAY
    passages[BEDROOM_to_BEDROOM_HALLWAY]->setCode(BEDROOM_to_BEDROOM_HALLWAY);
    passages[BEDROOM_to_BEDROOM_HALLWAY]->setLockState(UNLOCKED);
    passages[BEDROOM_to_BEDROOM_HALLWAY]->setVisibility(VISIBLE);
    passages[BEDROOM_to_BEDROOM_HALLWAY]->setLocation_1(&bedroom);
    passages[BEDROOM_to_BEDROOM_HALLWAY]->setLocation_2(&bedroom_hallway);
    passages[BEDROOM_to_BEDROOM_HALLWAY]->setKey_type(ACCESS_LVL_1);
    // BEDROOM_to_BATHROOM
    passages[BEDROOM_to_BATHROOM]->setCode(BEDROOM_to_BATHROOM);
    passages[BEDROOM_to_BATHROOM]->setLockState(UNLOCKED);
    passages[BEDROOM_to_BATHROOM]->setVisibility(VISIBLE);
    passages[BEDROOM_to_BATHROOM]->setLocation_1(&bedroom);
    passages[BEDROOM_to_BATHROOM]->setLocation_2(&bathroom);
    passages[BEDROOM_to_BATHROOM]->setKey_type(ACCESS_LVL_1);
    // BEDROOM_HALLWAY_to_ELEVATOR_ONE
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setCode(BEDROOM_HALLWAY_to_ELEVATOR_ONE);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setLockState(LOCKED);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setVisibility(VISIBLE);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setLocation_1(&bedroom_hallway);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setLocation_2(&elevator_one);
    passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]->setKey_type(ACCESS_LVL_2);
    
    
    // --------------------------------------------------------------------------------------
    // elevators
    // --------------------------------------------------------------------------------------
    // ELEVATOR_ONE
    elevator_one.setCode(ELEVATOR_ONE);
    elevator_one.setName("ELEVATOR ONE");
    elevator_one.setExit_direction(WEST);
    elevator_one.setExit(FIRST_FLOOR, passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]);
    elevator_one.setCurrent_floor(FIRST_FLOOR);
    elevator_one.initButtons();

    
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
