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

// ------------------------------------------------------------------------------------------------------
// Passage class
// ------------------------------------------------------------------------------------------------------
// connects locations together
// abstract, first level subclass
class Passage : public Base {
private:
    typedef Base super;
    bool lock_state;
    bool visibility;
    int key_type;
    Location* location_1;
    Location* location_2;
public:
    // checks
    bool isVisible();
    bool isUnlocked();    
    // setters
    void setLockState(bool state);
    void setVisibility(bool state);
    void setKey_type(int type);
    void setLocation_1(Location* new_location);
    void setLocation_2(Location* new_location);
    // getters
    int getKey_type();
    Location* getLocation_1();
    Location* getLocation_2();
    // overridden
    void overridden();
};

#endif /* Passage_hpp */
