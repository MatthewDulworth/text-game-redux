//
//  Game.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// calls all setup methods
void Game::setup(){
    directionSetup();
    actionSetup();
    mapSetup();
    physicalObjectSetup();
}

// sets the players location
void Game::setPlayer_location(Location* new_location){
    player_location = new_location;
}

// moves the player through a passage
void Game::movePlayerThroughPassage(Passage* passage){
    Location* target_location = createTargetLocation(passage, player_location);
    player_location = target_location;
}

// creates a target location 
Location* Game::createTargetLocation(Passage* passage, Location* location){
    Location* target_location = 0;
    
    if(location == passage->getLocation_1()){
        target_location = passage->getLocation_2();
    }
    
    else if(location == passage->getLocation_2()){
        target_location = passage->getLocation_1();
    }
    
    return target_location;
}
