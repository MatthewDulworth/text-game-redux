//
//  USE.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "PhysicalObject.hpp"

// --------------------------------------------------------------------------------------------------
// USE
// --------------------------------------------------------------------------------------------------
int Game::theUSEcommand(){
    if(commands.at(0) == USE){
        
        // if the command is only one word long, invalid command
        if(commands.size() == 1){
            return invalidCommand();
        }
        
        if(isPhysical_object(commands.at(1)) ){
            return true;
        }
        
        else {
            return invalidCommand();
        }
        
    }
    else{
        return WRONG_COMMAND;
    }
}
