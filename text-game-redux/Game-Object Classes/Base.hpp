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

#include <iostream>
#include <string>
#include "Constants.h"
using namespace std;

// ------------------------------------------------
// Base class
// ------------------------------------------------

// Virtual base game-object class: all game-objects are derived from this class
class Base { 
protected:
    int code;
    string name;
public:
    // virtual destructor
    virtual ~Base();
    // pure virtual method
    virtual string derivedType() = 0;
    // setters
    virtual void setCode(int new_code);
    virtual void setName(string new_name);
    // getters
    virtual int getCode();
    virtual string getName();
};

#endif /* BaseClass_hpp */

