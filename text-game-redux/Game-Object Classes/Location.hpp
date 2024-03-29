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

#include <string>
#include <vector>
#include "Base.hpp"
#include "OffsetArray.h"

class PhysicalObject;
class Passage;
class Elevator;

// ------------------------------------------------------------------------------------------------------
// Location classes
// ------------------------------------------------------------------------------------------------------

// ------------------------------------------------
// Location
// ------------------------------------------------
// locations that physical objects and the player can be in
// abstract, first level subclass
class Location : public Base {
private:
    typedef Base super;
protected:
    int entered_count;
    string description;
    vector<PhysicalObject*> contents;
public:
    // admin
    virtual void addObject(PhysicalObject* object);
    virtual void removeObject(PhysicalObject* object);
    virtual void incrementEnteredCount();
    // checks
    virtual bool locationHasBeenEntered();
    // setters
    virtual void setDescription(string new_string);
    // getters
    virtual string getDescription();
};

// ------------------------------------------------
// Location
// ------------------------------------------------
class ElevatorCallButton {
private:
    Elevator* elevator;
    bool visibility;
public:
    // checks
    bool isVisible();
    // setters
    void setVisibility(bool visibility);
    void setElevator(Elevator* new_elevator);
    // getters
    Elevator* getElevator();
};


// ------------------------------------------------
// Room
// ------------------------------------------------
// map locations, have exits, connect to other locations
class Room : public Location {
private:
    typedef Location super;
    int floor;
    OffsetArray<Passage*, DIRECTIONS_min, DIRECTIONS_max> exits;
    OffsetArray<ElevatorCallButton*, DIRECTIONS_min, DIRECTIONS_max> call_buttons;
public:
    // structors
    Room();
    ~Room();
    // init
    void initCallButtons();
    void updateButtonVisibility();
    // checks
    bool hasVisibleButton(int direction);
    // setters
    void setFloor(int new_floor);
    void setExit(int direction, Passage* exit);
    void setAllExits(Passage* exit_north, Passage* exit_south, Passage* exit_east, Passage* exit_west, Passage* exit_up, Passage* exit_down);
    // getters
    int getFloor();
    Passage* getExit(int direction);
    ElevatorCallButton* getButton(int direction);
    // overridden
    void overridden();
};


// ------------------------------------------------
// ElevatorFloorButton
// ------------------------------------------------
class ElevatorFloorButton{
private:
    int floor;
    bool visibility;
public:
    // checks
    bool isVisible();
    // setters
    void setVisibility(bool visibility);
    void setFloor(int floor);
    // getters
    int getFloor();
};


// ------------------------------------------------
// Elevator
// ------------------------------------------------
class Elevator : public Location {
private:
    typedef Location super;
    int exit_direction;
    int current_floor;
    OffsetArray<ElevatorFloorButton*, FLOORS_min, FLOORS_max> floor_buttons;
    OffsetArray<Passage*, FLOORS_min, FLOORS_max> exits;
    Passage* current_exit;
public:
    // structors
    Elevator();
    ~Elevator();
    // init
    void initButtons();
    void updateButtonsVisibility();
    // checks
    bool buttonIsVisibile(int floor);
    // setters
    void setExit_direction(int direction);
    void setExit(int floor, Passage* exit);
    void setCurrent_floor(int floor);
    // getters
    int getFloors();
    int getCurrent_floor();
    int getExit_direction();
    int getCurrentFloorNumber();
    Passage* getCurrent_exit();
    // overridden
    void overridden();
};


// ------------------------------------------------
// AdminLocation
// ------------------------------------------------
// administrative locations, not part of map, e.g. trash, inventory
class AdminLocation : public Location {
public:
    void overridden();
};

#endif /* Location */
