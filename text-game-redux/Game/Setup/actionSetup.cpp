//
//  actionSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "AdminClasses.hpp"

// ------------------------------------------------------------------------------------------------------
// actionSetup
// ------------------------------------------------------------------------------------------------------
// popluates the actions array
void Game::actionSetup(){
    
    // ----- create objects ----- //
    for(int i = ACTIONS_min; i<ACTIONS_max; i++){
        actions[i] = new Action();
    }
    
    // ----- set attributes ----- //
    // GO
    actions[GO]->setCode(GO);
    actions[GO]->setName("GO");
    actions[GO]->setSynonym("MOVE");
    // LOOK
    actions[LOOK]->setCode(LOOK);
    actions[LOOK]->setName("LOOK");
    actions[LOOK]->setSynonym("LOOK");
    // PRESS
    actions[PRESS]->setCode(PRESS);
    actions[PRESS]->setName("PRESS");
    actions[PRESS]->setSynonym("PUSH");
    // GET
    actions[GET]->setCode(GET);
    actions[GET]->setName("GET");
    actions[GET]->setSynonym("PICK");
    // DROP
    actions[DROP]->setCode(DROP);
    actions[DROP]->setName("DROP");
    actions[DROP]->setSynonym("DROP");
    // USE
    actions[USE]->setCode(USE);
    actions[USE]->setName("USE");
    actions[USE]->setSynonym("USE");
}
