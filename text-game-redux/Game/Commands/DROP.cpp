//
//  DROP.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// --------------------------------------------------------------------------------------------------
// DROP
// --------------------------------------------------------------------------------------------------
int Game::theDROPcommand(){
    if(commands.at(0) == DROP){
        
        // if the command is only one word long, no valid command entered
        if(commands.size() == 1){
            return invalidCommand();
        }
        
        // if the second command is a physical object
        if(isPhysical_object(commands.at(1)) ){
            PhysicalObject* current_object = physical_objects[commands.at(1)];
            
            // if the object is in the player's inventory
            if(current_object->getLocation() == locations[INVENTORY] ){
                if(isType<Item>(current_object)){
                    Item* current_item = static_cast<Item*>(current_object);
                    current_item->moveTo(player_location);
                    cout << "you dropped " << current_item->getDescription() << endl;
                    return True;
                }
                else{
                    cout << "ERROR: non item in inventory " << endl;
                    return False;
                }
            }
            else{
                return invalidCommand();
            }
        }
        
        // if the second command is not a physical_object
        else {
            return invalidCommand();
        }
    }
    
    // if the first command is not DROP
    else{
        return Neither;
    }
}
