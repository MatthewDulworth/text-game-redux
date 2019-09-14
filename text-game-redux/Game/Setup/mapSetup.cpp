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
    // init
    // --------------------------------------------------------------------------------------
    createMapElements();
    player = new Player(locations[STATION]);
    
    // --------------------------------------------------------------------------------------
    // rooms
    // --------------------------------------------------------------------------------------
    setupRoom(LOBBY,"LOBBY", "a lobby of an office building", FIRST_FLOOR, STATION_to_LOBBY, 0, 0, 0);
    setupRoom(STATION, "STATION", "an empty subway station", FIRST_FLOOR, 0, STATION_to_LOBBY, 0, 0);
    
    
    // ---------------------------------------------------------------------------------------
    // passages
    // ---------------------------------------------------------------------------------------
    setupPassage(STATION_to_LOBBY, UNLOCKED, VISIBLE, locations[LOBBY], locations[STATION]);
    setupPassage(LOBBY_to_ELEVATOR_ONE, UNLOCKED, VISIBLE, locations[LOBBY], locations[ELEVATOR_ONE]);

    
    // --------------------------------------------------------------------------------------
    // elevator
    // --------------------------------------------------------------------------------------
    setupElevator( ELEVATOR_ONE, "ELEVATOR ONE", "an elevator", SECOND_FLOOR, WEST, (Passage*[]){passages[LOBBY_to_ELEVATOR_ONE], 0});
    

    // --------------------------------------------------------------------------------------
    // admin locations
    // --------------------------------------------------------------------------------------
    setupAdminLocation(TRASH,"TRASH","trash");
    setupAdminLocation(INV, "INV", "the players inventory");
    
    // init buttons
    initCallButtons();
}
