//
//  main.cpp
//  homework 7
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#include "agent.h"
#include "room.h"
#include "thing.h"


int main(){
    srand(time(NULL));
    cout<<"The game is on."<<endl<<"You find yourself in a gruesome room. And you feel like something is chasing you...If you are scared out,please enter 'quit'.\n"<<endl;
    Room *gate = new Room("Gate", "locked in a house.");
    Room *livingroom = new Room("livingroom", "center of the house.");
    Room *toilet = new Room("toilet","unlighted toilet.");
    Room *outerspace = new Room("outerspace", "something weird happen, you are bounced out of earth.");
    Room *space_ship = new Room("space_ship", "a secret room");
    Room *bedroom=new Room("Bedroom","Window sealed up.");
    Room *AncientTime=new Room("100 years ago","Besides a well");
    
    gate->link("north",livingroom);
    livingroom->link("west",toilet);
    toilet->link("up", outerspace);
    toilet->link("down", AncientTime);
    AncientTime->link("up", toilet);
    AncientTime->link("east", bedroom);
    AncientTime->link("west", outerspace);
    livingroom->link("south", gate);
    livingroom->link("north", bedroom);
    bedroom->link("south", livingroom);
    bedroom->link("west", AncientTime);
    toilet->link("east", livingroom);
    outerspace->link("down", toilet);
    outerspace->link("east", AncientTime);
    outerspace->link("north", space_ship);
    space_ship->link("south", outerspace);
    
    Player* Ccookie = new Player("Ccookie", "Player");
    Ccookie->moveTo(gate);
    
    Thing* Box = new Thing("Box", "Can bring you back home");
    outerspace->getThings(Box);
    Thing* Soap= new Thing("A shining soap","You are blinded by dazzling light.");
    toilet->getThings(Soap);
    Thing* Morrior= new Thing("A broken Morrior","Old fashioned");
    AncientTime->getThings(Morrior);
    Thing* Sword= new Thing("Excaliburn","Send you back to bedroom");
    AncientTime->getThings(Sword);
    
    Monster * Sadako =new Monster("Sadako","is hanging around for alive person.");
    Sadako->moveTo(AncientTime);
    
    vector<Agent*> agents;
    agents.push_back(Sadako);
    agents.push_back(Ccookie);
    
    
    bool gameOn = true;
    while (gameOn) {
        for (auto p:agents){
            gameOn = p->act(p);
            if (!gameOn) {
                cout<<"\nGAME OVER!"<<endl;
                return 0;
            }
        }
    }
    //cout<<"Game over."<<endl;
    
    return 0;
}