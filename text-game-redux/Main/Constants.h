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
// integer constants
// -------------------------------------------
const int WRONG_COMMAND = -1;


// -------------------------------------------
// FLOORS
// -------------------------------------------
const int FLOORS = 2;
const int FLOORS_min = 100;
const int FLOORS_max = (FLOORS_min + FLOORS);

enum enum_FLOORS {
    FIRST_FLOOR = 100,
    SECOND_FLOOR
};


// -------------------------------------------
// NUMBERS
// -------------------------------------------
const int NUMBERS = 2;
const int NUMBERS_min = 200;
const int NUMBERS_max = (NUMBERS_min + NUMBERS);

enum enum_NUMBERS {
    ONE = 200,
    TWO
};


// -------------------------------------------
// DIRECTIONS
// -------------------------------------------
const int DIRECTIONS = 4;
const int DIRECTIONS_min = 300;
const int DIRECTIONS_max = (DIRECTIONS_min + DIRECTIONS);

enum enum_DIRECTIONS {
    NORTH = 300,
    SOUTH,
    EAST,
    WEST,
};


// -------------------------------------------
// LOCATIONS
// -------------------------------------------
const int LOCATIONS = 10;
const int LOCATIONS_min = 400;
const int LOCATIONS_max = (LOCATIONS_min + LOCATIONS);

enum enum_LOCATIONS {
    LOBBY = 400,
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
const int PASSAGES_min = 500;
const int PASSAGES_max = (PASSAGES_min + PASSAGES);

enum enum_PASSAGES {
    LOBBY_TO_ELEVATOR_1 = 500,
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
const int DOOR_TYPES_min = 600;
const int DOOR_TYPES_max = (DOOR_TYPES_min + DOOR_TYPES);

enum enum_DOOR_TYPES{
    NONE = 600,
    SILVER
};


// -------------------------------------------
// PHYSICAL OBJECTS
// -------------------------------------------
const int PHYSICAL_OBJECTS = 1;
const int PHYSICAL_OBJECTS_min = 700;
const int PHYSICAL_OBJECTS_max = (PHYSICAL_OBJECTS_min + PHYSICAL_OBJECTS);

enum enum_OBJECTS {
    SILVER_KEY = 700
};


// -------------------------------------------
// ACTIONS
// -------------------------------------------
const int ACTIONS = 6;
const int ACTIONS_min = 800;
const int ACTIONS_max = (ACTIONS_min + ACTIONS);

enum enum_ACTIONS {
    GO = 800,
    LOOK,
    PRESS,
    GET,
    DROP,
    USE
};


// -------------------------------------------
// WORDS
// -------------------------------------------
const int WORDS = 3;
const int WORDS_min = 900;
const int WORDS_max = (WORDS_min + WORDS);

enum enum_WORDS {
    EXIT = 900,
    ELEVATOR,
    BUTTON,
};


#endif /* Constants_h */
