//
//  TypeChecks.hpp
//  text-game-redux
//  Checks the class type of an object
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef TypeChecks_hpp
#define TypeChecks_hpp

#include "Base.hpp"
#include "Location.hpp"
#include "Passage.hpp"
#include "PhysicalObject.hpp"
#include "Action.hpp"
#include "Direction.hpp"

bool isRoom(Base*);
bool isElevator(Base*);
bool isAdminLocation(Base*);
bool isPassage(Base* );
bool isItem(Base*);
bool isMoney(Base*);
bool isAction(Base*);
bool isDirection(Base*);

#endif /* TypeChecks_hpp */
