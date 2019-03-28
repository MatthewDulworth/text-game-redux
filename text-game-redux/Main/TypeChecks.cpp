//
//  TypeChecks.cpp
//  text-game-redux
//  Checks the class type of an object
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "TypeChecks.hpp"

// ------- Location ------- //
bool isLocation(Base* unkown_object){
    Location* known_object;
    if( (known_object = dynamic_cast<Location*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- OpenPassage ------- //
bool isOpenPassage(Base* unkown_object){
    OpenPassage* known_object;
    if( (known_object = dynamic_cast<OpenPassage*>(unkown_object)) ) return true;
    else
        return false;
}

// ------- Trapdoor ------- //
bool isTrapdoor(Base* unkown_object){
    Trapdoor* known_object;
    if( (known_object = dynamic_cast<Trapdoor*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- RegularDoor ------- //
bool isRegularDoor(Base* unkown_object){
    RegularDoor* known_object;
    if( (known_object = dynamic_cast<RegularDoor*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Item ------- //
bool isItem(Base* unkown_object){
    Item* known_object;
    if( (known_object = dynamic_cast<Item*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Money ------- //
bool isMoney(Base* unkown_object){
    Money* known_object;
    if( (known_object = dynamic_cast<Money*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Action ------- //
bool isAction(Base* unkown_object){
    Action* known_object;
    if( (known_object = dynamic_cast<Action*>(unkown_object)) )
        return true;
    else
        return false;
}

// ------- Direction ------- //
bool isDirection(Base* unkown_object){
    Direction* known_object;
    if( (known_object = dynamic_cast<Direction*>(unkown_object)) )
        return true;
    else
        return false;
}


