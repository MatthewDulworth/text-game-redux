//
//  MARVIN.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 6/4/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include <string>
#include "text_functions.hpp"

int Game::theMARVINcommand(){
    if(commands.at(0) == MARVIN){
        cout << "establishing connection..." << endl;
        wait(1000);
        cout << "scanning... " << endl;
        wait(100);
        cout << "connecting... " << endl;
        wait(100);
        cout << "securing... " << endl;
        wait(250);
        cout << "secure connection established" << endl;
        wait(250);
        
        string player_input;
    
        do{
            cout << ">>> ";
            getline(cin, player_input);
            
            
        }while(player_input != "terminate connection");
        
        cout << "terminating connection..." << endl;
        wait(500);
        cout << "connection terminated" << endl;
        return true;
    }
    else {
        return WRONG_COMMAND;
    }
}
