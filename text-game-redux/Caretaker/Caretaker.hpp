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
    vector<string> tokens;
public:
    Caretaker(string name);
    bool conversation();
};




#endif /* Caretaker_hpp */
