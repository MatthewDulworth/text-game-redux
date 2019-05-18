//
//  directionSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// ------------------------------------------------------------------------------------------------------
// adminClassesSetup
// ------------------------------------------------------------------------------------------------------
// populates the direction array
void Game::adminClassesSetup(){
    
    // ------------------------------------------------
    // Directions
    // ------------------------------------------------
    
    // ----- declarations ----- //
    static Direction north, south, east, west;
    
    // ----- set variables ----- //
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
    
    // ----- set array ----- //
    directions[NORTH] = &north;
    directions[SOUTH] = &south;
    directions[EAST] = &east;
    directions[WEST] = &west;
    

    // ------------------------------------------------
    // Numbers
    // ------------------------------------------------
    
    // ----- declarations ----- //
    static Number one, two;
    
    // ----- set variables ----- //
    // ONE
    one.setCode(ONE);
    one.setName("ONE");
    one.setSynonym("1");
    // TWO
    two.setCode(TWO);
    two.setName("TWO");
    two.setSynonym("2");
    
    // ----- set array ----- //
    numbers[ONE] = &one;
    numbers[TWO] = &two;
}

