//
//  GET.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// --------------------------------------------------------------------------------------------------
// GET
// --------------------------------------------------------------------------------------------------
int Game::theGETcommand(){
    if(commands.at(0) == GET){
        
        // if the command is only one word long, no valid command entered
        if(commands.size() == 1){
            return invalidCommand();
        }
        
        // if the second command is a physical object
        if(isPhysical_object(commands.at(1)) ){
            PhysicalObject* current_object = physical_objects[commands.at(1)];
            
            if(current_object->getLocation() == player_location){
                if(isType<Item>(current_object)){
                    Item* current_item = static_cast<Item*>(current_object);
                    current_item->moveTo(locations[INVENTORY]);
                    cout << current_item->getDescription() << " is now in your inventory" << endl;
                    return True;
                }
                else {
                    cout << "you cannot pick that up" << endl;
                    return False;
                }
            }
            else {
                return invalidCommand();
            }
            
        }
        
        // if the second command is not a physical object
        else {
            return invalidCommand();
        }
    }
    
    // if the first command is not GET
    else {
        return Neither;
    }
}