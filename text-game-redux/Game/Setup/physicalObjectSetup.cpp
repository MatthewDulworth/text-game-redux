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
    llamaToken.setDescription("a small statue of a llama");
    llamaToken.setLocation(locations[SUBWAY_STATION]);
    llamaToken.setDetails("a small staatue of a llama\nhas MADE IN CHINA etched onto the underside");
    
    // KEY_CARD_1
    key_card_1.setCode(KEY_CARD_1);
    key_card_1.setName("ID");
    key_card_1.setDescription("an employee ID card");
    key_card_1.setDetails("a nondescript employee ID card with the logo of a company named LLAMACORP and the words 'access level 1' printed on it");
    key_card_1.setLocation(locations[INV]);


    // ----- set arrays ----- //
    physical_objects[LLAMA_TOKEN] = &llamaToken;
    physical_objects[KEY_CARD_1] = &key_card_1;
}
