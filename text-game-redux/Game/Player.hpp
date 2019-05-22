//
//  Player.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/22/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>
#include <vector>
#include "constants.h"
using namespace std;

class Location;
class PhysicalObject;

class Player {
private:
    string name;
    Location* location;
    vector<PhysicalObject*> inventory;
    
public:
    // constructor
    Player(Location* starting_location);
    // inventory
    bool isInInventory(PhysicalObject* item);
    void addObjectToInventory(PhysicalObject* item);
    void removeObjectFromInventory(PhysicalObject* item);
    // setters
    void setName(string name);
    void moveTo(Location* location);
    // getters
    string getName();
    Location* getLocation();
};

#endif /* Player_hpp */
