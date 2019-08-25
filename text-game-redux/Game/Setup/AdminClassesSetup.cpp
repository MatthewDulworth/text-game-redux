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
    
    // ----- create new objects ----- //
    for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
        directions[i] = new Direction();
    }
    
    // ----- set variables ----- //
    // NORTH
    directions[NORTH]->setCode(NORTH);
    directions[NORTH]->setName("NORTH");
    // SOUTH
    directions[SOUTH]->setCode(SOUTH);
    directions[SOUTH]->setName("SOUTH");
    // EAST
    directions[EAST]->setCode(EAST);
    directions[EAST]->setName("EAST");
    // WEST
    directions[WEST]->setCode(WEST);
    directions[WEST]->setName("WEST");
    
    
    // ------------------------------------------------
    // Numbers
    // ------------------------------------------------
    
    // ----- create new objects ----- //
    for(int i=NUMBERS_min; i<NUMBERS_max; i++){
        numbers[i] = new Number();
    }
    
    // ----- set variables ----- //
    // ONE
    numbers[ONE]->setCode(ONE);
    numbers[ONE]->setName("ONE");
    numbers[ONE]->setSynonym("1");
    // TWO
    numbers[TWO]->setCode(TWO);
    numbers[TWO]->setName("TWO");
    numbers[TWO]->setSynonym("2");
    // THREE
    numbers[THREE]->setCode(THREE);
    numbers[THREE]->setName("THREE");
    numbers[THREE]->setSynonym("3");
    // FOUR
    numbers[FOUR]->setCode(FOUR);
    numbers[FOUR]->setName("FOUR");
    numbers[FOUR]->setSynonym("4");
    // FIVE
    numbers[FIVE]->setCode(FIVE);
    numbers[FIVE]->setName("FIVE");
    numbers[FIVE]->setSynonym("5");
    // SIX
    numbers[SIX]->setCode(SIX);
    numbers[SIX]->setName("SIX");
    numbers[SIX]->setSynonym("6");
    // SEVEN
    numbers[SEVEN]->setCode(SEVEN);
    numbers[SEVEN]->setName("SEVEN");
    numbers[SEVEN]->setSynonym("7");
}
