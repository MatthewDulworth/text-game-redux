//
//  Game.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

// calls all setup functions
void Game::setup(){
    directionSetup();
    actionSetup();
    physicalObjectSetup();
    mapSetup();
}

void Game::setPlayer_location(Room* new_room){
    player_location = new_room;
}
