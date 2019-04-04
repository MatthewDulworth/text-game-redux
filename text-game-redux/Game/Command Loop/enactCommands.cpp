//
//  enactCommands.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

// -----------------------------------------------------------
// enactCommands method
// -----------------------------------------------------------
bool Game::enactCommands(){
    
    // ------------------------------------------------
    // no command entered
    // ------------------------------------------------
    if(commands.size() == 0){
        cout << "ERROR: No command entered.\n";
        return false;
    }
    
    // ------------------------------------------------
    // GO
    // ------------------------------------------------
    if(commands.at(0) == GO){
        
        // set current_direction
        Base* current_direction = directions[commands.at(1)];
        
        if(isDirection(current_direction) ){
            
            // set current_passage
            Passage* current_passage = player_location->exitTo(current_direction->getCode());
            
            if(current_passage != 0){ // if current passage exists
                if( current_passage->isVisible() ){ // if current passage is visible to the player
                    
                    if( isOpenPassage(current_passage) ){ 
                        movePlayerThroughPassage(current_passage);
                        return true;
                    }
                    else if( isRegularDoor(current_passage) ){
                        if(current_passage->isLocked() ) cout << "that door is locked\n";
                        else movePlayerThroughPassage(current_passage);
                        return true;
                    }
                    else if( isTrapdoor(current_passage) ){
                        if(current_passage->isLocked() ) cout << "that trapdoor is locked\n";
                        else movePlayerThroughPassage(current_passage);
                        return true;
                    }
                    else {
                        cout << "ERROR: undefined passage type, 'GO' \n";
                        return false;
                    }
                    
                }
            } else{
                cout << "there is no exit: " << current_direction->getName() << endl;
                return false;
            }
            
        } else{
            cout << "invalid direction" << endl;
            return false;
        }
    }
    
    // ------------------------------------------------
    // LOOK
    // ------------------------------------------------
    if(commands.at(0) == LOOK){
        cout << "You are in "; player_location->printDescription();
        cout << endl;

        for(int i=0; i<DIRECTIONS; i++){
            Passage* current_passage = player_location->exitTo(i);
            string lock;
            
            if(current_passage != 0){
                if(current_passage->isLocked() ){
                    lock = "locked ";
                } else {
                    lock = "";
                }
                
                if(i == UP || i == DOWN) {
                    cout << "there is a " << lock << " ladder going " << directions[i]->getName() << endl;
                } else{
                    cout << "there is a " << lock << " door to the " << directions[i]->getName() << endl;
                }
            }
            
        }
        for(int i=0; i<PHYSICALOBJECTS; i++){
            if(physical_objects[i]->getLocation() == player_location){
                cout << "there is " << physical_objects[i]->getDescription() << endl;
            }
        }
        return true;
    }
    
    
    cout << "ERROR: No valid command entered.\n";
    return false;
}
