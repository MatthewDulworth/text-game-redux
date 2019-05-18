//
//  USE.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// --------------------------------------------------------------------------------------------------
// USE
// --------------------------------------------------------------------------------------------------
int Game::theUSEcommand(){
    if(commands.at(0) == USE){
        
        if(commands.size() == 1){
            return invalidCommand();
        }
        return true;
    }
    else{
        return WRONG_COMMAND;
    }
}
