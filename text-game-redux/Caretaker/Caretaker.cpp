//
//  Caretaker.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 6/3/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include <string>
#include <vector>
#include "Caretaker.hpp"
using namespace std;

Caretaker::Caretaker(string name, char con_char){
    this->name = name;
    this->con_char = con_char;
}

void Caretaker::setCon_char(char c){
    con_char = c;
}

char Caretaker::getChar(){
    return con_char;
}
