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
    locations[INV] = &inventory;
    locations[TRASH] = &trash;
    
    // rooms
    static Room lobby, subway_station;
    static Elevator elevator_one;
    
    // fill array;
    locations[LOBBY] = &lobby;
    locations[SUBWAY_STATION] = &subway_station;
    locations[ELEVATOR_ONE] = &elevator_one;
    
    createRoom(
        /*CODE*/ X,
        /*NAME*/ "X",
        /*DESCRIPTION*/ "x",
        /*FLOOR*/ FIRST_FLOOR,
        /*NORTH EXIT*/ 0,
        /*SOUTH EXIT*/ 0,
        /*EAST EXIT*/ 0,
        /*WEST EXIT*/ 0
   );
    
    
    // ------------------------------------------------
    // passages
    // ------------------------------------------------
    for(int i = PASSAGES_min; i<PASSAGES_max; i++){
        passages[i] = new Passage();
    }
    
    
    // ------------------------------------------------
    // player
    // ------------------------------------------------
    player = new Player(locations[X]);
    
    
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
    lobby.setExit(NORTH, passages[SUBWAY_STATION_to_LOBBY]);
    

    // --------------------- -----------------------------------------------------------------
    // passages
    // --------------------------------------------------------------------------------------
    // SUBWAY_STATION_to_LOBBY
    
    passages[SUBWAY_STATION_to_LOBBY]->setCode(SUBWAY_STATION_to_LOBBY);
    passages[SUBWAY_STATION_to_LOBBY]->setLockState(UNLOCKED);
    passages[SUBWAY_STATION_to_LOBBY]->setVisibility(VISIBLE);
    passages[SUBWAY_STATION_to_LOBBY]->setLocation_1(&lobby);
    passages[SUBWAY_STATION_to_LOBBY]->setLocation_2(&subway_station);
    
    // LOBBY_to_ELEVATOR_ONE
    passages[LOBBY_to_ELEVATOR_ONE]->setCode(LOBBY_to_ELEVATOR_ONE);
    passages[LOBBY_to_ELEVATOR_ONE]->setLockState(UNLOCKED);
    passages[LOBBY_to_ELEVATOR_ONE]->setVisibility(VISIBLE);
    passages[LOBBY_to_ELEVATOR_ONE]->setLocation_1(&lobby);
    passages[LOBBY_to_ELEVATOR_ONE]->setLocation_2(&elevator_one);

    
    // --------------------------------------------------------------------------------------
    // elevators
    // --------------------------------------------------------------------------------------
    // ELEVATOR_ONE
    elevator_one.setCode(ELEVATOR_ONE);
    elevator_one.setName("ELEVATOR ONE");
    elevator_one.setDescription("an elevator");
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
    // INV
    locations[INV]->setCode(INV);
    locations[INV]->setName("INV");
    locations[INV]->setDescription("the players inventory");
    // TRASH
    locations[TRASH]->setCode(TRASH);
    locations[TRASH]->setName("TRASH");
    locations[TRASH]->setDescription( "trash for unneeded physical objects");
}
