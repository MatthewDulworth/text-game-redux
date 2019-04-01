//
//  commandLoop.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

void Game::commandLoop(){
    string player_input;
    
    do{
        if(player_input != "quit"){
            
            cout << "Enter a command: ";
            getline(cin, player_input);
            
            parse(player_input);
            initCommands();
            enactCommands();
        }
        tokens.clear();
        commands.clear();
        player_input.clear();
    }while(player_input != "quit");
}

