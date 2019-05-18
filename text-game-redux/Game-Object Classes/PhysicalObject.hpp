//
//  PhysicalObjectClasses.hpp
//  text-game-redux
//  The Physical object classes that the player can interact with 
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#ifndef PhysicalObjectClasses_hpp
#define PhysicalObjectClasses_hpp

#include <vector>
#include <string> 
#include "Base.hpp"

class Location;
class Passage;

// ------------------------------------------------------------------------------------------------------
// PhysicalObject classes
// ------------------------------------------------------------------------------------------------------

// ------------------------------------------------
// PhysicalObject
// ------------------------------------------------
class PhysicalObject : public Base {
protected:
    string description;
    Location* location;
public:
    // setters
    virtual void setDescription(string new_description);
    virtual void setLocation(Location* new_location);
    // getters
    virtual string getDescription();
    virtual Location* getLocation();
    // output
    virtual void printDescription();
};

// ------------------------------------------------
// Item
// ------------------------------------------------
class Item : public PhysicalObject {
public:
    // var management
    virtual void moveTo(Location* location);
    // checks
    virtual bool isInInventory();
    // overridden
    virtual void overridden();
};

// ------------------------------------------------
// Key
// ------------------------------------------------
class Key : public Item {
private:
    int door_type;
public:
    // checks
    bool canUnlock(Passage* door);
    // setters
    void setDoor_Type(int type);
    // getters
    int getDoor_type();
};

// ------------------------------------------------
// Money
// ------------------------------------------------
class Money : public Item {
private:
    double value;
public:
    // setters
    void setValue(double new_value);
    // getters
    double getValue();
};

// ------------------------------------------------
// ImmovableObject
// ------------------------------------------------
class ImmovableObject : public PhysicalObject {
public:
    // overridden
    void overridden();
};

#endif /* PhysicalObjectClasses_hpp */
