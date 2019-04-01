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
            

            cout << current_direction->getName() << endl; // NORTH
            cout << player_location->getName() << endl;   // KITCHEN
            
            // set current_passage
            Passage* current_passage = player_location->exitTo(current_direction->getCode());
            
            
            if(current_passage != 0 ){
                
                cout << "here_3\n";
                // set room_1 and room_2 to the rooms attached to current_passage
                Room* room_1 = player_location->exitTo(current_direction->getCode())->getRoom_1();
                Room* room_2 = player_location->exitTo(current_direction->getCode())->getRoom_2();
                
                // move player
                if(player_location == room_1){
                    player_location = room_2;
                    cout << player_location->getName() << endl;
                    return true;
                }
                else if(player_location == room_2){
                    player_location = room_1;
                    cout << player_location->getName() << endl;
                    return true;
                }
            }
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
                cout << "there is an exit to the" << directions[i]->getName() << endl;
            }
        }
        for(int i=0; i<PHYSICALOBJECTS; i++){
            if(physical_objects[i]->getLocation() == player_location){
                cout << "There is " << physical_objects[i]->getDescription() << endl;
            }
        }
        return true;
    }
    
    
    cout << "ERROR: No valid command entered.\n";
    return false;
}
