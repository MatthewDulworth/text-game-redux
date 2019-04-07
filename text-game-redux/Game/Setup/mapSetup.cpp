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
    static Room lobby, street;                                                              // first floor
    static Room cubicle_room, supply_closet, managers_office, llama_shrine, break_room;     // second floor
    static Elevator elevator_1;                                                             // elevators
    static AdminLocation inventory, trash;                                                  // admin locations
    
    // ----- passage declarations ----- //
    static Passage lobby_to_street, lobby_to_elevator1;                                                 // 1st floor
    static Passage cubicleRoom_to_elevator1, cubicleRoom_to_supplyCloset, cubicleRoom_to_breakRoom;     // 2nd floor
    static Passage breakRoom_to_llamaShrine, managersOffice_to_llamaShrine, cubicleRoom_to_managersOffice; // 2nd floor
    
    // ----- set player starting location ----- //
    setPlayer_location(&lobby);
    
    // ----- set first floor rooms ----- //
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
    
    // ----- set second floor rooms ----- //
    // LARGE_EMPTY_ROOM
    cubicle_room.setCode(CUBICLE_ROOM);
    cubicle_room.setName("large empty room");
    cubicle_room.setDescription("a large empty room");
    cubicle_room.setExit(NORTH, &cubicleRoom_to_elevator1);
    cubicle_room.setExit(SOUTH, &cubicleRoom_to_managersOffice);
    cubicle_room.setExit(EAST, &cubicleRoom_to_supplyCloset);
    cubicle_room.setExit(WEST, &cubicleRoom_to_breakRoom);
    // SUPPLY CLOSET
    supply_closet.setCode(SUPPLY_CLOSET);
    supply_closet.setName("SUPPLY CLOSET");
    supply_closet.setDescription("a supply closet");
    supply_closet.setExit(WEST, &cubicleRoom_to_supplyCloset);
    // MANAGERS_OFFICE
    managers_office.setCode(MANAGERS_OFFICE);
    managers_office.setName("MANAGERS OFFICE");
    managers_office.setDescription("a managers office");
    managers_office.setExit(NORTH, &cubicleRoom_to_managersOffice);
    // LLAMA_SHRINE
    llama_shrine.setCode(LLAMA_SHRINE);
    llama_shrine.setName("LLAMA SHRINE");
    llama_shrine.setDescription("a shrine for the llama god");
    llama_shrine.setExit(NORTH, &breakRoom_to_llamaShrine);
    llama_shrine.setExit(EAST, &managersOffice_to_llamaShrine);
    // BREAK_ROOM
    break_room.setCode(BREAK_ROOM);
    break_room.setName("BREAK ROOM");
    break_room.setDescription("an office break room");
    break_room.setExit(EAST, &cubicleRoom_to_breakRoom);
    break_room.setExit(SOUTH, &breakRoom_to_llamaShrine);
    
    // ----- set elevators ----- //
    // ELEVATOR 1
    elevator_1.setCode(ELEVATOR_1);
    elevator_1.setName("ELEVATOR ONE");
    elevator_1.setDescription("an elevator");
    elevator_1.setExit(FIRST_FLOOR, &lobby_to_elevator1);
    elevator_1.setExit(SECOND_FLOOR, &cubicleRoom_to_elevator1);
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
