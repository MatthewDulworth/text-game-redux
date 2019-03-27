//
//  classes.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef classes_hpp
#define classes_hpp

#include <string>
using namespace std;

// forward declarations
class Base;             // All parseable game-objects are derived from this class
class Location;
class Passage;
class Action;
class PhysicalObject;




// Virtual base game-object class: all parseable game-objects are derived from this class
class Base {
protected:
    int code;
    string name;
public:
    virtual void func() = 0;
    // getters
    virtual int getCode();
    virtual string getName();
};

// Location class: locations that physical objects and the player can be in
class Location : public Base {
private:
    
public:
    void func();
};

// Passage class: connects locations together
class Passage : public Base {
private:
    
    
public:
    void func();
};

class OpenPassage : public Passage {
    
};

// action class
class Action : public Base {
private:
    
public:
    void func();
};

// base Physical object class
class PhysicalObject : public Base {
protected:
    
public:
    void func();
};




#endif /* classes_hpp */

