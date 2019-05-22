//
//  main.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/27/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

// ----- NOTES ----- //
/*
 Have player start without the ability to do anything, with their eyeballs and a note in thier pocket.
 After putting their eyeballs in allow them use of the LOOK command.
 Similarly make them put on their feet to allow them to use the GO command.
 
 Possible names: Requim for a Llama, Harbring of Llamas, Llamajuice Evil Inccorperated, Lamacorp,  Ascent through Llama tower.
 
 Enemys: Llamaguards, Llamposts, Llazerbunnies
 Final Boss: ASCENDED LLAMA.
 */


// ------ DISCLAIMER ------- //
/*
 The inital code I used to begin the project was not mine, it came from a blogpost about creating a text-based game in c++.
 The majority of the project was written entirely by me, any code sourced from the internet will have a link to where I found it.
 
 blogpost: http://cplussplussatplay.blogspot.com/2013/01/text-adventure-games-c-part-4.html
 blogpost source code: https://pastebin.com/UFzveurA
 */

#include <iostream>
#include "Game.hpp"
using namespace std;

int main() {

    
    Game game;
    game.setup();
    game.commandLoop();
    
    return 0;
}
