//
//  Player.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/22/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#include <vector>
#include <algorithm>
#include "Player.hpp"
#include "Location.hpp"
using namespace std;

Player::Player(Location* starting_location){
    location = starting_location;
}

bool Player::isInInventory(PhysicalObject* item){
    
    
    return false;
}

void Player::addObjectToInventory(PhysicalObject* item){
    inventory.push_back(item);
}

void Player::removeObjectFromInventory(PhysicalObject* item){
    inventory.erase(std::remove(inventory.begin(), inventory.end(), item ), inventory.end() );
}

void Player::setName(string name){
    this->name = name;
}

void Player:: changeLocation(Location* location){
    this->location = location;
}

string Player::getName(){
    return name;
}

Location* Player::getLocation(){
    return location;
}
