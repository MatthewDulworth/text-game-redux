//
//  GeneralFunctions.cpp
//  text-game-redux
//  Checks the class type of an object
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "GeneralFunctions.hpp"
#include "Passage.hpp"
#include "Location.hpp"
#include <typeinfo>

// ------------------------------------------------
// type checks by code
// ------------------------------------------------
bool isPhysicalObject(int code){
    return (code >= PHYSICAL_OBJECTS_min && code<PHYSICAL_OBJECTS_max);
}
bool isNumber(int code){
    return (code >= NUMBERS_min && code<NUMBERS_max);
}
bool isAction(int code){
    return (code >= ACTIONS_min && code<ACTIONS_max);
}
bool isWord(int code){
    return (code >= WORDS_min && code<WORDS_max);
}
bool isDirection(int code){
    return (code >= DIRECTIONS_min && code < DIRECTIONS_max);
}

// ------------------------------------------------
// getTargetLocation
// ------------------------------------------------
Location* getTargetLocation(Passage* passage, Location* location){
    Location* target_location = 0;
    
    if(location == passage->getLocation_1()){
        target_location = passage->getLocation_2();
    }
    
    else if(location == passage->getLocation_2()){
        target_location = passage->getLocation_1();
    }
    
    return target_location;
}

// ------------------------------------------------
// createTokens
// ------------------------------------------------
vector<string> createTokens(string player_input){
    
    vector<string> tokens;
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
    
    return tokens;
}
