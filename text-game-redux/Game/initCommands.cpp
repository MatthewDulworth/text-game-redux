//
//  initCommands.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
//using namespace std;

void Game::initCommands(){
    
    for(int i=0; i<tokens.size(); i++){
        
        int j;
    
        for(j=0; j<DIRECTIONS; j++){
            if(tokens.at(i) == directions[j]->getName() ){
                commands.at(i) = directions[j]->getCode();
                goto end_of_loop;
            }
        }
        for(j=0; j<ACTIONS; j++){
            if(tokens.at(i) == actions[j]->getName() ){
                commands.at(i) = actions[j]->getCode();
                goto end_of_loop;
            }
        }
        for(j=0; j<PHYSICALOBJECTS; j++){
            if(tokens.at(i) == physical_objects[j]->getName() ){
                commands.at(i) = physical_objects[j]->getCode();
                goto end_of_loop;
            }
        }
        for(j=0; j<LOCATIONS; j++){
            if(tokens.at(i) == locations[j]->getName() ){
                commands.at(i) = locations[j]->getCode();
                goto end_of_loop;
            }
        }
        for(j=0; j<PASSAGES; j++){
            if(tokens.at(i) == passages[j]->getName() ){
                commands.at(i) = passages[j]->getCode();
                goto end_of_loop;
            }
        }
    end_of_loop: j=0;
    }
}
