//
//  Location.hpp
//  text-game-redux
//  The Location and Passage classes that make up the game map. 
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include "Base.hpp"
#include <vector>
class Passage;

// ------------------------------------------------
// Location classes
// ------------------------------------------------

// ------- Location ------- //
// locations that physical objects and the player can be in
// abstract, first level subclass
class Location : public Base {
protected:
    string description;
public:
    virtual void setDescription(string new_string);
    virtual string getDescription();
    virtual void printDescription();
    virtual Passage* exitTo(int direction);
};

// ------- Room ------- //
// map locations, have exits, connect to other locations
class Room : public Location {
private:
    Passage* exits[DIRECTIONS];
public:
    string derivedType();
    void setExit(int direction, Passage* exit);
    void setAllExits(Passage* exit_north, Passage* exit_south, Passage* exit_east, Passage* exit_west, Passage* exit_up, Passage* exit_down);
    Passage* exitTo(int direction);
};

// ------- Elevator ------- //
class Elevator : public Location{
private:
    Passage* exits[FLOORS];
    Passage* current_exit;
public:
    string derivedType();
    void setExit(int floor, Passage* exit);
    void setFloor(int floor);
    Passage* getCurrent_exit();
};

// ------- AdminLocation ------- //
// administrative locations, not part of map, e.g. trash, inventory
class AdminLocation : public Location {
public:
    string derivedType();
};

#endif /* Location */
