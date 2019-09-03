//
//  MapSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"
#include "Location.hpp"
#include "Passage.hpp"
#include "Player.hpp"

// ------------------------------------------------------------------------------------------------------
// mapSetup
// ------------------------------------------------------------------------------------------------------
// popluates the loctions and passages arrays
void Game::mapSetup(){
    
    // --------------------------------------------------------------------------------------
    // create new objects
    // --------------------------------------------------------------------------------------
    
    // ------------------------------------------------
    // locations
    // ------------------------------------------------
    // admin locations
    static AdminLocation inventory, trash;
    locations[INVENTORY] = &inventory;
    locations[TRASH] = &trash;
    
    // rooms
    static Room lobby, subway_station;
    static Elevator elevator_one;
    
    // fill array;
    locations[LOBBY] = &lobby;
    locations[SUBWAY_STATION] = &subway_station;
    locations[ELEVATOR_ONE] = &elevator_one;
    
    
    // ------------------------------------------------
    // passages
    // ------------------------------------------------
    for(int i = PASSAGES_min; i<PASSAGES_max; i++){
        passages[i] = new Passage();
    }
    
    
    // ------------------------------------------------
    // player
    // ------------------------------------------------
    player = new Player(&lobby);
    
    
    // --------------------------------------------------------------------------------------
    // rooms
    // --------------------------------------------------------------------------------------
    // SUBWAY_STATION
    subway_station.setCode(SUBWAY_STATION);
    subway_station.setName("SUBWAY_STATION");
    subway_station.setDescription("subway station");
    subway_station.setFloor(FIRST_FLOOR);
    subway_station.setExit(SOUTH, passages[SUBWAY_STATION_to_LOBBY]);
    
    // LOBBY
    lobby.setCode(LOBBY);
    lobby.setName("LOBBY");
    lobby.setDescription("the lobby of an office building");
    lobby.setFloor(FIRST_FLOOR);
    lobby.setExit(SOUTH, passages[LOBBY_to_ELEVATOR_ONE]);
    

    // --------------------- -----------------------------------------------------------------
    // passages
    // --------------------------------------------------------------------------------------
    // SUBWAY_STATION_to_LOBBY
    
    passages[SUBWAY_STATION_to_LOBBY]->setCode(SUBWAY_STATION_to_LOBBY);
    passages[SUBWAY_STATION_to_LOBBY]->setLockState(UNLOCKED);
    passages[SUBWAY_STATION_to_LOBBY]->setVisibility(VISIBLE);
    passages[SUBWAY_STATION_to_LOBBY]->setLocation_1(&lobby);
    passages[SUBWAY_STATION_to_LOBBY]->setLocation_2(&subway_station);
    passages[SUBWAY_STATION_to_LOBBY]->setKey_type(ACCESS_LVL_1);
    
    // ATRIUM_HALLWAY_to_CONNECTING_ROOM
    passages[LOBBY_to_ELEVATOR_ONE]->setCode(LOBBY_to_ELEVATOR_ONE);
    passages[LOBBY_to_ELEVATOR_ONE]->setLockState(UNLOCKED);
    passages[LOBBY_to_ELEVATOR_ONE]->setVisibility(VISIBLE);
    passages[LOBBY_to_ELEVATOR_ONE]->setLocation_1(&lobby);
    passages[LOBBY_to_ELEVATOR_ONE]->setLocation_2(&elevator_one);
    passages[LOBBY_to_ELEVATOR_ONE]->setKey_type(ACCESS_LVL_1);

    
    // --------------------------------------------------------------------------------------
    // elevators
    // --------------------------------------------------------------------------------------
    // ELEVATOR_ONE
    elevator_one.setCode(ELEVATOR_ONE);
    elevator_one.setName("ELEVATOR ONE");
    elevator_one.setExit_direction(WEST);
    elevator_one.setExit(FIRST_FLOOR, passages[LOBBY_to_ELEVATOR_ONE]);
    elevator_one.setCurrent_floor(FIRST_FLOOR);
    elevator_one.initButtons();
    
    // init buttons
    lobby.initCallButtons();
    subway_station.initCallButtons();

    
    // --------------------------------------------------------------------------------------
    // admin locations
    // --------------------------------------------------------------------------------------
    // ----- set adminlocations ----- //
    // INVENTORY
    locations[INVENTORY]->setCode(INVENTORY);
    locations[INVENTORY]->setName("INVENTORY");
    locations[INVENTORY]->setDescription("the players inventory");
    // TRASH
    locations[TRASH]->setCode(TRASH);
    locations[TRASH]->setName("TRASH");
    locations[TRASH]->setDescription( "trash for unneeded physical objects");
}
