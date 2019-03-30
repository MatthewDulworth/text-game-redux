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

#include "BaseClass.hpp"
#include "MapClasses.hpp"
#include "PhysicalObjectClasses.hpp"
#include "SetupClasses.hpp"
#include <typeinfo>

bool isRoom(Base*);
bool isAdminLocation(Base*);
bool isDeadend(Base*);
bool isOpenPassage(Base*);
bool isTrapdoor(Base*);
bool isRegularDoor(Base*);
bool isItem(Base*);
bool isMoney(Base*);
bool isAction(Base*);
bool isDirection(Base*);

#endif /* TypeChecks_hpp */
