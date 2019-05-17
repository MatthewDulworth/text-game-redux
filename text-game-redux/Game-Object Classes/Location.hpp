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
#include "PhysicalObject.hpp"
#include "OffsetArray.h"
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
    vector<PhysicalObject*> contents;
public:
    // setters
    virtual void setDescription(string new_string);
    virtual void addObject(PhysicalObject* object);
    virtual void removeObject(PhysicalObject* object);
    // getters
    virtual string getDescription();
};
// ------------------------------------------------





// ------------------------------------------------
// Room
// ------------------------------------------------
// map locations, have exits, connect to other locations
class Room : public Location {
private:
    int floor;
    OffsetArray<Passage*, DIRECTIONS_min, DIRECTIONS_max> exits;
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





// ------------------------------------------------
// ElevatorButton
// ------------------------------------------------
class ElevatorButton{
private:
    int floor;
    bool visible_state;
public:
    // methods
    bool isVisible();
    // setters
    void setVisibleState(bool new_visible_state);
    void setFloor(int new_floor);
    // getters
    int getFloor();
};
// ------------------------------------------------






// ------------------------------------------------
// Elevator
// ------------------------------------------------
class Elevator : public Location {
    
private:
    
    // ------------------------------
    // private member variables
    // ------------------------------
    
    // the direction the elevator doors open
    int exit_direction;
    
    // the current floor the elevator
    int current_floor;
    
    // elevator buttons for every floor
    OffsetArray<ElevatorButton*, FLOORS_min, FLOORS_max> buttons;
    
    // the passages which the elevator connects to at each floor
    OffsetArray<Passage*, FLOORS_min, FLOORS_max> exits;
    
    // the passage on the floor that the elevator is currently at
    Passage* current_exit;
    

public:
    
    // ------------------------------
    // destructor
    // ------------------------------
    ~Elevator();
    
    
    // ------------------------------
    // public methods
    // ------------------------------

    // returns the first level subclass name
    // must be overriden for the class not to be abstract
    string derivedType();
    
    // checks if the button for a floor is visble to the player
    bool buttonIsVisibile(int floor);
    
    
    // ----- setters ----- //
    // sets the direction that the elevator doors open
    void setExit_direction(int direction);
    
    // sets the exit at a given floor
    void setExit(int floor, Passage* exit);
    
    // sets the current floor and current exit
    void setCurrent_floor(int floor);
    
    // creates the buttons calls updateButtonVisibility()
    void initButtons();
    
    // updates the visibility of eaach button based on whether or not the elevator can go to that floor and whether or not the exit on the floor is visible
    void updateButtonsVisibility();
    
    
    // ----- getters ----- //
    // returns the floor the elevator is currently on
    int getCurrent_floor();
    
    // returns direction direction the elevator doors open
    int getExit_direction();
    
    // returns 1 if on the first floor etc.
    int getCurrentFloorNumber();
    
    // returns the current exit
    Passage* getCurrent_exit();
    
};
// ------------------------------------------------





// ------------------------------------------------
// AdminLocation
// ------------------------------------------------
// administrative locations, not part of map, e.g. trash, inventory
class AdminLocation : public Location {
public:
    string derivedType();
};

#endif /* Location */
