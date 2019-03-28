//
//  SetupClasses.hpp
//  text-game-redux
//  The Action and Direction classes. 
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef SetupClasses_hpp
#define SetupClasses_hpp

#include "BaseClass.hpp"

// ------------------------------------------------
// Action Class
// ------------------------------------------------
class Action : public Base {
public:
    string derivedType();
};

// ------------------------------------------------
// Direction Class
// ------------------------------------------------
class Direction : public Base {
private:
    
public:
    string derivedType();
};

#endif /* SetupClasses_hpp */
