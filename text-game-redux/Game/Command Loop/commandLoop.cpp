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
        cout << ">>> "; 
        getline(cin, player_input);
        
        if(player_input != "quit"){
            createTokens(player_input);     
            parseTokens();
            enactCommands();
            cout << endl;
            enactEvents();
        }
        tokens.clear();
        commands.clear();
        
    }while(player_input != "quit");

    cout << "quitting game" << endl;
}

