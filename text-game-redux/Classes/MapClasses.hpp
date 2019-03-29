//
//  MapClasses.hpp
//  text-game-redux
//  The Location and Passage classes that make up the game map. 
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef MapClasses_hpp
#define MapClasses_hpp

# include "BaseClass.hpp"

class Location;
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
};

// ------- AdminLocation ------- //
// administrative locations, not part of map, e.g. trash, inventory
class AdminLocation : public Location {
public:
    string derivedType();
};


// ------------------------------------------------
// Passage Classes
// ------------------------------------------------

// ------- Passage ------- //
// connects locations together
// abstract, first level subclass
class Passage : public Base {
protected:
    bool hidden_state;
    Location* location_1; // the Location on one side of the passage
    Location* location_2; // the Location on the other side of the passage
public:
    // checks
    virtual bool isHidden();
    // setters
    virtual void setHiddenState(bool new_state);
    virtual void setLocation_1(Location* new_location);
    virtual void setLocation_2(Location* new_location);
    // getters
    virtual Location* getLocation_1();
    virtual Location* getLocation_2();
};

// -------  Deadend ------- //
// Player cannot move through
class Deadend : public Passage {
public:
    string derivedType();
};

// -------  OpenPassage ------- //
// Passages that are always open
class OpenPassage : public Passage {
public:
    string derivedType();
};

// ------- Closed Passage ------- //
// Passages that can be closed and locked
// abstract, second level subclass 
class ClosedPassage : public Passage {
protected:
    bool lock_state;
    bool open_state;
public:
    virtual bool isLocked();
    virtual bool isOpen();
};

// ------- Trapdoor ------- //
// ClosedPassages that open Up or Down
class Trapdoor : public ClosedPassage {
private:
public:
    string derivedType();
};

// ------- RegularDoor ------- //
// ClosedPassages that open in the four regular directions
class RegularDoor : public ClosedPassage {
private:
public:
    string derivedType();
};

#endif /* MapClasses_hpp */
