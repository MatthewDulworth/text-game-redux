//
//  parseTokens.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

void Game::parseTokens(){
    
    for(int i=0; i<tokens.size(); i++){
        
        int j;
    
        for(j=ACTIONS_min; j<ACTIONS_max; j++){
            if(tokens.at(i) == actions[j]->getName() ){
                commands.push_back(actions[j]->getCode() );
                goto end_of_loop;
            }
        }
        for(j=DIRECTIONS_min; j<DIRECTIONS_max; j++){
            if(tokens.at(i) == directions[j]->getName() ){
                commands.push_back(directions[j]->getCode() );
                goto end_of_loop;
            }
        }
        for(j=NUMBERS_min; j<NUMBERS_max; j++){
            if(tokens.at(i) == numbers[j]->getName() ){
                commands.push_back(numbers[j]->getCode() );
                goto end_of_loop;
            }
        }
        for(j=PHYSICAL_OBJECTS_min; j<PHYSICAL_OBJECTS_max; j++){
            if(tokens.at(i) == physical_objects[j]->getName() ){
                commands.push_back(physical_objects[j]->getCode() );
                goto end_of_loop;
            }
        }
    end_of_loop: j=0;
    }
}
