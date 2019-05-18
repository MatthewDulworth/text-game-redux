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
    
    // ----- object declarations ----- //
    static Action go, look, press, get, drop, use;
    
    // ----- set attributes ----- //
    // GO
    go.setCode(GO);
    go.setName("GO");
    // LOOK
    look.setCode(LOOK);
    look.setName("LOOK");
    // PRESS
    press.setCode(PRESS);
    press.setName("PRESS");
    // GET
    get.setCode(GET);
    get.setName("GET");
    // DROP
    drop.setCode(DROP);
    drop.setName("DROP");
    //USE
    use.setCode(USE);
    use.setName("USE");
    
    // ----- set array ----- //
    actions[GO] = &go;
    actions[LOOK] = &look;
    actions[PRESS] = &press;
    actions[GET] = &get;
    actions[DROP] = &drop;
    actions[USE] = &use;
}
