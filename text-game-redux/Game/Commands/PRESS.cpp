//
//  PRESS.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "Location.hpp"

// --------------------------------------------------------------------------------------------------
// PRESS
// --------------------------------------------------------------------------------------------------
int Game::thePRESScommand(){
    if(commands.at(0) == PRESS){

        // if the command is only one word long, no valid command entered
        if(commands.size() < 2){
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
                    return true;
                }
                else {
                    cout << "you are already on that floor" << endl;
                    return false;
                }
            }
            else {
                return invalidCommand();
            }
        }

        // if the player is in a room
        else if(isType<Room>(player_location)){
            Room* current_room = static_cast<Room*>(player_location);
            
            // if the command is only one word long, no valid command entered
            if(commands.size() < 3){
                return invalidCommand();
            }
            
            if(commands.at(1) == ELEVATOR){
                if(isNumber(commands.at(2))){
                    string elevator_string = words[ELEVATOR]->getName();
                    string number_string = numbers[commands.at(2)]->getName();
                    
                    for(int i=DIRECTIONS_min; i<DIRECTIONS_max; i++){
                        if(current_room->hasVisibleButton(i)){
                            ElevatorCallButton* button = current_room->getButton(i);
                            Elevator* target_elevator = button->getElevator();
                            
                            if( (elevator_string + " " + number_string) == target_elevator->getName() ){
                                if(target_elevator->getCurrent_floor() != current_room->getFloor() ){
                                    target_elevator->setCurrent_floor(current_room->getFloor());
                                    cout << target_elevator->getName() << " is now on your floor" << endl;
                                    return true;
                                }
                                else{
                                    cout << target_elevator->getName() << " is already on your floor" << endl;
                                    return false;
                                }
                            }
                        }
                    }
                    return invalidCommand();
                }
                else {
                    return invalidCommand();
                }
            }
            else{
                return invalidCommand();
            }
        }

        // if the player is in neither a room or an elevator
        else {
            cout << "ERROR: player is not in a room or elevator" << endl;
            return false;
        }


    }

    // if the first command is not PRESS
    else {
        return WRONG_COMMAND;
    }
}
