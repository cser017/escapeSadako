//
//  room.h
//  homework 7
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//

#ifndef __homework_7__room__
#define __homework_7__room__

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include "thing.h"
#include "agent.h"

using namespace std;


class Thing;
class Agent;

class Room{
private:
    string name;
    string description;
    set<Thing*> things;
    unordered_map<string, Room*> map4room;
    set<Agent*> agents;
    
public:
    Room(string _name, string _description):name(_name), description(_description){}
    
    string getName();
    
    string getDescription();
    
    void link(string direction, Room* r);
    
    Room *goToRoom(string direction);
    
    void getThings(Thing* T);
    
    void printLinked();
    
    void printMonster();
    
    void enter(Agent *a);
    void leave(Agent *a);
    bool meet();
};

#endif /* defined(__HW5__room__) */




