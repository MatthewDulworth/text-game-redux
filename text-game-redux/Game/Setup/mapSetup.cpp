//
//  MapSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// --------------------------------------------------------------------------------------
// mapSetup
// --------------------------------------------------------------------------------------
// popluates the loctions and passages arrays
void Game::mapSetup(){
    
    // ------------------------------------------------
    // delarations
    // ------------------------------------------------
    // ----- location declarations ----- //
    static Room lobby, street;                                                              // first floor
    static Room cubicle_room, supply_closet, managers_office, llama_shrine, break_room;     // second floor
    static Elevator elevator_1;                                                             // elevators
    static AdminLocation inventory, trash;                                                  // admin locations
    
    // ----- passage declarations ----- //
    static Passage lobby_to_street, lobby_to_elevator1;                                                     // 1st floor
    static Passage cubicleRoom_to_elevator1, cubicleRoom_to_supplyCloset, cubicleRoom_to_breakRoom;         // 2nd floor
    static Passage breakRoom_to_llamaShrine, managersOffice_to_llamaShrine, cubicleRoom_to_managersOffice;  // 2nd floor
    
    
    
    // ------------------------------------------------
    // rooms
    // ------------------------------------------------
    // ----- set first floor rooms ----- //
    // LOBBY
    lobby.setCode(LOBBY);                                           // index in the locations array
    lobby.setName("LOBBY");                                         // in-game name
    lobby.setDescription("an empty lobby of an office building");   // in-game description
    lobby.setFloor(FIRST_FLOOR);                                    // floor that the room is on
    lobby.setExit(NORTH, &lobby_to_elevator1);                      // passage to the north
    lobby.setExit(SOUTH, &lobby_to_street);                         // passage to the south
    // STREET
    street.setCode(STREET);
    street.setName("STREET");
    street.setFloor(FIRST_FLOOR);
    street.setDescription("a busy street");
    street.setExit(NORTH, &lobby_to_street);
    
    // ----- set second floor rooms ----- //
    // LARGE_EMPTY_ROOM
    cubicle_room.setCode(CUBICLE_ROOM);
    cubicle_room.setName("large empty room");
    cubicle_room.setDescription("a large empty room");
    cubicle_room.setFloor(SECOND_FLOOR);
    cubicle_room.setExit(NORTH, &cubicleRoom_to_elevator1);
    cubicle_room.setExit(SOUTH, &cubicleRoom_to_managersOffice);
    cubicle_room.setExit(EAST, &cubicleRoom_to_supplyCloset);
    cubicle_room.setExit(WEST, &cubicleRoom_to_breakRoom);
    // SUPPLY CLOSET
    supply_closet.setCode(SUPPLY_CLOSET);
    supply_closet.setName("SUPPLY CLOSET");
    supply_closet.setFloor(SECOND_FLOOR);
    supply_closet.setDescription("a supply closet");
    supply_closet.setExit(WEST, &cubicleRoom_to_supplyCloset);
    // MANAGERS_OFFICE
    managers_office.setCode(MANAGERS_OFFICE);
    managers_office.setName("MANAGERS OFFICE");
    managers_office.setDescription("a managers office");
    managers_office.setFloor(SECOND_FLOOR);
    managers_office.setExit(NORTH, &cubicleRoom_to_managersOffice);
    // LLAMA_SHRINE
    llama_shrine.setCode(LLAMA_SHRINE);
    llama_shrine.setName("LLAMA SHRINE");
    llama_shrine.setDescription("a shrine for the llama god");
    llama_shrine.setFloor(SECOND_FLOOR);
    llama_shrine.setExit(NORTH, &breakRoom_to_llamaShrine);
    llama_shrine.setExit(EAST, &managersOffice_to_llamaShrine);
    // BREAK_ROOM
    break_room.setCode(BREAK_ROOM);
    break_room.setName("BREAK ROOM");
    break_room.setDescription("an office break room");
    break_room.setFloor(SECOND_FLOOR);
    break_room.setExit(EAST, &cubicleRoom_to_breakRoom);
    break_room.setExit(SOUTH, &breakRoom_to_llamaShrine);
    
    
    // ------------------------------------------------
    // passages
    // ------------------------------------------------
    // ----- set first floor passages ----- //
    // LOBBY to ELEVATOR_ONE
    lobby_to_elevator1.setCode(LOBBY_TO_ELEVATOR_1);    // index in the passages array
    lobby_to_elevator1.setLockState(UNLOCKED);          // if the door is locked or unlocked
    lobby_to_elevator1.setHiddenState(VISIBLE);         // if the passage is hidden or visible
    lobby_to_elevator1.setRoom_1(&lobby);               // the room on one side of the passage
    lobby_to_elevator1.setRoom_2(&elevator_1);          // the room on the other side the passage
    // LOBBY to STREET
    lobby_to_street.setCode(LOBBY_TO_STREET);
    lobby_to_street.setLockState(UNLOCKED);
    lobby_to_street.setHiddenState(VISIBLE);
    lobby_to_street.setRoom_1(&lobby);
    lobby_to_street.setRoom_2(&street);
    
    // ----- set second floor passages ----- //
    // CUBICLE_ROOM to ELEVATOR_ONE
    cubicleRoom_to_elevator1.setCode(CUBICLE_ROOM_TO_ELEVATOR_1);
    cubicleRoom_to_elevator1.setLockState(UNLOCKED);
    cubicleRoom_to_elevator1.setHiddenState(VISIBLE);
    cubicleRoom_to_elevator1.setRoom_1(&cubicle_room);
    cubicleRoom_to_elevator1.setRoom_2(&elevator_1);
    // CUBICLE_ROOM to SUPPLY_CLOSET
    cubicleRoom_to_supplyCloset.setCode(CUBICLE_ROOM_TO_SUPPLY_CLOSET);
    cubicleRoom_to_supplyCloset.setLockState(UNLOCKED);
    cubicleRoom_to_supplyCloset.setHiddenState(VISIBLE);
    cubicleRoom_to_supplyCloset.setRoom_1(&cubicle_room);
    cubicleRoom_to_supplyCloset.setRoom_2(&supply_closet);
    // CUBICLE_ROOM to BREAK_ROOM
    cubicleRoom_to_breakRoom.setCode(CUBICLE_ROOM_TO_BREAK_ROOM);
    cubicleRoom_to_breakRoom.setLockState(UNLOCKED);
    cubicleRoom_to_breakRoom.setHiddenState(VISIBLE);
    cubicleRoom_to_breakRoom.setRoom_1(&cubicle_room);
    cubicleRoom_to_breakRoom.setRoom_2(&break_room  );
    // CUBICLE_ROOM to MANAGERS_OFFICE
    cubicleRoom_to_managersOffice.setCode(CUBICLE_ROOM_TO_MANAGERS_OFFICE);
    cubicleRoom_to_managersOffice.setLockState(UNLOCKED);
    cubicleRoom_to_managersOffice.setHiddenState(VISIBLE);
    cubicleRoom_to_managersOffice.setRoom_1(&cubicle_room);
    cubicleRoom_to_managersOffice.setRoom_2(&managers_office);
    // MANAGERS_OFFICE to LLAMA SHRINE
    managersOffice_to_llamaShrine.setCode(MANAGERS_OFFICE_TO_LLAMA_SHRINE);
    managersOffice_to_llamaShrine.setLockState(UNLOCKED);
    managersOffice_to_llamaShrine.setHiddenState(VISIBLE);
    managersOffice_to_llamaShrine.setRoom_1(&managers_office);
    managersOffice_to_llamaShrine.setRoom_2(&llama_shrine);
    // BREAK_ROOM to LLAMA SHRINE
    breakRoom_to_llamaShrine.setCode(BREAK_ROOM_TO_LLAMA_SHRINE);
    breakRoom_to_llamaShrine.setLockState(UNLOCKED);
    breakRoom_to_llamaShrine.setHiddenState(VISIBLE);
    breakRoom_to_llamaShrine.setRoom_1(&break_room);
    breakRoom_to_llamaShrine.setRoom_2(&llama_shrine);
    
    
    // ------------------------------------------------
    // elevators
    // ------------------------------------------------
    // ELEVATOR ONE
    elevator_1.setCode(ELEVATOR_ONE);                               // index of the elevator in the locations array
    elevator_1.setName("ELEVATOR ONE");                             // in-game name
    elevator_1.setDescription("an elevator");                       // in-game description
    elevator_1.setExit(FIRST_FLOOR, &lobby_to_elevator1);           // first floor passage
    elevator_1.setExit(SECOND_FLOOR, &cubicleRoom_to_elevator1);    // second floor passage
    elevator_1.setCurrent_floor(FIRST_FLOOR);                               // starting floor
   
    
    
    // ------------------------------------------------
    // admin locations
    // ------------------------------------------------
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
    locations[LOBBY] = &lobby;
    locations[STREET] = &lobby;
    locations[ELEVATOR_ONE] = &elevator_1;
    locations[CUBICLE_ROOM] = &cubicle_room;
    locations[SUPPLY_CLOSET] = &supply_closet;
    locations[BREAK_ROOM] = &break_room;
    locations[MANAGERS_OFFICE] = &managers_office;
    locations[LLAMA_SHRINE] = &llama_shrine;
    locations[INVENTORY] = &inventory;
    locations[TRASH] = &trash;
    
    // ----- set passages array ----- //
    passages[LOBBY_TO_STREET] = &lobby_to_street;
    passages[LOBBY_TO_ELEVATOR_1] = &lobby_to_elevator1;
    passages[CUBICLE_ROOM_TO_ELEVATOR_1] = &cubicleRoom_to_elevator1;
    passages[CUBICLE_ROOM_TO_SUPPLY_CLOSET] = &cubicleRoom_to_supplyCloset;
    passages[CUBICLE_ROOM_TO_BREAK_ROOM] = &cubicleRoom_to_managersOffice;
    passages[CUBICLE_ROOM_TO_BREAK_ROOM] = &cubicleRoom_to_breakRoom;
    passages[MANAGERS_OFFICE_TO_LLAMA_SHRINE] = &managersOffice_to_llamaShrine;
    passages[BREAK_ROOM_TO_LLAMA_SHRINE] = &breakRoom_to_llamaShrine;
    
    // ----- set player starting location ----- //
    setPlayer_location(&lobby);
}
