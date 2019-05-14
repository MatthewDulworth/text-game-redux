//
//  enactCommands.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"


/*
 TO DO:
 
 add floor buttons in an elevator
 add ability to change floors
 add ability to exit elevators in GO
 
 */

// ------------------------------------------------------------------------------------------------------
// enactCommands method
// ------------------------------------------------------------------------------------------------------
bool Game::enactCommands(){
    
    
    // --------------------------------------------------------------------------------------------------
    // no command entered
    // --------------------------------------------------------------------------------------------------
    if(command.size() == 0){
        cout << "ERROR: No command entered.\n";
        return false;
    }
    
    
    // --------------------------------------------------------------------------------------------------
    // GO
    // --------------------------------------------------------------------------------------------------
    // if the player types "GO" *DIRECTION* and there is an unlocked, visible, passage in that direction, move the player through that passage
    
    if(command.at(0) == GO){
        
        Base* current_direction;
        
        // if the command is only one word long, no valid command entered
        if(command.size() == 1){
            cout << "No valid command entered" << endl;
            return false;
        }
        // otherwise set the current direction equal to the second command
        else{
            current_direction = directions[command.at(1)];
        }
        
        // ------------------------------------------------------------------------------
        // check direction : if the current direction exists and actually is a direction
        // ------------------------------------------------------------------------------
        if(isDirection(current_direction) ){
            
            
            // ---------------------------------------------------------
            // move player : player is in an elevator
            // ---------------------------------------------------------
            if( isElevator(player_location) ){
                Elevator* current_elevator = static_cast<Elevator*>(player_location);           // set the current elevator to the player location
                
                cout << current_elevator->getName() << " cannot move" << endl;
                
                
                
            }
            
            
            // ---------------------------------------------------------
            // move player : player is in a room
            // ---------------------------------------------------------
            else if( isRoom(player_location) ){
                
                Room* current_room = static_cast<Room*>(player_location);                           // set the current room to the player location
                Passage* current_passage = current_room->exitTo( current_direction->getCode() );    // set the current passage to the passage in current direction of the current room
                
                
                // -------------------------------------
                if(current_passage != 0){                   // check to see that the current passage exists
                    if(current_passage->isVisible() ){      // check to see that the current passage is visible
                        
                        // if the current passage is locked, inform the player
                        if(current_passage->isLocked() ){
                            cout << "that door is locked\n";
                            return false;
                        }
                        
                        // if the current passage is not locked, move the player throught the current passage
                        else{
                            movePlayerThroughPassage(current_passage);
                            cout << "you went " << current_direction->getName() << endl;
                            return true;
                        }
                        
                        
                    }
                }
                // -------------------------------------
                
                // if the current passage does not exist, inform the player
                else {
                    cout << "there is no exit: " << current_direction->getName() << endl;
                    return false;
                }
            }
            
            
            // ---------------------------------------------------------
            // ERROR : player is not in an elevator or a room
            // ---------------------------------------------------------
            else {
                cout << "ERROR: invalid room, GO command, enactCommands.cpp, line " << __LINE__ << endl;
                return false;
            }
        }
        
        
        // ------------------------------------------------------------------------------
        // check direction : current_direction is not a valid direction
        // ------------------------------------------------------------------------------
        else {
            cout << "invalid direction" << endl;
            return false;
        }
        
    }
    // --------------------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    // --------------------------------------------------------------------------------------------------
    // LOOK
    // --------------------------------------------------------------------------------------------------
    // if the player types "LOOK", output all visible exits and all objects in the room
    
    if(command.at(0) == LOOK){
        
        
        // ---------------------------------------------------------
        // output exits : if the player is in an elevator
        // ---------------------------------------------------------
        if( isElevator(player_location) ){
            
            // set the current elevator to the player location
            Elevator* current_elevator = static_cast<Elevator*>(player_location);
            
            cout << "you are in " << current_elevator->getName() << endl;
            cout << "you are on floor: " << current_elevator->getFloor() << endl;
            cout << "the elevator doors open to the " << directions[current_elevator->getExit_direction()]->getName() << endl;
            
        }
        
        
        // ---------------------------------------------------------
        // output exits : if the player is in a room
        // ---------------------------------------------------------
        else if( isRoom(player_location) ){
        
            // output the description of the location
            cout << "You are in " << player_location->getDescription() << endl;
            
            
            // loop once for each direction
            for(int i=0; i<DIRECTIONS; i++){
                
                Room* current_room = static_cast<Room*>(player_location);   // point current_room to the player location
                Passage* current_passage = current_room->exitTo(i);         // set the current passage equal to the exit of the player location at i
                string lock;
            
                
                // ---------------------------------------------
                if(current_passage != 0){                   // check to see if the current passage exists
                    if(current_passage->isVisible() ){      // check to see if the current passage is visible
                        
                        // -----------------------------
                        // if the passage is locked, set the lock string equal to locked
                        if(current_passage->isLocked() ){
                            lock = " locked ";
                        }
                        
                        // if the passage isnot locked, don't set the lock string equal to locked
                        else {
                            lock = "n ";
                        }
                        
                        // output the exit state
                        cout << "there is a" << lock << "exit to the " << directions[i]->getName() << endl;
                        // -----------------------------
                        
                    }
                }
                // --------------------------------------------
                
                
            }
        }
        
    
        // ---------------------------------------------------------
        // ERROR : if the player is not in an elevator or a room
        // ---------------------------------------------------------
        else{
            cout << "ERROR: invalid room, LOOK command, enactCommands.cpp, line " << __LINE__ << endl;
            return false;
        }
        
        
        // ---------------------------------------------------------
        // output the descriptions of all the objects in the room
        // ---------------------------------------------------------
        for(int i=0; i<PHYSICALOBJECTS; i++){
            if(physical_objects[i]->getLocation() == player_location){
                cout << "there is " << physical_objects[i]->getDescription() << endl;
            }
        }
        
        
        return true;
    }
    // --------------------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    // --------------------------------------------------------------------------------------------------
    // no valid command entered
    // --------------------------------------------------------------------------------------------------
    cout << "No valid command entered.\n";
    return false;
}
