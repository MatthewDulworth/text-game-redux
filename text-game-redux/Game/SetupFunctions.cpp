//
//  Game.cpp
//  text-game-redux
// Game setup methods.
//
//  Created by Matthew Dulworth on 3/28/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

// ------------------------------------------------
// setup
// ------------------------------------------------
// calls all setup functions
void Game::setup(){
    directionSetup();
    actionSetup();
    objectSetup();
    mapSetup();
}

// ------------------------------------------------
// directionSetup
// ------------------------------------------------
// populates the direction array
void Game::directionSetup(){
    
    // ----- object declarations ----- //
    static Direction north, south, east, west, up, down;
    
    // ----- set attributes ----- //
    // NORTH
    north.setCode(NORTH);
    north.setName("NORTH");
    // SOUTH
    south.setCode(SOUTH);
    south.setName("SOUTH");
    // EAST
    east.setCode(EAST);
    east.setName("EAST");
    // WEST
    west.setCode(WEST);
    west.setName("WEST");
    // UP
    up.setCode(UP);
    up.setName("UP");
    // DOWN
    down.setCode(DOWN);
    down.setName("DOWN");
    
    // ----- set array ----- //
    directions[NORTH] = &north;
    directions[SOUTH] = &south;
    directions[EAST] = &east;
    directions[WEST] = &west;
    directions[UP] = &up;
    directions[DOWN] = &down;
}

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

// ------------------------------------------------
// mapSetup
// ------------------------------------------------
// popluates the loctions and passages arrays
void Game::mapSetup(){
    
    // ----- object declarations ----- //
    static Room kitchen, bedroom;
    
    // ----- set attributes ----- //
    kitchen.setCode(KITCHEN);
    kitchen.setName("KITCHEN");
    
    // ----- set arrays ----- //
}

// ------------------------------------------------
// objectSetup
// ------------------------------------------------
// popluates the physical_objectss array
void Game::objectSetup(){
    
    // ----- object declarations ----- //
    static Money coins;
    static Key key;
    static Item waffle_bat;
    static Immovable desk;
    
    // ----- set attributes ----- //
    // COINS
    coins.setCode(COINS);
    coins.setName("COINS");
    coins.setWorth(0.25);
    // WAFFLE_BAT
    waffle_bat.setCode(WAFFLE_BAT);
    waffle_bat.setName("WAFFLE_BAT");
    // KEY
    key.setCode(KEY);
    key.setName("KEY");
    // DESK
    desk.setCode(DESK);
    desk.setName("DESK");
    
    // ----- set arrays ----- //
    physical_objects[COINS] = &coins;
    physical_objects[KEY] = &key;
    physical_objects[WAFFLE_BAT] = &waffle_bat;
    physical_objects[DESK] = &desk;
}







