//
//  gameMenu.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/23/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "text_functions.hpp"
#include <string>

void Game::gameMenu(){
    
    while(true){
        string selection;
        string new_game = "new game";
        string load_game = "load save";
        
        cout << "To begin a new game, type \"" << new_game << "\"" << endl;
        cout << "To continue a previous, type \"" << load_game << "\"" << endl;
        cout << endl << ">>> ";
        getline(cin, selection);
        
        if(selection == new_game){
            loadNewGame();
            break;
        }
        else if (selection == load_game){
            loadNewGame();
            break;
        }
        else {
            cout << "no valid command entered " << endl;
        }
    }
    clearConsole();
}
