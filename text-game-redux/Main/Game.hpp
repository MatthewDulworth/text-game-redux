//
//  Game.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/28/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "TypeChecks.hpp"

// ------------------------------------------------
// Game class
// ------------------------------------------------
class Game {
private:
    Location* locations[LOCATIONS];
    Passage* passages[PASSAGES];
    PhysicalObject* physical_objects[PHYSICALOBJECTS];
    Action* actions[ACTIONS];
    Direction* directions[DIRECTIONS];
    
public:
    void mapSetup();
    void objectSetup();
    void actionSetup();
    void directionSetup();
};





#include <stdio.h>

#endif /* Game_hpp */
