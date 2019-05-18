//
//  PhysicalObjectSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// ------------------------------------------------
// objectSetup
// ------------------------------------------------
// popluates the physical_objectss array
void Game::physicalObjectSetup(){
    
    // ----- object declarations ----- //
    static Key simple_key_1;
    // ----- set attributes ----- //
    simple_key_1.setCode(SIMPLE_KEY_1);
    simple_key_1.setName("SILVER");
    simple_key_1.setDescription("a silver key");
    simple_key_1.setDoor_Type(SIMPLE);
    simple_key_1.setLocation(locations[LOBBY]);

    // ----- set arrays ----- //
    physical_objects[SIMPLE_KEY_1] = &simple_key_1;
    
}
