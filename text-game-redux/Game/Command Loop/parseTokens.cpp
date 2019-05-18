//
//  parseTokens.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

// ------------------------------------------------
// parseTokens
// ------------------------------------------------
/// parses tokens into commands
/// if a token matches the name of action, direction, number, or physical object,
/// push back the code of the instance into commands
void Game::parseTokens(){
    
    // loop once for each token in tokens
    for(int i=0; i<tokens.size(); i++){
        
        // second loop variable
        int j;
        
        // ------- Actions ------- //
        for(j=ACTIONS_min; j<ACTIONS_max; j++){
            if(tokens.at(i) == actions[j]->getName() ){
                commands.push_back(actions[j]->getCode() );
                goto end_of_loop;
            }
        }
        
        // ------- Directions ------- //
        for(j=DIRECTIONS_min; j<DIRECTIONS_max; j++){
            if(tokens.at(i) == directions[j]->getName() ){
                commands.push_back(directions[j]->getCode() );
                goto end_of_loop;
            }
        }
        
        // ------- Numbers ------- //
        for(j=NUMBERS_min; j<NUMBERS_max; j++){
            if(tokens.at(i) == numbers[j]->getName() || tokens.at(i) == numbers[j]->getSynonym() ){
                commands.push_back(numbers[j]->getCode() );
                goto end_of_loop;
            }
        }
        
        // ------- Physical Objects ------- //
        for(j=PHYSICAL_OBJECTS_min; j<PHYSICAL_OBJECTS_max; j++){
            if(tokens.at(i) == physical_objects[j]->getName() ){
                commands.push_back(physical_objects[j]->getCode() );
                goto end_of_loop;
            }
        }
    end_of_loop: j=0;
    }
}
