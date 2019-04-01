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
