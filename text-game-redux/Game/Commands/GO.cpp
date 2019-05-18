//
//  GO.cpp
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
// GO
// --------------------------------------------------------------------------------------------------
int Game::theGOcommand(){
    if(commands.at(0) == GO){
        
        // if the command is only one word long, no valid command entered
        if(commands.size() < 2){
            return invalidCommand();
        }
        
        // if the second command is a direction
        if(isDirection(commands.at(1))){
            Base* current_direction = directions[commands.at(1)];
            
            // if the player is in an elevator
            if( isType<Elevator>(player_location) ){
                Elevator* current_elevator = static_cast<Elevator*>(player_location);
                
                if(current_elevator->getExit_direction() == current_direction->getCode() ){
                    Passage* current_passage = current_elevator->getCurrent_exit();
                    
                    if(current_passage != 0){
                        if(current_passage->isVisible() ){
                            if(current_passage->isUnlocked() ){
                                movePlayerThroughPassage(current_passage);
                                cout << "you went " << current_direction->getName() << endl;
                                cout << "you are in " << player_location->getDescription() << endl;
                                return true;
                            }else{
                                cout << "this floor is locked" << endl;
                                return true;
                            }
                        }else{
                            return invalidCommand();
                        }
                    }
                    else {
                        cout << "ERROR: passage does not exist, GO command, enactCommands.cpp, line " << __LINE__ << endl;
                        return false;
                    }
                }
                else {
                    cout << "The elevator doors do not open in that direction" << endl;
                    return true;
                }
            }
            
            // if the player is in a room
            else if( isType<Room>(player_location) ){
                Room* current_room = static_cast<Room*>(player_location);
                Passage* current_passage = current_room->getExit( current_direction->getCode() );
                
                if(current_passage != 0){
                    if(current_passage->isVisible() ){
                        if(current_passage->isUnlocked() ){
                            
                            Location* target_location = getTargetLocation(current_passage, player_location);
                            if(isType<Elevator>(target_location)){
                                Elevator* target_elevator = static_cast<Elevator*>(target_location);
                                
                                if(target_elevator->getCurrent_floor() != current_room->getFloor() ){
                                    cout << target_elevator->getName() << " is not on your floor" << endl;
                                    return true;
                                }
                            }
                            movePlayerThroughPassage(current_passage);
                            cout << "you went " << current_direction->getName() << endl;
                            cout << "you are in " << player_location->getDescription() << endl;
                            return true;
                        }
                        else{
                            cout << "that door is locked" << endl;
                            return true;
                        }
                    }
                    else{
                        return invalidCommand();
                    }
                }
                else{
                    cout << "there is no exit in that direction" << endl;
                    return false;
                }
            }
            
            // ERROR: if the player is in neither
            else {
                cout << "ERROR: invalid room, GO command, enactCommands.cpp, line " << __LINE__ << endl;
                return false;
            }
            
        }
        
        // if the second command is not a direction
        else {
            return invalidCommand();
        }
        
    }
    
    // if the first command is not GO
    else {
        return WRONG_COMMAND;
    }
}
