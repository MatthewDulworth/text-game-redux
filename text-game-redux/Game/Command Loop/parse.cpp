//
//  initCommands.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

void Game::parse(){
    
    for(int i=0; i<tokens.size(); i++){
        
        int j;
    
        for(j=0; j<ACTIONS; j++){
            if(tokens.at(i) == actions[j]->getName() ){
                command.push_back(actions[j]->getCode() );
                goto end_of_loop;
            }
        }
        for(j=0; j<DIRECTIONS; j++){
            if(tokens.at(i) == directions[j]->getName() ){
                command.push_back(directions[j]->getCode() );
                goto end_of_loop;
            }
        }
        for(j=0; j<NUMBERS; j++){
            if(tokens.at(i) == numbers[j]->getName() ){
                command.push_back(numbers[j]->getCode() );
                goto end_of_loop;
            }
        }
        for(j=0; j<PHYSICALOBJECTS; j++){
            if(tokens.at(i) == physical_objects[j]->getName() ){
                command.push_back(physical_objects[j]->getCode() );
                goto end_of_loop;
            }
        }
    end_of_loop: j=0;
    }
}
