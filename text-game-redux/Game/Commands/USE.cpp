//
//  USE.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "PhysicalObject.hpp"
#include "Location.hpp"
#include "Passage.hpp"
#include "Player.hpp"

// --------------------------------------------------------------------------------------------------
// USE
// --------------------------------------------------------------------------------------------------
int Game::theUSEcommand(){
    if(commands.at(0) == USE){
        
        // if the command is smaller than 4 , invalid command
        if(commands.size() < 4){
            return invalidCommand();
        }
        
        // if the second command is a physical_object
        if(isPhysicalObject(commands.at(1)) && isDirection(commands.at(2)) && isWord(commands.at(3))) {
            
            Direction* current_direction = directions[commands.at(2)];
            Word* current_word = words[commands.at(3)];
            PhysicalObject* current_object = physical_objects[commands.at(1)];
            
            // if the object is a key and the 4th command is EXIT
            if(isType<Key>(current_object) && current_word->getCode() == EXIT){
                Key* current_key = static_cast<Key*>(current_object);
                Passage* current_passage = 0;
                
                if(current_key->getLocation() != locations[INVENTORY]){
                    return invalidCommand();
                }
                
                // if the player is in an elevator
                if(isType<Elevator>(player->getLocation())){
                    Elevator* current_elevator = static_cast<Elevator*>(player->getLocation());
                    
                    if(current_elevator->getExit_direction() == current_direction->getCode()){
                        current_passage = current_elevator->getCurrent_exit();
                    }
                    else{
                        return noExit();
                    }
                }
                // if the player in a room
                else if(isType<Room>(player->getLocation())){
                    Room* current_room = static_cast<Room*>(player->getLocation());
                    current_passage = current_room->getExit(current_direction->getCode());
                }
                
                if(current_passage != 0){
                    if(current_passage->isVisible()){
                        if(current_passage->isUnlocked()){
                            cout << "that exit is already unlocked" << endl;
                            return false;
                        }
                        else {
                            if(current_key->canUnlock(current_passage)){
                                current_passage->setLockState(UNLOCKED);
                                cout << "you unlocked the " << current_direction->getName() << " exit" << endl;
                                return true;
                            }
                            else {
                                cout << "that key cannot unlock that door" << endl;
                                return false;
                            }
                        }
                    }
                    else {
                        return noExit();
                    }
                }
                else {
                    return noExit();
                }
                
                
            }
            
            // if the object is not a key or the 4th command is not EXIT
            else {
                return invalidCommand();
            }
        }
        
        // if the second command is not a physical_object
        else {
            return invalidCommand();
        }
        
    }
    else{
        return WRONG_COMMAND;
    }
}
