//
//  Game.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "Player.hpp"

// calls all setup methods
void Game::setup(){
    adminClassesSetup();
    actionSetup();
    mapSetup();
    physicalObjectSetup();
}

// moves the player through a passage
void Game::movePlayerThroughPassage(Passage* passage){
    Location* target_location = getTargetLocation(passage, player->getLocation());
    player->changeLocation(target_location);
}

bool Game::invalidCommand(){
    cout << "no valid command entered" << endl;
    return false; 
}

bool Game::noExit(){
    cout << "there is no exit in that direction" << endl;
    return false;
}

