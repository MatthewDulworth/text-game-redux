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
// Location
// ------------------------------------------------
// locations that physical objects and the player can be in
// abstract, first level subclass
class Location : public Base {
protected:
    string description;
public:
    // setters
    virtual void setDescription(string new_string);
    // getters
    virtual string getDescription();
};

// ------------------------------------------------
// Room
// ------------------------------------------------
// map locations, have exits, connect to other locations
class Room : public Location {
private:
        int floor;
    Passage* exits[DIRECTIONS];
public:
    string derivedType();
    // setters
        virtual void setFloor(int new_floor);
    void setExit(int direction, Passage* exit);
    void setAllExits(Passage* exit_north, Passage* exit_south, Passage* exit_east, Passage* exit_west, Passage* exit_up, Passage* exit_down);
    // getters
        virtual int getFloor();
    Passage* exitTo(int direction);
};

// ------------------------------------------------
// Elevator
// ------------------------------------------------
class Elevator : public Location{
private:
    int exit_direction;
    int floor;
    Passage* exits[FLOORS];
    Passage* current_exit;
public:
    string derivedType();
    // setters
    void setExit_direction(int direction);
    void setExit(int floor, Passage* exit);
    void setFloor(int floor);
    // getters
    int getFloor();
    int getExit_direction();
    Passage* getCurrent_exit();
};

// ------------------------------------------------
// AdminLocation
// ------------------------------------------------
// administrative locations, not part of map, e.g. trash, inventory
class AdminLocation : public Location {
public:
    string derivedType();
};

#endif /* Location */
