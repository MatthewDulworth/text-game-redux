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
    // if the player types "GO" *DIRECTION* and there is an unlocked, visible, passage in that direction, move the player through that passage
    if(commands.at(0) == GO){
        Base* current_direction = directions[commands.at(1)];
        
        if(isDirection(current_direction) ){
            // ----------------------------------------------------------------------------
            if( isElevator(player_location) ){
                Elevator* current_elevator = static_cast<Elevator*>(player_location);
                
                if(current_direction->getCode() == current_elevator->getExit_direction() ){
                    Passage* current_passage = current_elevator->getCurrent_exit();
                    movePlayerThroughPassage(current_passage);
                } else {
                    cout << " the elevator doors do not open in that direction ";
                    return false;
                }
            }
            // ----------------------------------------------------------------------------
            else if( isRoom(player_location) ){
                Room* current_room = static_cast<Room*>(player_location);
                Passage* current_passage = current_room->exitTo( current_direction->getCode() );
                
                if(current_passage != 0){
                    if(current_passage->isVisible() ){
                        if(current_passage->isLocked() ){
                            cout << "that door is locked\n";
                            return false;
                        } else{
                            movePlayerThroughPassage(current_passage);
                            return true;
                        }
                    }
                } else {
                    cout << "there is no exit: " << current_direction->getName() << endl;
                    return false;
                }
            }
            // ----------------------------------------------------------------------------
            else {  // if the location the player is in is somehow not an Elevator or a Room, this should never happen.
                cout << "ERROR: invalid room, GO command, enactCommands.cpp, line " << __LINE__ << endl;
                return false;
            }
            // ----------------------------------------------------------------------------
        } else {
            cout << "invalid direction" << endl;
            return false;
        }
    } // end GO
    
    // ------------------------------------------------
    // LOOK
    // ------------------------------------------------
    // if the player types "LOOK", output all visible exits and all objects in the room
    if(commands.at(0) == LOOK){
        cout << "You are in " << player_location->getDescription() << endl;
        // ----------------------------------------------------------------------------
        if( isElevator(player_location) ){ // if the player is in an elevator
            Elevator* current_elevator = static_cast<Elevator*>(player_location);
            cout << "you are on floor: " << current_elevator->getFloor() << endl;
            cout << "the elevator doors open to the " << directions[current_elevator->getExit_direction()]->getName();
        }
        // ----------------------------------------------------------------------------
        else if( isRoom(player_location) ){ // if the player is in a room
            for(int i=0; i<DIRECTIONS; i++){
                Room* current_room = static_cast<Room*>(player_location);
                Passage* current_passage = current_room->exitTo(i);
                string lock;
            
                if(current_passage != 0){
                    if(current_passage->isVisible() ){
                        // -----------------------------
                        if(current_passage->isLocked() ){
                            lock = "locked ";
                        } else {
                            lock = "n ";
                        }
                        // -----------------------------
                        if(i == UP || i == DOWN) {
                            cout << "there is a" << lock << "ladder going " << directions[i]->getName() << endl;
                        } else{
                            cout << "there is a" << lock << "exit to the " << directions[i]->getName() << endl;
                        }
                        // -----------------------------
                    }
                }
            }
        }
        // ----------------------------------------------------------------------------
        else{   // if the location the player is in is somehow not an Elevator or a Room, this should never happen.
            cout << "ERROR: invalid room, LOOK command, enactCommands.cpp, line " << __LINE__ << endl;
            return false;
        }
        // ----------------------------------------------------------------------------
        for(int i=0; i<PHYSICALOBJECTS; i++){   // output the descriptions of all the objects in the room.
            if(physical_objects[i]->getLocation() == player_location){
                cout << "there is " << physical_objects[i]->getDescription() << endl;
            }
        }
        // ----------------------------------------------------------------------------
        return true;
    }
    
    // ------------------------------------------------
    // no valid command entered 0
    // ------------------------------------------------
    cout << "ERROR: No valid command entered.\n";
    return false;
}
