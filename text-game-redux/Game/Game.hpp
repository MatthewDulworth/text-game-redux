//
//  Game.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/28/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <string>
#include <vector>
#include "TypeChecks.hpp"
#include "Player.hpp"

// ------------------------------------------------
// Game class
// ------------------------------------------------
class Game {
private:
    Location* player_location;
    
    // arrays of pinters to game-objects
    Location* locations[LOCATIONS];
    Passage* passages[PASSAGES];
    PhysicalObject* physical_objects[PHYSICALOBJECTS];
    Action* actions[ACTIONS];
    Direction* directions[DIRECTIONS];
    
    // run vars
    string player_input;
    vector<string> tokens;
    vector<int> commands;
    
public:
    // setup functions
    void mapSetup();
    void objectSetup();
    void actionSetup();
    void directionSetup();
    void setup();
    
    // run functions
    void parse();
    void initCommands();
    bool enactCommands();
    void commandLoop();
};

#endif /* Game_hpp */
