//
//  enactCommands.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

bool Game::enactCommands(){
    
    // if no command entered
    if(commands.size() == 0){
        cout << "ERROR: No command entered.\n";
        return false;
    }
    
    // if the 'GO' command entered
    if(commands.at(0) == GO){
        if(isDirection(directions[commands.at(1)]) ){
            
        }
    }
    
    // if the 'LOOK' command entered
    if(commands.at(0) == LOOK){
        
    }
    
    
    cout << "ERROR: No valid command entered.\n";
    return false;
}
