//
//  INSPECT.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 9/8/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "PhysicalObject.hpp"

int Game::theINSPECTcommand(){
    if(commands.at(0) == INSPECT){
        
        if(commands.size() < 2){
            return invalidCommand();
        }
        
        if(isPhysicalObject(commands.at(1)) ){
            PhysicalObject* current_object = physical_objects[commands.at(1)];
        
            cout << current_object->getDescription() << endl;
            return true;
        }
        else{
            return invalidCommand();
        }
    }
    else{
        return WRONG_COMMAND;
    }
}
