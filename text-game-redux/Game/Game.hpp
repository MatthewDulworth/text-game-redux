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
#include "OffsetArray.h"

// ------------------------------------------------
// Game class
// ------------------------------------------------
class Game {
private:
    Location* player_location;

    // arrays of pointers to game-objects
    OffsetArray<Location*, LOCATIONS_min, LOCATIONS_max> locations;
    OffsetArray<Passage*, PASSAGES_min, PASSAGES_max> passages;
    OffsetArray<PhysicalObject*, PHYSICAL_OBJECTS_min, PHYSICAL_OBJECTS_max> physical_objects;
    OffsetArray<Number*, NUMBERS_min, NUMBERS_max> numbers;
    OffsetArray<Action*, ACTIONS_min, ACTIONS_max> actions;
    OffsetArray<Direction*, DIRECTIONS_min, DIRECTIONS_max> directions;
    
    // run vars
    vector<string> tokens;
    vector<int> commands;
    
    
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
    void movePlayerThroughPassage(Passage* passage);
    bool invalidCommand();
    
    // commands
    int theGOcommand();
    int theLOOKcommand();
    int thePRESScommand();
    int theGETcommand();
    int theDROPcommand();
};

#endif /* Game_hpp */
