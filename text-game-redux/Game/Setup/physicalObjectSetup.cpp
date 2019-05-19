//
//  PhysicalObjectSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "PhysicalObject.hpp"

// ------------------------------------------------------------------------------------------------------
// physicalObjectSetup
// ------------------------------------------------------------------------------------------------------
// popluates the physical_objectss array
void Game::physicalObjectSetup(){
    
    // ----- object declarations ----- //
    static Key silver_key;
    
    // ----- set variables ----- //
    silver_key.setCode(SILVER_KEY);
    silver_key.setName("SILVER");
    silver_key.setDescription("a silver key");
    silver_key.setDoor_Type(SILVER);
    silver_key.setLocation(locations[STREET]);

    // ----- set arrays ----- //
    physical_objects[SILVER_KEY] = &silver_key;
}
