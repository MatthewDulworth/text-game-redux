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
            
            if(current_passage != 0 ){
            
                // set room_1 and room_2 to the rooms attached to current_passage
                Room* room_1 = player_location->exitTo(current_direction->getCode())->getRoom_1();
                Room* room_2 = player_location->exitTo(current_direction->getCode())->getRoom_2();
                
                // move player
                if(player_location == room_1){
                    player_location = room_2;
                    return true;
                }
                else if(player_location == room_2){
                    player_location = room_1;
                    return true;
                }
                else{
                    cout << "ERROR: player location no connected to current passage, 'GO'" << endl;
                    return false;
                }
            }
            else{
                cout << "there is no exit: " << current_direction->getName() << endl;
                return false;
            }
        }
        else{
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
            if(player_location->exitTo(i) !=0){
                cout << "there is an exit to the " << directions[i]->getName() << endl;
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
