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
 
 add elevator call buttons to rooms that can call elevators
 add ability to change floors
 
 */

// ------------------------------------------------------------------------------------------------------
// enactCommands method
// ------------------------------------------------------------------------------------------------------
bool Game::enactCommands(){
    
    
    // --------------------------------------------------------------------------------------------------
    // no command entered
    // --------------------------------------------------------------------------------------------------
    if(command.size() == 0){
        cout << "no command entered" << endl;;
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
            cout << "no valid command entered" << endl;
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
                
                // set the current elevator to the player location
                Elevator* current_elevator = static_cast<Elevator*>(player_location);
                

                // -------------------------------------------
                // check direction : elevator doors do open
                // -------------------------------------------
                if(current_elevator->getExit_direction() == current_direction->getCode() ){
                    Passage* current_passage = current_elevator->getCurrent_exit();
                    
                    
                    if(current_passage != 0){                   // check to see that the current passage exists
                        if(current_passage->isVisible() ){      // check to see that the current passage is visible
                            
                            // if the passage is unlocked, move the player through it
                            if(current_passage->isUnlocked() ){
                                movePlayerThroughPassage(current_passage);
                                cout << "you went " << current_direction->getName() << endl;
                                return true;
                                
                            }
                            
                            // otherwise, inform the player that it is locked
                            else{
                                cout << "this floor is locked" << endl;
                                return true;
                            }
                            
                        }
                    }
                    else {
                        cout << "ERROR: passage does not exist, GO command, enactCommands.cpp, line " << __LINE__ << endl;
                        return false;
                    }
                    
                }
                
            
                // -------------------------------------------
                // check direction : elevator doors don't open
                // -------------------------------------------
                else{
                    cout << "The elevator doors do not open in that direction" << endl;
                    return true;
                }
            }
            
            
            // ---------------------------------------------------------
            // move player : player is in a room
            // ---------------------------------------------------------
            else if( isRoom(player_location) ){
                
                // set current_room to player_location
                // set current_passage to the current_direction passage of current_room
                Room* current_room = static_cast<Room*>(player_location);
                Passage* current_passage = current_room->exitTo( current_direction->getCode() );
                
                
                // -------------------------------------
                if(current_passage != 0){                   // check to see that the current passage exists
                    if(current_passage->isVisible() ){      // check to see that the current passage is visible
                        
                        
                        // ----------
                        // if the current passage is not locked
                        if(current_passage->isUnlocked() ){
                            
                            // check to see if the player is trying to enter an elevator not on the same floor
                            Location* target_location = createTargetLocation(current_passage, player_location);
                            if(isElevator(target_location)){
                                Elevator* target_elevator = static_cast<Elevator*>(target_location);
                                
                                if(target_elevator->getCurrent_floor() != current_room->getFloor() ){
                                    cout << target_elevator->getName() << " is not on your floor" << endl;
                                    return true;
                                }
                            }
                            
                            // move the player
                            movePlayerThroughPassage(current_passage);
                            cout << "you went " << current_direction->getName() << endl;
                            return true;
                        }
                        // ----------
                        
                        
                        // if the current passage is locked, inform the player
                        else{
                            cout << "that door is locked\n";
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
            cout << "you are on floor: " << current_elevator->getCurrent_floor() + 1 << endl;
            cout << "the elevator doors open to the " << directions[current_elevator->getExit_direction()]->getName() << endl;
            
            
            for(int i=0; i<FLOORS; i++){
                if(current_elevator->buttonIsVisibile(i)){
                    cout << "there is an elevator button with a: " << i+1 << " on it" << endl;
                }
            }
            
            
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
                        // if the passage is unlocked
                        if(current_passage->isUnlocked() ){
                            lock = "n ";
                        }
                        
                        // if the passage is locked
                        else {
                            lock = " locked ";
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
    cout << "no valid command entered.\n";
    return false;
}
