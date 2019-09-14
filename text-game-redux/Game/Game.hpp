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
#include "Location.hpp"
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
    
    // Charecters
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
    
    // setup methods
    void mapSetup();
    void physicalObjectSetup();
    void actionSetup();
    void adminClassesSetup();
    void createMapElements();
    void setupAdminLocation(int code, string name, string description);
    void setupRoom(int code, string name, string description, int floor, int exit_north, int exit_south, int exit_east, int exit_west);
    void setupElevator(int code, string name, string description, int startingFloor, int exitDirection, Passage* exits[]);
    void setupPassage(int code, bool lockState, bool visibility, Location* location_1, Location* location_2);
    void initCallButtons();
    
    // command methods
    int theGOcommand();
    int theLOOKcommand();
    int thePRESScommand();
    int theGETcommand();
    int theDROPcommand();
    int theUSEcommand();
    int theINVENTORYcommand();
    int theINSPECTcommand();
    
    // events methods
    
    // methods used in commands
    void movePlayerThroughPassage(Passage* passage);
    bool invalidCommand();
    bool noExit();
    
    // run methods
    bool devCommands(string player_input);
    void parseTokensToCommands();
    void parseTokensToWords();
    bool enactCommands();
    bool enactEvents();
    
    
public:
    // ------------------------------------------------
    // public methods
    // ------------------------------------------------
    ~Game();
    void commandLoop();
    void setup();
};

#endif /* Game_hpp */
