//
//  gameMenu.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/23/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "text_functions.hpp"
#include "Player.hpp"
#include <string>

void Game::gameMenu(){
    
    loadNewGame();
    
    /*
    while(true){
        string selection;
        string new_game = "new";
        string load_game = "load";
        
        cout << "To begin a new game, type \"" << new_game << "\"" << endl;
        cout << "To continue a previous, type \"" << load_game << "\"" << endl;
        cout << endl << ">>> ";
        getline(cin, selection);
        
        if(selection == new_game){
            loadNewGame();
            
            string player_name;
            cout << endl << "Enter your charecter's first name. " << endl;
            cout << ">>> "; getline(cin, player_name);
            player->setName(player_name);
            
            break;
        }
//        else if (selection == load_game){
//            loadSavedGame();
//            break;
//        }
        else {
            cout << "no valid command entered " << endl << endl;
        }
    }
    clearConsole();
    */
}
