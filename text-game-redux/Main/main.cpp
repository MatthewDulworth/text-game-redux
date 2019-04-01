//
//  main.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
using namespace std;

int main() {

    Game game;
    game.setup();
    game.commandLoop();
    
    
    return 0;
}
