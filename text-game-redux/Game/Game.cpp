//
//  Game.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "Player.hpp"
#include "Location.hpp"
#include "Passage.hpp"
#include "PhysicalObject.hpp"
#include "AdminClasses.hpp"

// destructor
Game::~Game(){
    delete player;
    
    for(int i=PASSAGES_min; i<PASSAGES_max; i++){
        delete passages[i];
    }
    
    for(int i=ACTIONS_min; i<ACTIONS_max; i++){
        delete actions[i];
    }
    
    for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
        delete directions[i];
    }
    
    for(int i=COMMAND_WORDS_min; i<COMMAND_WORDS_max; i++){
        delete words[i];
    }
    
    for(int i=NUMBERS_min; i<NUMBERS_max; i++){
        delete numbers[i];
    }
}

// moves the player through a passage
void Game::movePlayerThroughPassage(Passage* passage){
    Location* target_location = getTargetLocation(passage, player->getLocation());
    player->moveTo(target_location);
}

bool Game::invalidCommand(){
    cout << "no valid command entered" << endl;
    return false;
}

bool Game::noExit(){
    cout << "there is no exit in that direction" << endl;
    return false;
}

