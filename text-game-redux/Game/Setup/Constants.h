//
//  Constants.h
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#ifndef Constants_h
#define Constants_h

// -------------------------------------------
// array indexes
// -------------------------------------------
const int LOCATIONS = 10;
const int PASSAGES = 8;
const int DIRECTIONS = 6;
const int PHYSICALOBJECTS = 0;
const int ACTIONS = 2;
const int FLOORS = 2;


// -------------------------------------------
// boolean constants
// -------------------------------------------
const bool UNLOCKED = true;
const bool LOCKED = false;
const bool VISIBLE = true;
const bool HIDDEN = false;


// -------------------------------------------
// FLOORS
// -------------------------------------------
enum enum_FLOORS {
    FIRST_FLOOR,
    SECOND_FLOOR
    
};

// -------------------------------------------
// DIRECTIONS
// -------------------------------------------
enum enum_DIRECTIONS {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    UP,
    DOWN
};

// -------------------------------------------
// LOCATIONS
// -------------------------------------------
enum enum_LOCATIONS {
    LOBBY,
    STREET,
    ELEVATOR_1,
    CUBICLE_ROOM,
    SUPPLY_CLOSET,
    MANAGERS_OFFICE,
    LLAMA_SHRINE,
    BREAK_ROOM,
    INVENTORY,
    TRASH}
;

// -------------------------------------------
// PASSAGES
// -------------------------------------------
enum enum_PASSAGES {
    LOBBY_TO_ELEVATOR_1,
    LOBBY_TO_STREET,
    CUBICLE_ROOM_TO_ELEVATOR_1,
    CUBICLE_ROOM_TO_SUPPLY_CLOSET,
    CUBICLE_ROOM_TO_BREAK_ROOM,
    CUBICLE_ROOM_TO_MANAGERS_OFFICE,
    BREAK_ROOM_TO_LLAMA_SHRINE,
    MANAGERS_OFFICE_TO_LLAMA_SHRINE
};

// -------------------------------------------
// OBJECTS
// -------------------------------------------
enum enum_OBJECTS {
    DESK,
    KEY,
    WAFFLE_BAT,
    COINS
    
};

// -------------------------------------------
// ACTIONS
// -------------------------------------------
enum enum_ACTIONS {
    GO,
    LOOK
};

#endif /* Constants_h */
