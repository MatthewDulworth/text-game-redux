//
//  I.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 9/8/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "PhysicalObject.hpp"
#include "Location.hpp"

int Game::theINVENTORYcommand(){
    if(commands.at(0) == INVENTORY){
        
        cout << "your inventory contains:" << endl;
        for(int i=PHYSICAL_OBJECTS_min; i<PHYSICAL_OBJECTS_max; i++){
            if(physical_objects[i]->getLocation()->getCode() == INV){
                cout << "\t" << physical_objects[i]->getDescription() << endl;
            }
        }
        return true;
    }
    else{
        return WRONG_COMMAND;
    }
}
