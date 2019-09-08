//
//  INSPECT.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 9/8/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "PhysicalObject.hpp"
#include "Player.hpp"

int Game::theINSPECTcommand(){
    if(commands.at(0) == INSPECT){
        
        if(commands.size() < 2){
            return invalidCommand();
        }
        
        if(isPhysicalObject(commands.at(1)) ){
            PhysicalObject* current_object = physical_objects[commands.at(1)];
            if(current_object->getLocation() == player->getLocation() || current_object->getLocation() == locations[INV]){
                cout << current_object->getDetails() << endl;
                return true;
            }
            else{
                return invalidCommand();
            }
        }
        else{
            return invalidCommand();
        }
    }
    else{
        return WRONG_COMMAND;
    }
}
