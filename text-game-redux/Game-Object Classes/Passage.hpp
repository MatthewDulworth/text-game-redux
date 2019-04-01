//
//  Passage.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef Passage_hpp
#define Passage_hpp

#include "Base.hpp"
#include "Location.hpp"
class Room;

// ------------------------------------------------
// Passage Classes
// ------------------------------------------------

// ------- Passage ------- //
// connects locations together
// abstract, first level subclass
class Passage : public Base {
protected:
    bool hidden_state;
    Room* room_1; // the Room on one side of the passage
    Room* room_2; // the Room on the other side of the passage
public:
    // checks
    virtual bool isHidden();
    // setters
    virtual void setHiddenState(bool new_state);
    virtual void setRoom_1(Room* new_location);
    virtual void setRoom_2(Room* new_location);
    // getters
    virtual Room* getRoom_1();
    virtual Room* getRoom_2();
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


#endif /* Passage_hpp */
