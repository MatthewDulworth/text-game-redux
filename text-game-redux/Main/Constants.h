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
// boolean constants
// -------------------------------------------
const bool UNLOCKED = true;
const bool LOCKED = false;
const bool VISIBLE = true;
const bool HIDDEN = false;


// -------------------------------------------
// FLOORS
// -------------------------------------------
const int FLOORS = 2;
enum enum_FLOORS {
    FIRST_FLOOR,
    SECOND_FLOOR
};

// -------------------------------------------
// NUMBERS
// -------------------------------------------
const int NUMBERS = 2;
enum enum_NUMBERS {
    ONE,
    TWO
};

// -------------------------------------------
// DIRECTIONS
// -------------------------------------------
const int DIRECTIONS = 4;
enum enum_DIRECTIONS {
    NORTH,
    SOUTH,
    EAST,
    WEST,
};

// -------------------------------------------
// LOCATIONS
// -------------------------------------------
const int LOCATIONS = 10;
enum enum_LOCATIONS {
    LOBBY,
    STREET,
    ELEVATOR_ONE,
    CUBICLE_ROOM,
    SUPPLY_CLOSET,
    MANAGERS_OFFICE,
    LLAMA_SHRINE,
    BREAK_ROOM,
    INVENTORY,
    TRASH
    
};

// -------------------------------------------
// PASSAGES
// -------------------------------------------
const int PASSAGES = 8;
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
// DOOR TYPES
// -------------------------------------------
const int DOOR_TYPES = 1;
enum enum_DOOR_TYPES{
    SIMPLE
};
// -------------------------------------------
// PHYSICAL OBJECTS
// -------------------------------------------
const int PHYSICALOBJECTS = 1;
enum enum_OBJECTS {
    SIMPLE_KEY_1
};

// -------------------------------------------
// ACTIONS
// -------------------------------------------
const int ACTIONS = 2;
enum enum_ACTIONS {
    GO,
    LOOK,
    PRESS
};

#endif /* Constants_h */
