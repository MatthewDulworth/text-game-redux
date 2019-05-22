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
    directions[NORTH] = new Direction();
    directions[SOUTH] = new Direction();
    directions[EAST] = new Direction();
    directions[WEST] = new Direction();
    
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
    numbers[ONE] = new Number();
    numbers[TWO] = new Number();
    numbers[THREE] = new Number();
    numbers[FOUR] = new Number();
    numbers[FIVE] = new Number();
    numbers[SIX] = new Number();
    numbers[SEVEN] = new Number();
    
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

    
    // ------------------------------------------------
    // WORDS
    // ------------------------------------------------
    
    // ----- create new objects ----- //
    words[EXIT] = new Word();
    words[ELEVATOR] = new Word();
    
    // ----- set variables ----- //
    // EXIT
    words[EXIT]->setCode(EXIT);
    words[EXIT]->setName("EXIT");
    // ELEVATOR
    words[ELEVATOR]->setCode(ELEVATOR);
    words[ELEVATOR]->setName("ELEVATOR");
}

