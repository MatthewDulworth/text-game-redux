//
//  Game.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/28/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

// ------------------------------------------------
// Game setup methods
// ------------------------------------------------

// popluates the loctions and passages arrays
void Game::mapSetup(){
    
}

// popluates the physical_objectss array
void Game::objectSetup(){
    
    static Money coins;
    coins.setCode(COINS);
    coins.setName("COINS");
    coins.setWorth(0.25);
    
    static Item waffle_bat;
    waffle_bat.setCode(WAFFLE_BAT);
    waffle_bat.setName("WAFFLE_BAT");
    
    static Immovable desk;
    desk.setCode(DESK);
    desk.setName("DESK");
}

// popluates the actions array
void Game::actionSetup(){
    
    static Action go, look;
    go.setCode(GO);
    go.setName("GO");
    look.setCode(LOOK);
    look.setName("LOOK");
    
    actions[GO] = &go;
    actions[LOOK] = &look;
}

// populates the direction array
void Game::directionSetup(){
    
    static Direction north, south, east, west, up, down;
    north.setCode(NORTH);
    north.setName("NORTH");
    south.setCode(SOUTH);
    south.setName("SOUTH");
    east.setCode(EAST);
    east.setName("EAST");
    west.setCode(WEST);
    west.setName("WEST");
    up.setCode(UP);
    up.setName("UP");
    down.setCode(UP);
    down.setName("UP");
    
    directions[NORTH] = &north;
    directions[SOUTH] = &south;
    directions[EAST] = &east;
    directions[WEST] = &west;
    directions[UP] = &up;
    directions[DOWN] = &down;
}

// calls all setup functions
void Game::setup(){
    directionSetup();
    actionSetup();
    objectSetup();
    mapSetup();
}

