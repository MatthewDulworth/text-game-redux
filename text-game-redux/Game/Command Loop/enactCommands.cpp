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
 
 Add USE command
 Add ability to unlock doors
 
 */

// ------------------------------------------------------------------------------------------------------
// enactCommands method
// ------------------------------------------------------------------------------------------------------
bool Game::enactCommands(){
    
    
    // --------------------------------------------------------------------------------------------------
    // no command entered
    // --------------------------------------------------------------------------------------------------
    if(commands.size() == 0){
        cout << "no command entered" << endl;
        return false;
    }
    
    
    // --------------------------------------------------------------------------------------------------
    // GO
    // --------------------------------------------------------------------------------------------------
    // if the player types "GO" *DIRECTION* and there is an unlocked, visible, passage in that direction, move the player through that passage
    
    if(commands.at(0) == GO){
        
        // if the command is only one word long, no valid command entered
        if(commands.size() == 1){
            cout << "no valid command entered" << endl;
            return false;
        }
        
        // ------------------------------------------------------------------------------
        // check direction : if the current direction exists and actually is a direction
        // ------------------------------------------------------------------------------
        if(isDirection(commands.at(1)) ){
            
            // set the current direction equal to the second command
            Base* current_direction = directions[commands.at(1)];
            
            
            // ---------------------------------------------------------
            // move player : player is in an elevator
            // ---------------------------------------------------------
            if( isType<Elevator>(player_location) ){
                
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
                                cout << "you are in " << player_location->getDescription() << endl;
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
            else if( isType<Room>(player_location) ){
                
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
                            Location* target_location = getTargetLocation(current_passage, player_location);
                            if(isType<Elevator>(target_location)){
                                Elevator* target_elevator = static_cast<Elevator*>(target_location);
                                
                                if(target_elevator->getCurrent_floor() != current_room->getFloor() ){
                                    cout << target_elevator->getName() << " is not on your floor" << endl;
                                    return true;
                                }
                            }
                            
                            // move the player
                            movePlayerThroughPassage(current_passage);
                            cout << "you went " << current_direction->getName() << endl;
                            cout << "you are in " << player_location->getDescription() << endl;
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
            cout << "no valid command entered" << endl;
            return false;
        }
        
    }
    // --------------------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    // --------------------------------------------------------------------------------------------------
    // LOOK
    // --------------------------------------------------------------------------------------------------
    // if the player types "LOOK", output all visible exits and all objects in the room
    
    if(commands.at(0) == LOOK){
        
        
        // ---------------------------------------------------------
        // output exits : if the player is in an elevator
        // ---------------------------------------------------------
        if( isType<Elevator>(player_location) ){
            
            // set the current elevator to the player location
            Elevator* current_elevator = static_cast<Elevator*>(player_location);
            
            cout << "you are in " << current_elevator->getName() << endl;
            cout << "you are on floor: " << current_elevator->getCurrentFloorNumber() << endl;
            cout << "the elevator doors open to the " << directions[current_elevator->getExit_direction()]->getName() << endl;
            
            
            for(int i=FLOORS_min; i<FLOORS_max; i++){
                if(current_elevator->buttonIsVisibile(i)){
                    cout << "there is an elevator button with a " << current_elevator->getCurrentFloorNumber()+i-100 << " on it" << endl;
                }
            }
            
            
        }
        
        
        // ---------------------------------------------------------
        // output exits : if the player is in a room
        // ---------------------------------------------------------
        else if(isType<Room>(player_location)){
            
            Room* current_room = static_cast<Room*>(player_location);   // point current_room to the player location
        
            // output the description of the location
            cout << "you are in " << player_location->getDescription() << endl;
            
            
            // loop once for each direction
            for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
                
                
                Passage* current_passage = current_room->exitTo(i);         // set the current passage equal to the exit of the player location at i
                string lock;
            
                
                // ---------------------------------------------
                if(current_passage != 0){                   // check to see if the current passage exists
                    if(current_passage->isVisible() ){      // check to see if the current passage is visible
                        
                        Location* target_location = getTargetLocation(current_passage, player_location);
                        if(isType<Elevator>(target_location)){
                            
                            // if the passage is unlocked
                            if(current_passage->isUnlocked() ){
                                lock = " ";
                            }
                            
                            // if the passage is locked
                            else {
                                lock = " locked ";
                            }
                            
                            // output the exit state
                            cout << "there are" << lock << "elevator doors to the " << directions[i]->getName() << endl;
                        }
                        
                        else {
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
                        }
                        
                        
                    }
                }
                // --------------------------------------------
            }
            
            for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
                Direction* current_direction = directions[i];
                if(current_room->hasCallButton(i)){
                    cout << "there is an elevator call button on the " << current_direction->getName() << " wall" << endl;
                }
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
        for(int i=PHYSICAL_OBJECTS_min; i<PHYSICAL_OBJECTS_max; i++){
            if(physical_objects[i]->getLocation() == player_location){
                cout << "there is " << physical_objects[i]->getDescription() << endl;
            }
        }
        
        
        return true;
    }
    // --------------------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    // --------------------------------------------------------------------------------------------------
    // PRESS
    // --------------------------------------------------------------------------------------------------
    if(commands.at(0) == PRESS){
        
        
        // if the command is only one word long, no valid command entered
        if(commands.size() == 1){
            cout << "no valid command entered" << endl;
            return false;
        }
        
        if(isType<Elevator>(player_location)){
            Elevator* current_elevator = static_cast<Elevator*>(player_location);
            
            if(isNumber(commands.at(1)) ){
                
                int target_floor = commands.at(1) - 100;
                
                if(current_elevator->getCurrent_floor() != target_floor){
                    current_elevator->setCurrent_floor(target_floor);
                    cout << "you are now on floor: " << current_elevator->getCurrentFloorNumber() << endl;
                } else {
                    cout << "you are already on that floor" << endl;
                }
                
                return true;
            }
            else {
                cout << "no valid command entered" << endl;
                return false;
            }
        }
        
        
        if(isType<Room>(player_location)){
            Room* current_room = static_cast<Room*>(player_location);
            
            if(isDirection(commands.at(1)) ){
                Passage* current_passage = current_room->exitTo(commands.at(1));
                Location* target_location = getTargetLocation(current_passage, current_room);
                
                if(current_room->hasCallButton(commands.at(1)) ){
                    Elevator* target_elevator = static_cast<Elevator*>(target_location);
                    
                    if(target_elevator->getCurrent_floor() == current_room->getFloor()){
                        cout << "the elevator is already on your floor" << endl;
                        return true;
                    }
                    else{
                        target_elevator->setCurrent_floor(current_room->getFloor());
                        cout << "the elevator is now your floor " << endl;
                        return true;
                    }
                }
                else {
                    cout << "there is no elevator call button in that direction" << endl;
                    return true;
                }
            }
            else{
                cout << "no valid command entered" << endl;
                return false;
            }
        }
    
    }
    // --------------------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    
    // --------------------------------------------------------------------------------------------------
    // GET
    // --------------------------------------------------------------------------------------------------
    if(commands.at(0) == GET){
        
        // if the command is only one word long, no valid command entered
        if(commands.size() == 1){
            cout << "no valid command entered" << endl;
            return false;
        }
        
        if(isPhysical_object(commands.at(1)) ){
            PhysicalObject* current_object = physical_objects[commands.at(1)];
            
            if(current_object->getLocation() == player_location){
                if(isType<Item>(current_object)){
                    Item* current_item = static_cast<Item*>(current_object);
                    current_item->moveTo(locations[INVENTORY]);
                    cout << current_item->getDescription() << " is now in your inventory" << endl;
                    return true;
                }
                else {
                    cout << "you cannot pick that up" << endl;
                }
            }
        }
    }
    // --------------------------------------------------------------------------------------------------

    
    
    
    
    
    
    // --------------------------------------------------------------------------------------------------
    // DROP
    // --------------------------------------------------------------------------------------------------
    if(commands.at(0) == DROP){
        
        // if the command is only one word long, no valid command entered
        if(commands.size() == 1){
            cout << "no valid command entered" << endl;
            return false;
        }
        
        if(isPhysical_object(commands.at(1)) ){
            PhysicalObject* current_object = physical_objects[commands.at(1)];
            
            if(current_object->getLocation() == locations[INVENTORY] ){
                if(isType<Item>(current_object)){
                    Item* current_item = static_cast<Item*>(current_object);
                    current_item->moveTo(player_location);
                    cout << "you dropped " << current_item->getDescription() << endl;
                    return true;
                }
                else{
                    cout << "ERROR: non item in inventory " << endl;
                    return false;
                }
            }
        }
    }
    // --------------------------------------------------------------------------------------------------
 
    
    
    
    
    
    // --------------------------------------------------------------------------------------------------
    // no valid command entered
    // --------------------------------------------------------------------------------------------------
    cout << "no valid command entered" << endl;
    return false;
}
