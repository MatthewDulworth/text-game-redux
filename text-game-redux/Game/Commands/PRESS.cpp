//
//  PRESS.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

// --------------------------------------------------------------------------------------------------
// PRESS
// --------------------------------------------------------------------------------------------------
int Game::thePRESScommand(){
    if(commands.at(0) == PRESS){

        // if the command is only one word long, no valid command entered
        if(commands.size() == 1){
            return invalidCommand();
        }

        // if the player is in an elevator
        if(isType<Elevator>(player_location)){
            Elevator* current_elevator = static_cast<Elevator*>(player_location);

            if(isNumber(commands.at(1)) ){
                int target_floor = commands.at(1) - 100;

                if(current_elevator->getCurrent_floor() != target_floor){
                    current_elevator->setCurrent_floor(target_floor);
                    cout << "you are now on floor: " << current_elevator->getCurrentFloorNumber() << endl;
                    return True;
                }
                else {
                    cout << "you are already on that floor" << endl;
                    return True;
                }
            }
            else {
                return invalidCommand();
            }
        }

        // if the player is in a room
        else if(isType<Room>(player_location)){
            Room* current_room = static_cast<Room*>(player_location);
            
            // if the second command is a direction
            if(isDirection(commands.at(1)) ){
                Passage* current_passage = current_room->exitTo(commands.at(1));
                Location* target_location = getTargetLocation(current_passage, current_room);
                
                if(current_room->hasCallButton(commands.at(1)) ){
                    Elevator* target_elevator = static_cast<Elevator*>(target_location);
                    
                    if(target_elevator->getCurrent_floor() == current_room->getFloor()){
                        cout << "the elevator is already on your floor" << endl;
                        return True;
                    }
                    else{
                        target_elevator->setCurrent_floor(current_room->getFloor());
                        cout << "the elevator is now your floor " << endl;
                        return True;
                    }
                    
                }
                else {
                    return invalidCommand();
                }
            }
            
            // if the second command is not a direction
            else{
                return invalidCommand();
            }

        }

        // if the player is in neither a room or an elevator
        else {
            cout << "ERROR: player is not in a room or elevator" << endl;
            return False;
        }


    }

    // if the first command is not PRESS
    else {
        return WRONG_COMMAND;
    }
}
