//
//  loadSavedGame.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/23/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

void Game::loadNewGame(){
    adminClassesSetup();
    actionSetup();
    mapSetup();
    physicalObjectSetup();
}

void Game::loadSavedGame(){
    adminClassesSetup();
    actionSetup();
}
