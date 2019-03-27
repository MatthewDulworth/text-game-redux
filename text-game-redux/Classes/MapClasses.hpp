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
// Location class: locations that physical objects and the player can be in
class Location : public Base {
private:
    Passage* exits[DIRECTIONS]; // an array of pointers to passages, can be any type of passage
public:
    string derivedType();
};


// ------------------------------------------------
// Passage Classes
// ------------------------------------------------

// ------- Passage ------- //
// connects locations together
// abstract
class Passage : public Base {
protected:
    bool hidden_state;
    Location* location_1;
    Location* location_2;
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


// -------  OpenPassage ------- //
// Passages that are always open
class OpenPassage : public Passage {
private:
public:
    string derivedType();
};

// ------- Closed Passage ------- //
// Passages that can be closed
// abstract
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
