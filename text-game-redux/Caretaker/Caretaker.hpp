//
//  Caretaker.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 6/3/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef Caretaker_hpp
#define Caretaker_hpp

#include <string>
#include <vector>
using namespace std;
class Player;

class Caretaker {
private:
    string name;
    char con_char;
public:
    Caretaker(string name, char con_char);
    void setCon_char(char c);
    char getChar();
};




#endif /* Caretaker_hpp */
