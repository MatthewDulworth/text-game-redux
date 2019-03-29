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
// number of each type of thing
// -------------------------------------------
const int LOCATIONS = 4;
const int PASSAGES = 4;
const int DIRECTIONS = 4;
const int PHYSICALOBJECTS = 2;
const int ITEMS = 1;
const int ACTIONS = 2;
const int NONE = -1;

const bool UNLOCKED = true;
const bool LOCKED = false;
const bool OPEN = true;
const bool CLOSED = false;
const bool VISIBLE = true;
const bool HIDDEN = false;


// -------------------------------------------
// parser codes
// -------------------------------------------
enum enum_DIRECTIONS {NORTH, SOUTH, EAST, WEST, UP, DOWN};
enum enum_LOCATIONS {KITCHEN, BEDROOM, INVENTORY, TRASH};
enum enum_PASSAGES {P1, P2, P3, P4};
enum enum_OBJECTS {DESK, KEY};
enum enum_ACTIONS {GO, LOOK};

#endif /* Constants_h */
