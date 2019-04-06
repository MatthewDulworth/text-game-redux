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
    mapSetup();
    physicalObjectSetup();
}

void Game::setPlayer_location(Room* new_room){
    player_location = new_room;
}

bool Game::movePlayerThroughPassage(Passage* passage){
    if(player_location == passage->getRoom_1() ){
        player_location = passage->getRoom_2();
        return true;
    }
    else if(player_location == passage->getRoom_2() ){
        player_location = passage->getRoom_1();
        return true;
    }
    else{
        return false;
    }
}
