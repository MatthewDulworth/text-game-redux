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
    go.setSynonym("GO");
    // LOOK
    look.setCode(LOOK);
    look.setName("LOOK");
    look.setSynonym("LOOK");
    // PRESS
    press.setCode(PRESS);
    press.setName("PRESS");
    press.setSynonym("PUSH");
    // GET
    get.setCode(GET);
    get.setName("GET");
    get.setSynonym("GET");
    // DROP
    drop.setCode(DROP);
    drop.setName("DROP");
    drop.setSynonym("DROP");
    //USE
    use.setCode(USE);
    use.setName("USE");
    use.setSynonym("USE");
    
    // ----- set array ----- //
    actions[GO] = &go;
    actions[LOOK] = &look;
    actions[PRESS] = &press;
    actions[GET] = &get;
    actions[DROP] = &drop;
    actions[USE] = &use;
}
