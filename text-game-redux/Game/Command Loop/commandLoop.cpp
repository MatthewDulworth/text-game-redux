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
        cout << "Enter a command: ";
        getline(cin, player_input);
        
        if(player_input != "quit"){
            parse(player_input);
            initCommands();
            enactCommands();
        }
        tokens.clear();
        commands.clear();
    }while(player_input != "quit");
}

