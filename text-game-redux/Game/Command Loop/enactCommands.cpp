//
//  enactCommands.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"


/*
 TO DO:
 
 Add USE command
 Add ability to unlock doors
 rework elevator call button PRESS command
 
 */

// ------------------------------------------------------------------------------------------------------
// enactCommands method
// ------------------------------------------------------------------------------------------------------
bool Game::enactCommands(){
    int return_value;
    
    // ------------------------------------------------
    // no command entered
    // ------------------------------------------------
    if(commands.size() == 0){
        return invalidCommand();
    }
    
    // ------------------------------------------------
    // GO
    // ------------------------------------------------
    return_value = theGOcommand();
    if(return_value != WRONG_COMMAND){
        return return_value;
    }

    // ------------------------------------------------
    // LOOK
    // ------------------------------------------------
    return_value = theLOOKcommand();
    if(return_value != WRONG_COMMAND){
        return return_value;
    }
    
    // ------------------------------------------------
    // PRESS
    // ------------------------------------------------
    return_value = thePRESScommand();
    if(return_value != WRONG_COMMAND){
        return return_value;
    }
    
    // ------------------------------------------------
    // GET
    // ------------------------------------------------
    return_value = theGETcommand();
    if(return_value != WRONG_COMMAND){
        return return_value;
    }

    // ------------------------------------------------
    // DROP
    // ------------------------------------------------
    return_value = theDROPcommand();
    if(return_value != WRONG_COMMAND){
        return return_value;
    }
    
    // ------------------------------------------------
    // DROP
    // ------------------------------------------------
    return_value = theUSEcommand();
    if(return_value != WRONG_COMMAND){
        return return_value;
    }

    // ------------------------------------------------
    // no valid command entered
    // ------------------------------------------------
    return invalidCommand();
}
