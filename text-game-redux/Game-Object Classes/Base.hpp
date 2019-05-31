//
//  classes.hpp
//  text-game-redux
//  The Base class for all game-objects.
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef BaseClass_hpp
#define BaseClass_hpp

#include <string>
#include "Constants.h"
using namespace std;

// ------------------------------------------------------------------------------------------------------
// Base class
// ------------------------------------------------------------------------------------------------------
// Virtual base game-object class: all game-objects are derived from this class
class Base { 
protected:
    int code;
    string name;
public:
    // virtual destructor
    virtual ~Base();
    // pure virtual method
    virtual void overridden() = 0;
    // setters
    virtual void setCode(int new_code);
    virtual void setName(string new_name);
    // getters
    virtual int getCode();
    virtual string getName();
};

// all derived class use a version of the follwoing to emulate the super keyword in java.
//
// typedef Base super;
//
// with base being whatever the immeadiate superclass of the current class.
// source: https://stackoverflow.com/questions/180601/using-super-in-c

#endif /* BaseClass_hpp */

