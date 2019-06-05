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
#include "GeneralFunctions.hpp"
#include "OffsetArray.h"

class Base;
class Location;
class Passage;
class PhysicalObject;
class Action;
class Direction;
class Number;
class Player;

// ------------------------------------------------------------------------------------------------------
// Game class
// ------------------------------------------------------------------------------------------------------
class Game {
private:
    // ------------------------------------------------
    // member variables
    // ------------------------------------------------
    
    // the location of the player
    Player* player;
    
    // arrays of pointers to game-objects
    OffsetArray<Location*, LOCATIONS_min, LOCATIONS_max> locations;
    OffsetArray<Passage*, PASSAGES_min, PASSAGES_max> passages;
    OffsetArray<PhysicalObject*, PHYSICAL_OBJECTS_min, PHYSICAL_OBJECTS_max> physical_objects;
    OffsetArray<Number*, NUMBERS_min, NUMBERS_max> numbers;
    OffsetArray<Action*, ACTIONS_min, ACTIONS_max> actions;
    OffsetArray<Direction*, DIRECTIONS_min, DIRECTIONS_max> directions;
    OffsetArray<Word*, WORDS_min, WORDS_max> words;
    
    // run vars
    vector<string> tokens;
    vector<int> commands;
    
    // event vars
    int last_successfull_action;
    
    
    // ------------------------------------------------
    // private methods
    // ------------------------------------------------
    
    // loads and saves
    void loadNewGame();
    void loadSavedGame();
    void saveGame();
    
    // setup methods
    void mapSetup();
    void physicalObjectSetup();
    void actionSetup();
    void adminClassesSetup();
    
    // command methods
    int theGOcommand();
    int theLOOKcommand();
    int thePRESScommand();
    int theGETcommand();
    int theDROPcommand();
    int theUSEcommand();
    int theMARVINcommand();
    
    // events methods
    
    // methods used in commands
    void movePlayerThroughPassage(Passage* passage);
    bool invalidCommand();
    bool noExit();
    
    // run methods
    bool devCommands(string player_input);
    void parseTokens();
    bool enactCommands();
    bool enactEvents();
    
    
public:
    // ------------------------------------------------
    // public methods
    // ------------------------------------------------
    ~Game();
    void gameMenu();
    void commandLoop();
};

#endif /* Game_hpp */
