//
//  GeneralFunctions.hpp
//  text-game-redux
//  Checks the class type of an object
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef GeneralFunctions_hpp
#define GeneralFunctions_hpp

#include "AdminClasses.hpp"

class Location;
class Passage;

bool isWord(int);
bool isPhysicalObject(int);
bool isNumber(int);
bool isAction(int);
bool isDirection(int);
Location* getTargetLocation(Passage*, Location*);
vector<string> createTokens(string);

// ------- isType ------- //
// checks if an object is a given type or is derived from a given type
// source: https://stackoverflow.com/questions/307765/how-do-i-check-if-an-objects-type-is-a-particular-subclass-in-c
template <class DstType, class SrcType>
bool isType(const SrcType* src){
    return dynamic_cast<const DstType*>(src) != nullptr;
}

#endif /* GeneralFunctions_hpp */
