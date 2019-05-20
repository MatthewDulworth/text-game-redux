//
//  enactEvents().cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/18/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "Location.hpp"
#include "Passage.hpp"
#include <unistd.h>

// ------------------------------------------------------------------------------------------------------
// enactEvents
// ------------------------------------------------------------------------------------------------------

bool Game::enactEvents(){
    
    /*
    if(gazedUponTheLlamaGod() == true){
        return true;
    }
     */
    
    
    if(locations[LLAMA_SHRINE]->locationHasBeenEntered()){
        if(!passages[MANAGERS_OFFICE_TO_LLAMA_SHRINE]->isVisible()){
            passages[MANAGERS_OFFICE_TO_LLAMA_SHRINE]->setVisibility(VISIBLE);
            cout << "a hidden door is revealed to the east" << endl;
            cout << endl;
            return true;
        }
    }
    
    
    
    return false;
}
