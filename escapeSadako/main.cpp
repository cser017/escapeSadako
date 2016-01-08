//
//  main.cpp
//  escapeSadako
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2016 Chen Cai. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#include "agent.h"
#include "room.h"

int main(){
    //set up rooms
    Room *gate = new Room("Gate", "locked in a house.");
    Room *livingroom = new Room("livingroom", "center of the house.");
    Room *toilet = new Room("toilet","unlighted toilet.");
    Room *outerspace = new Room("outerspace", "something weird happen, you are out of earth.");
    Room *SECRET_ROOM = new Room("SECRET ROOM", "Key is here!!!");
    
    //link the world together
    gate->link("NORTH",livingroom);
    livingroom->link("WEST",toilet);
    livingroom->link("EAST", outerspace);
    livingroom->link("SOUTH", gate);
    toilet->link("EAST", livingroom);
    outerspace->link("WEST", livingroom);
    outerspace->link("NORTH", SECRET_ROOM);
    SECRET_ROOM->link("SOUTH", outerspace);
    
    Player* Ccookie = new Player("Ccookie", "Player 1");
    Ccookie->moveTo(gate);
    Thing* key = new Thing("Key", "To unlock to door");
    key->moveTo(SECRET_ROOM);
    
    vector<Player*> agents_in_game;
    agents_in_game.push_back(Ccookie);
    
    //keep game on until the key have been found
    bool gameOn = true;
    while (gameOn) {
        for (auto player_ptr:agents_in_game){
            gameOn = player_ptr->act();
        }
    }
    cout<<"Key Found. Game over."<<endl;
    
    return 0;
}