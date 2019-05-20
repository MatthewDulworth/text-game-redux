//
//  enactEvents().cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include <unistd.h>

// ------------------------------------------------------------------------------------------------------
// enactEvents
// ------------------------------------------------------------------------------------------------------

bool Game::enactEvents(){
    
    if(gazedUponTheLlamaGod() == true){
        return true;
    }
    
    return false;
}
