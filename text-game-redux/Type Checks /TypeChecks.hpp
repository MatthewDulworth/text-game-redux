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
bool isNumber(Base*);
bool isAction(Base*);
bool isDirection(Base*);

bool isPhysical_object(int);
bool isNumber(int);
bool isAction(int);
bool isDirection(int);

Location* getTargetLocation(Passage*, Location*);

// ------- isType ------- //
// checks if an object is a given type or is derived from a given type
// source: https://stackoverflow.com/questions/307765/how-do-i-check-if-an-objects-type-is-a-particular-subclass-in-c
template <class DstType, class SrcType>
bool isDerivedFrom(const SrcType* src){
    return dynamic_cast<const DstType*>(src) != nullptr;
}

#endif /* TypeChecks_hpp */
