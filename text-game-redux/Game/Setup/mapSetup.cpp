//
//  MapSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// ------------------------------------------------
// mapSetup
// ------------------------------------------------
// popluates the loctions and passages arrays
void Game::mapSetup(){
    
    // ----- location declarations ----- //
    static Room lobby, street;                                  // first floor
    static Room large_empty_room, supply_closet, r1, r2, r3;    // second floor
    static Elevator elevator_1;                                 // elevators
    static AdminLocation inventory, trash;                      // admin locations
    
    // ----- passage declarations ----- //
    static Passage lobby_to_street, lobby_to_elevator1;                                                            // 1st floor
    static Passage elevator1_to_LEroom, LEroom_to_supplyCloset, LEroom_to_r1, r1_to_r2, r2_to_r3, LEroom_to_r3;    // 2nd floor
    
    // ----- set player starting location ----- //
    setPlayer_location(&lobby);
    
    // ----- set rooms ----- //
    // LOBBY
    lobby.setCode(LOBBY);
    lobby.setName("LOBBY");
    lobby.setDescription("an empty lobby of an office building");
    lobby.setExit(NORTH, &lobby_to_elevator1);
    lobby.setExit(SOUTH, &lobby_to_street);
    // STREET
    street.setCode(STREET);
    street.setName("STREET");
    street.setDescription("a busy street");
    street.setExit(NORTH, &lobby_to_street);
    // LARGE_EMPTY_ROOM
    large_empty_room.setCode(LARGE_EMPTY_ROOM);
    large_empty_room.setName("large empty room");
    large_empty_room.setDescription("a large empty room");
    large_empty_room.setExit(NORTH, &elevator1_to_LEroom);
    large_empty_room.setExit(SOUTH, &LEroom_to_r3);
    large_empty_room.setExit(EAST, &LEroom_to_supplyCloset);
    large_empty_room.setExit(WEST, &LEroom_to_r1);
    // SUPPLY CLOSET
    supply_closet.setCode(SUPPLY_CLOSET);
    supply_closet.setName("");
    supply_closet.setDescription("a large empty room");
    supply_closet.setExit(NORTH, &elevator1_to_LEroom);
    supply_closet.setExit(SOUTH, &LEroom_to_r3);
    supply_closet.setExit(EAST, &LEroom_to_supplyCloset);
    supply_closet.setExit(WEST, &LEroom_to_r1);
    // ELEVATOR 1
    elevator_1.setCode(ELEVATOR_1);
    elevator_1.setName("ELEVATOR ONE");
    elevator_1.setDescription("an elevator");
    elevator_1.setExit(FIRST_FLOOR, &lobby_to_elevator1);
    elevator_1.setExit(SECOND_FLOOR, &elevator1_to_LEroom);
    elevator_1.setFloor(FIRST_FLOOR);
    
    // ----- set passages ----- //
    lobby_to_elevator1.setCode(LOBBY_TO_ELEVATOR_1);
    lobby_to_elevator1.setName("LOBBY TO ELEVATOR ONE");
    lobby_to_elevator1.setLockState(UNLOCKED);
    lobby_to_elevator1.setHiddenState(VISIBLE);
    lobby_to_elevator1.setRoom_1(&lobby);
    lobby_to_elevator1.setRoom_1(&elevator_1);
    
    

    // ----- set adminlocations ----- //
    // INVENTORY
    inventory.setCode(INVENTORY);
    inventory.setName("INVENTORY");
    inventory.setDescription("the player inventory");
    // TRASH
    trash.setCode(TRASH);
    trash.setName("TRASH");
    trash.setDescription("trash for unneeded physical objects");
    
    
    // ----- set locations array ----- //
   
    locations[INVENTORY] = &inventory;
    locations[TRASH] = &trash;
    
    // ----- set passages array ----- //
    
}
