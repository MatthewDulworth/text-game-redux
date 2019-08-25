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
    static AdminLocation inventory, trash;
    locations[INVENTORY] = &inventory;
    locations[TRASH] = &trash;
    
    // first floor
    static Room atrium, atrium_hallway;
    //static Elevator elevator_one;
    
    // fill array;
    locations[ATRIUM] = &atrium;
    locations[ATRIUM_HALLWAY] = &atrium_hallway;
    // locations[ELEVATOR_ONE] = &elevator_one;
    
    
    // ------------------------------------------------
    // passages
    // ------------------------------------------------
    for(int i = PASSAGES_min; i<PASSAGES_max; i++){
        passages[i] = new Passage();
    }
    
    
    // ------------------------------------------------
    // charecters
    // ------------------------------------------------
    player = new Player(&atrium);
    
    
    // --------------------------------------------------------------------------------------
    // rooms
    // --------------------------------------------------------------------------------------
    // ATRIUM
    atrium.setCode(ATRIUM);
    atrium.setName("ATRIUM");
    atrium.setDescription("the atrium");
    atrium.setFloor(FIRST_FLOOR);
    atrium.setExit(SOUTH, passages[ATRIUM_to_ATRIUM_HALLWAY]);
    
    // ATRIUM_HALLWAY
    atrium_hallway.setCode(ATRIUM_HALLWAY);
    atrium_hallway.setName("ATRIUM_HALLWAY");
    atrium_hallway.setDescription("hallway");
    atrium_hallway.setFloor(FIRST_FLOOR);
    atrium_hallway.setExit(NORTH, passages[ATRIUM_to_ATRIUM_HALLWAY]);
    

    // --------------------- -----------------------------------------------------------------
    // passages
    // --------------------------------------------------------------------------------------
    // ATRIUM_to_ATRIUM_HALLWAY
    passages[ATRIUM_to_ATRIUM_HALLWAY]->setCode(ATRIUM_to_ATRIUM_HALLWAY);
    passages[ATRIUM_to_ATRIUM_HALLWAY]->setLockState(UNLOCKED);
    passages[ATRIUM_to_ATRIUM_HALLWAY]->setVisibility(VISIBLE);
    passages[ATRIUM_to_ATRIUM_HALLWAY]->setLocation_1(&atrium);
    passages[ATRIUM_to_ATRIUM_HALLWAY]->setLocation_2(&atrium_hallway);
    passages[ATRIUM_to_ATRIUM_HALLWAY]->setKey_type(ACCESS_LVL_1);
    
    
    // --------------------------------------------------------------------------------------
    // elevators
    // --------------------------------------------------------------------------------------
    // ELEVATOR_ONE
//    elevator_one.setCode(ELEVATOR_ONE);
//    elevator_one.setName("ELEVATOR ONE");
//    elevator_one.setExit_direction(WEST);
//    elevator_one.setExit(FIRST_FLOOR, passages[BEDROOM_HALLWAY_to_ELEVATOR_ONE]);
//    elevator_one.setCurrent_floor(FIRST_FLOOR);
//    elevator_one.initButtons();

    
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
