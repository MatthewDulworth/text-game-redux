//
//  actionSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// ------------------------------------------------
// actionSetup
// ------------------------------------------------
// popluates the actions array
void Game::actionSetup(){
    
    // ----- object declarations ----- //
    static Action go, look;
    
    // ----- set attributes ----- //
    // GO
    go.setCode(GO);
    go.setName("GO");
    // LOOK
    look.setCode(LOOK);
    look.setName("LOOK");
    
    // ----- set array ----- //
    actions[GO] = &go;
    actions[LOOK] = &look;
}
