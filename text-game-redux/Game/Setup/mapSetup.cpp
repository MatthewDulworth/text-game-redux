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
    
    createMapElements();
    player = new Player(locations[STATION]);
    
    static AdminLocation inventory, trash;
    locations[INV] = &inventory;
    locations[TRASH] = &trash;
    static Elevator elevator_one;
    
    
    // --------------------------------------------------------------------------------------
    // rooms
    // --------------------------------------------------------------------------------------
    
    // LOBBY
    setupRoom(
       /*CODE*/        LOBBY,
       /*NAME*/        "LOBBY",
       /*DESCRIPTION*/ "lobby",
       /*FLOOR*/       FIRST_FLOOR,
       /*NORTH EXIT*/  STATION_to_LOBBY,
       /*SOUTH EXIT*/  0,
       /*EAST EXIT*/   0,
       /*WEST EXIT*/   0
    );
    
    // STATION
    setupRoom(
       /*CODE*/        STATION,
       /*NAME*/        "STATION",
       /*DESCRIPTION*/ "station",
       /*FLOOR*/       FIRST_FLOOR,
       /*NORTH EXIT*/  0,
       /*SOUTH EXIT*/  STATION_to_LOBBY,
       /*EAST EXIT*/   0,
       /*WEST EXIT*/   0
    );
    
    
    
    // --------------------- -----------------------------------------------------------------
    // passages
    // --------------------------------------------------------------------------------------
    // SUBWAY_STATION_to_LOBBY
    
    passages[STATION_to_LOBBY]->setCode(STATION_to_LOBBY);
    passages[STATION_to_LOBBY]->setLockState(UNLOCKED);
    passages[STATION_to_LOBBY]->setVisibility(VISIBLE);
    passages[STATION_to_LOBBY]->setLocation_1(locations[LOBBY]);
    passages[STATION_to_LOBBY]->setLocation_2(locations[STATION]);
    
    // LOBBY_to_ELEVATOR_ONE
    passages[LOBBY_to_ELEVATOR_ONE]->setCode(LOBBY_to_ELEVATOR_ONE);
    passages[LOBBY_to_ELEVATOR_ONE]->setLockState(UNLOCKED);
    passages[LOBBY_to_ELEVATOR_ONE]->setVisibility(VISIBLE);
    passages[LOBBY_to_ELEVATOR_ONE]->setLocation_1(locations[LOBBY]);
    passages[LOBBY_to_ELEVATOR_ONE]->setLocation_2(locations[ELEVATOR_ONE]);

    
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
    initCallButtons();
    
    
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
    locations[TRASH]->setDescription("trash for unneeded physical objects");
}
