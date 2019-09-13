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
const int NONE = -100;


// -------------------------------------------
// FLOORS
// -------------------------------------------
const int FLOORS = 2;
const int FLOORS_min = 100;
const int FLOORS_max = (FLOORS_min + FLOORS);

enum enum_FLOORS {
    FIRST_FLOOR = FLOORS_min,
    SECOND_FLOOR,
};


// -------------------------------------------
// NUMBERS
// -------------------------------------------
const int NUMBERS = 7;
const int NUMBERS_min = 200;
const int NUMBERS_max = (NUMBERS_min + NUMBERS);

enum enum_NUMBERS {
    ONE = NUMBERS_min,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
};


// -------------------------------------------
// DIRECTIONS
// -------------------------------------------
const int DIRECTIONS = 4;
const int DIRECTIONS_min = 300;
const int DIRECTIONS_max = (DIRECTIONS_min + DIRECTIONS);

enum enum_DIRECTIONS {
    NORTH = DIRECTIONS_min,
    SOUTH,
    EAST,
    WEST,
};


// -------------------------------------------
// LOCATIONS
// -------------------------------------------
const int LOCATIONS = 6;
const int LOCATIONS_min = 400;
const int LOCATIONS_max = (LOCATIONS_min + LOCATIONS);

enum enum_LOCATIONS {
    INV = LOCATIONS_min,
    TRASH,
    LOBBY,
    SUBWAY_STATION,
    ELEVATOR_ONE,
    X
};


// -------------------------------------------
// PASSAGES
// -------------------------------------------
const int PASSAGES = 2;
const int PASSAGES_min = 500;
const int PASSAGES_max = (PASSAGES_min + PASSAGES);

enum enum_PASSAGES {
    SUBWAY_STATION_to_LOBBY = PASSAGES_min,
    LOBBY_to_ELEVATOR_ONE,
};


// -------------------------------------------
// PHYSICAL OBJECTS
// -------------------------------------------
const int PHYSICAL_OBJECTS = 2;
const int PHYSICAL_OBJECTS_min = 600;
const int PHYSICAL_OBJECTS_max = (PHYSICAL_OBJECTS_min + PHYSICAL_OBJECTS);

enum enum_OBJECTS {
    LLAMA_TOKEN = PHYSICAL_OBJECTS_min,
    KEY_CARD_1
};


// -------------------------------------------
// ACTIONS
// -------------------------------------------
const int ACTIONS = 8;
const int ACTIONS_min = 700;
const int ACTIONS_max = (ACTIONS_min + ACTIONS);

enum enum_ACTIONS {
    GO = ACTIONS_min,
    LOOK,
    PRESS,
    GET,
    DROP,
    USE,
    INSPECT,
    INVENTORY
};


// --------------------------------------------
// WORDS
// --------------------------------------------
const int WORDS = 2;
const int WORDS_min = 800;
const int WORDS_max = (WORDS_min + WORDS);

enum enum_WORDS {
    ELEVATOR = WORDS_min,
    EXIT,
};


#endif /* Constants_h */
