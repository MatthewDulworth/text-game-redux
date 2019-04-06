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
class Location;

// ------------------------------------------------
// Passage Classes
// ------------------------------------------------

// ------- Passage ------- //
// connects locations together
// abstract, first level subclass
class Passage : public Base {
protected:
    bool lock_state;    // whether or not the passage is locked
    bool hidden_state;  // whether or not the passage is visible to the player
    Location* room_1;       // the Room on one side of the passage
    Location* room_2;       // the Room on the other side of the passage
public:
    string derivedType();
    // checks
    bool isVisible();
    bool isLocked();    // do nothing for now
    // setters
    void setLockState(bool state);
    void setHiddenState(bool new_state);
    void setRoom_1(Location* new_location);
    void setRoom_2(Location* new_location);
    // getters
    Location* getRoom_1();
    Location* getRoom_2();
};

#endif /* Passage_hpp */
