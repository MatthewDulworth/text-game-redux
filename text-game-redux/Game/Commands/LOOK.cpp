//
//  LOOK.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "Location.hpp"
#include "Passage.hpp"
#include "PhysicalObject.hpp"

// --------------------------------------------------------------------------------------------------
// LOOK
// --------------------------------------------------------------------------------------------------
int Game::theLOOKcommand(){
    if(commands.at(0) == LOOK){
        
        // if the player is in an elevator 
        if( isType<Elevator>(player_location)){
            Elevator* current_elevator = static_cast<Elevator*>(player_location);
            Passage* current_passage = current_elevator->getCurrent_exit();
            bool passage_flag = false;
            
            cout << "you are in " << current_elevator->getName() << endl;
            cout << "you are on floor: " << current_elevator->getCurrentFloorNumber() << endl;
            
            if(current_passage != 0){
                if(current_passage->isVisible()){
                    passage_flag = true;
                    cout << "the elevator doors open to the " << directions[current_elevator->getExit_direction()]->getName() << endl;
                    if( !(current_passage->isUnlocked()) ){
                        cout << "the elevator doors are locked" << endl;
                    }
                }
            }
            
            if(passage_flag == false){
                cout << "the elevator doors do not open on this floor" << endl;
            }
            
            for(int i=FLOORS_min; i<FLOORS_max; i++){
                if(current_elevator->buttonIsVisibile(i)){
                    cout << "there is an elevator button with a " << (i+1-100) << " on it" << endl;
                }
            }
        }
        
        // if the player is in a room
        else if(isType<Room>(player_location)){
            Room* current_room = static_cast<Room*>(player_location);
            cout << "you are in " << player_location->getDescription() << endl;
            
            for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
                Passage* current_passage = current_room->getExit(i);
                string lock;
                
                if(current_passage != 0){
                    if(current_passage->isVisible() ){
                        Location* target_location = getTargetLocation(current_passage, player_location);
                        
                        if(isType<Elevator>(target_location)){
                            
                            if(current_passage->isUnlocked() ){
                                lock = " ";
                            }else{
                                lock = " locked ";
                            }
                            cout << "there are" << lock << "elevator doors to the " << directions[i]->getName() << endl;
                        }
                        else {
                        
                            if(current_passage->isUnlocked() ){
                                lock = "n ";
                            }else{
                                lock = " locked ";
                            }
                            cout << "there is a" << lock << "exit to the " << directions[i]->getName() << endl;
                        }
                    }
                }
            }
            
            for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
                Direction* current_direction = directions[i];
                if(current_room->hasCallButton(i)){
                    cout << "there is an elevator call button on the " << current_direction->getName() << " wall" << endl;
                }
            }
        }
        
        // if the player is in neither
        else{
            cout << "ERROR: invalid room, LOOK command, enactCommands.cpp, line " << __LINE__ << endl;
            return false;
        }
        
        // output all physical object in the room
        for(int i=PHYSICAL_OBJECTS_min; i<PHYSICAL_OBJECTS_max; i++){
            if(physical_objects[i]->getLocation() == player_location){
                cout << "there is " << physical_objects[i]->getDescription() << endl;
            }
        }
        return true;
    }
    
    // if the first command is not LOOK
    else {
        return WRONG_COMMAND;
    }
}
