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
    static Item llamaToken;
    static Key key_card_1;
    // ----- set variables ----- //
    
    // LLAMA_TOKEN
    llamaToken.setCode(LLAMA_TOKEN);
    llamaToken.setName("LLAMA TOKEN");
    llamaToken.setDescription("a small figure of a llama");
    llamaToken.setLocation(locations[LOBBY]);
    
    // KEY_CARD_1
    key_card_1.setCode(KEY_CARD_1);
    key_card_1.setName("KEY CARD 1");
    key_card_1.setDescription("a key card");
    key_card_1.setLocation(locations[SUBWAY_STATION]);
    key_card_1.setDoor_Type(ACCESS_LVL_1);


    // ----- set arrays ----- //
    physical_objects[LLAMA_TOKEN] = &llamaToken;
    physical_objects[KEY_CARD_1] = &key_card_1;
}
