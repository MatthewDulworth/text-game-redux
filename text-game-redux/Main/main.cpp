//
//  main.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

// ------ DISCLAIMER ------- //
/*
 The inital code I used to begin the project was not mine, it came from a blogpost about creating a text-based game in c++.
 The vast majority of the project was written entirely by me, any code not written by me will have a citation.
 
 blogpost: http://cplussplussatplay.blogspot.com/2013/01/text-adventure-games-c-part-4.html
 blogpost source code: https://pastebin.com/UFzveurA
 */

#include <iostream>
#include "Game.hpp"
using namespace std;

int main() {
    
    Game game;
    game.gameMenu();
    game.commandLoop();
    
    return 0;
}
