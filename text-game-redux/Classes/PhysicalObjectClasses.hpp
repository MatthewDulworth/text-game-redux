//
//  PhysicalObjectClasses.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef PhysicalObjectClasses_hpp
#define PhysicalObjectClasses_hpp

#include "BaseClass.hpp"
// ------------------------------------------------
// PhysicalObject classes
// ------------------------------------------------

// ------- PhysicalObject ------- //
// abstract physical object class
class PhysicalObject : public Base {
protected:
    
public:
};

// ------- MoveableObject ------- // 
class MoveableObject : public PhysicalObject {
protected:
    
public:
    void func();
    
};

class UnmoveableObject : public PhysicalObject {
protected:
    
public:
    void func();
};

#endif /* PhysicalObjectClasses_hpp */
