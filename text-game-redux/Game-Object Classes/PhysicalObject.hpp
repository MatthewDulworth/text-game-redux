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
#include "Base.hpp"
class Location;
class Passage;
// ------------------------------------------------
// PhysicalObject classes
// ------------------------------------------------

// ------- PhysicalObject ------- //
// abstract physical object class
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
    //
    virtual void printDescription();
};

// ------- Item ------- //
class Item : public PhysicalObject {
public:
    string derivedType();
    bool isInInventory();
};

// -------- Key ------- //
class Key : public Item {
private:
    int door_type;
public:
    void setDoor_Type(int type);
    int getDoor_type();
    bool canUnlock(Passage* door);
};

// ------- Money ------- //
class Money : public Item {
private:
    double worth;
public:
    // setters
    void setWorth(double new_worth);
    // getters
    double getWorth();
};


// ------- UnmoveableObject ------- //
class ImmovableObject : public PhysicalObject {
public:
    string derivedType();
};

#endif /* PhysicalObjectClasses_hpp */
