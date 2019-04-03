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
const int LOCATIONS = 4;
const int PASSAGES = 1;
const int DIRECTIONS = 6;
const int PHYSICALOBJECTS = 4;
const int ACTIONS = 2;


// -------------------------------------------
// boolean constants
// -------------------------------------------
const bool UNLOCKED = true;
const bool LOCKED = false;
const bool VISIBLE = true;
const bool HIDDEN = false;


// -------------------------------------------
// parser codes
// -------------------------------------------
enum enum_DIRECTIONS {NORTH, SOUTH, EAST, WEST, UP, DOWN};
enum enum_LOCATIONS {KITCHEN, BEDROOM, INVENTORY, TRASH};
enum enum_PASSAGES {KITCHEN_TO_BEDROOM};
enum enum_OBJECTS {DESK, KEY, WAFFLE_BAT, COINS};
enum enum_ACTIONS {GO, LOOK};

#endif /* Constants_h */
