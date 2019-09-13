//
//  createRoom.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 9/12/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "Location.hpp"

Room* Game::createRoom(int code, string name, string description, int floor, int exit_north, int exit_south, int exit_east, int exit_west){
    
    // create object
    static Room room;
    locations[code] = &room;
    
    // assign attributes
    room.setCode(code);
    room.setName(name);
    room.setDescription(description);
    room.setFloor(floor);
    
    int exits[DIRECTIONS] = {exit_north, exit_south, exit_east, exit_west};
    
    for(int i=0; i<DIRECTIONS; i++){
        if(exits[i] == 0){
            room.setExit(i+DIRECTIONS_min, 0);
        }
        else{
            room.setExit(i+DIRECTIONS_min, passages[exits[i]]);
        }
    }
    
    return &room;
}
