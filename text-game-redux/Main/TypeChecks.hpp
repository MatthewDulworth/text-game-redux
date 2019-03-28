//
//  TypeChecks.hpp
//  text-game-redux
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

bool isLocation(Base*);
bool isOpenPassage(Base*);
bool isTrapdoor(Base*);
bool isRegularDoor(Base*);
bool isItem(Base*);
bool isMoney(Base*);
bool isAction(Base*);
bool isDirection(Base*);

#endif /* TypeChecks_hpp */
