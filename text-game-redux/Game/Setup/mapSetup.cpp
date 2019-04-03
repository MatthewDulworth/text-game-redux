//
//  MapSetup.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 3/29/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include "Game.hpp"

// ------------------------------------------------
// mapSetup
// ------------------------------------------------
// popluates the loctions and passages arrays
void Game::mapSetup(){
    
    // ----- object declarations ----- //
    static Room kitchen, bedroom;
    static AdminLocation inventory, trash;
    static OpenPassage kitchen_to_bedroom;
    
    setPlayer_location(&kitchen);
    
    // ----- set rooms ----- //
    kitchen.setCode(KITCHEN);
    kitchen.setName("KITCHEN");
    kitchen.setDescription("a kitchen");
    kitchen.setExit(NORTH, &kitchen_to_bedroom);
    kitchen.setExit(SOUTH, 0);
    kitchen.setExit(EAST, 0);
    kitchen.setExit(WEST, 0);
    kitchen.setExit(UP, 0);
    kitchen.setExit(DOWN, 0);
    
    bedroom.setCode(BEDROOM);
    bedroom.setName("BEDROOM");
    bedroom.setDescription("a bedroom");
    bedroom.setAllExits(0, &kitchen_to_bedroom, 0, 0, 0, 0);
    
    
    // ----- set passages ----- //
    kitchen_to_bedroom.setCode(KITCHEN_TO_BEDROOM);
    kitchen_to_bedroom.setName("KITCHEN_TO_BEDROOM");
    kitchen_to_bedroom.setHiddenState(VISIBLE);
    kitchen_to_bedroom.setRoom_1(&kitchen);
    kitchen_to_bedroom.setRoom_2(&bedroom);
    

    // ----- set adminlocations ----- //
    inventory.setCode(INVENTORY);
    inventory.setName("INVENTORY");
    inventory.setDescription("the player inventory");
    
    trash.setCode(TRASH);
    trash.setName("TRASH");
    trash.setDescription("trash for unneeded physical objects");
    
    
    // ----- set locations array ----- //
    locations[KITCHEN] = &kitchen;
    locations[BEDROOM] = &bedroom;
    locations[INVENTORY] = &inventory;
    locations[TRASH] = &trash;
    
    // ----- set passages array ----- //
    passages[KITCHEN_TO_BEDROOM] = &kitchen_to_bedroom;
}
