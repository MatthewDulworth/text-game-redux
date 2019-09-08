//
//  enactCommands.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// ------------------------------------------------------------------------------------------------------
// enactCommands
// ------------------------------------------------------------------------------------------------------
bool Game::enactCommands(){
    int return_value;
    last_successfull_action = NONE;
    
    // ----- no command entered ----- //
    if(commands.size() == 0){
        return invalidCommand();
    }
    
    // ----- GO ----- //
    return_value = theGOcommand();
    if(return_value != WRONG_COMMAND){
        if(return_value == true){
            last_successfull_action = GO;
            
        }
        return return_value;
    }

    // ----- LOOK ----- //
    return_value = theLOOKcommand();
    if(return_value != WRONG_COMMAND){
        if(return_value == true) last_successfull_action = LOOK;
        return return_value;
    }
    
    // ----- PRESS ----- //
    return_value = thePRESScommand();
    if(return_value != WRONG_COMMAND){
        if(return_value == true) last_successfull_action = PRESS;
        return return_value;
    }
    
    // ----- GET ----- //
    return_value = theGETcommand();
    if(return_value != WRONG_COMMAND){
        if(return_value == true) last_successfull_action = GET;
        return return_value;
    }

    // ----- DROP ----- //
    return_value = theDROPcommand();
    if(return_value != WRONG_COMMAND){
        if(return_value == true) last_successfull_action = DROP;
        return return_value;
    }
    
    // ----- USE ----- //
    return_value = theUSEcommand();
    if(return_value != WRONG_COMMAND){
        if(return_value == true) last_successfull_action = USE;
        return return_value;
    }
    
    // ----- no valid command entered ----- //
    return invalidCommand();
}
