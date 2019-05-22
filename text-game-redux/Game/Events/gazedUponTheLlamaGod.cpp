//
//  gazedUponTheLlamaGod.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/19/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"
#include "Player.hpp"
#include "text_functions.hpp"

bool Game::gazedUponTheLlamaGod(){
    
    if(player->getLocation() == locations[LLAMA_SHRINE] && last_successfull_action == LOOK){
        typeText("You hear a voice booming through your head: ");
        typeText("\"MORTAl! YOU DARE GAZE UPON THE SHRINE OF THE LLAMA GOD!?\"");
        typeText("\"HAS YOUR ARROGANCE NO BOUNDS?\"");
        typeText("\"RETURN, WORM, TO THE DUST FROM WHENCE YOU CAME.\"");
        typeText("You notice something dripping from your eyes and nose.");
        typeText("You glance down, it's blood." );
        typeText("Your vision starts to fade and your legs start to feel numb.");
        typeText("You collapse to the ground, the last thing your failing eyes see is the graven image of the Llama God staring mockingly down...");
        wait(5000);
        scrollDown(console_height, 10);
        centerText("Game Over");
        newline(console_height/2);
        exit(0);
    }
    else{
        return false;
    }
}
