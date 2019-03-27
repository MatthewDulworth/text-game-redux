//
//  PhysicalObjectClasses.hpp
//  text-game-redux
//  The Physical object classes that the player can interact with 
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef PhysicalObjectClasses_hpp
#define PhysicalObjectClasses_hpp

#include "BaseClass.hpp"
#include "MapClasses.hpp"
// ------------------------------------------------
// PhysicalObject classes
// ------------------------------------------------

// ------- PhysicalObject ------- //
// abstract physical object class
class PhysicalObject : public Base {
protected:
    Location* location;
public:
    virtual void getLocation();
};

// ------- Item ------- //
class Item : public PhysicalObject {
private:
public:
    string derivedType();
};

// ------- Money ------- //
class Money : public PhysicalObject {
private:
public:
    string derivedType();
};

// ------- UnmoveableObject ------- //
class UnmoveableObject : public PhysicalObject {
protected:
    
public:
};

#endif /* PhysicalObjectClasses_hpp */
