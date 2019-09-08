//
//  Direction.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include "AdminClasses.hpp"

// ------------------------------------------------
// Action methods
// ------------------------------------------------
void Action::overridden(){}
// ----- setSynonym ----- //
void Action::setSynonym(string synonym){
    this->synonym = synonym;
}
// ----- getSynonym ----- //
string Action::getSynonym(){
    return synonym;
}


// ------------------------------------------------
// Direction methods
// ------------------------------------------------
void Direction::overridden(){}


// ------------------------------------------------
// Number methods
// ------------------------------------------------
// ----- setSynonym ----- //
void Number::setSynonym(string synonym){
    this->synonym = synonym;
}
// ----- getSynonym ----- //
string Number::getSynonym(){
    return synonym;
}
// ----- getValue----- //
int Number::getValue(){
    return (code - NUMBERS_min);
}
// ----- overridden ----- //
void Number::overridden(){}

// ------------------------------------------------
// Word methods
// ------------------------------------------------
// ----- setCode ----- //
void Word::setCode(int code){
    this->code = code;
}
// ----- addSynonym ----- //
void Word::addSynonym(string word){
    synonyms.push_back(word);
}
// ----- getCode ----- //
int Word::getCode(){
    return code;
}
// ----- getSynonym ----- //
string Word::getSynonym(int i){
    return synonyms.at(i);
}
void Word::overridden(){}
