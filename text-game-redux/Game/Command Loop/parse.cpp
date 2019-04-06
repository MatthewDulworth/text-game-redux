//
//  Parse.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "Game.hpp"

void Game::parse(string player_input){
    
    string temp;
    char space = ' ';
    
    // convert player_input to uppercase
    transform(player_input.begin(), player_input.end(), player_input.begin(), ::toupper);
    
    // chops player_input into tokens and stores them in the tokens vector
    for(int i=0; i<player_input.size(); i++){
        
        // if the charecter at i is a space, add temp to tokens
        if(player_input.at(i) == space){
            tokens.push_back(temp);
            temp.clear();
        }
        // otherwise insert the charecter at the end of temp
        else{
            temp.insert(temp.end(), player_input.at(i) );
        }
        // if the end of player_input is reached, add temp to tokens
        if(i == player_input.size()-1 ){
            tokens.push_back(temp);
            temp.clear();
        }
    }
    
    // erase blank tokens
    for(unsigned long i=tokens.size()-1; i>0; i--){
        if(tokens.at(i) == ""){
            tokens.erase(tokens.begin()+i);
        }
    }
}


