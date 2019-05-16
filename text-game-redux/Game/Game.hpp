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
    Number* numbers[NUMBERS];
    Action* actions[ACTIONS];
    Direction* directions[DIRECTIONS];
    
    // run vars
    vector<string> tokens;
    vector<int> command;
    
public:
    // setup methods
    void test();
    void mapSetup();
    void physicalObjectSetup();
    void actionSetup();
    void directionSetup();
    void setup();
    void setPlayer_location(Location* new_location);
    
    // run methods
    void createTokens(string player_input);
    void parseTokens();
    bool enactCommands();
    void commandLoop();
    
    // enactCommands methods
    Location* createTargetLocation(Passage* current_passage, Location*);
    void movePlayerThroughPassage(Passage* passage);
};

#endif /* Game_hpp */
