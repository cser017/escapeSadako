//
//  room.h
//  escapeSadako
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//


#ifndef __escapeSadako__room__
#define __escapeSadako__room__

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include "thing.h"
using namespace std;


class Thing;

class Room{
    string name;
    string description;
    set<Thing*> things;
    unordered_map<string, Room*> map4room;
    
public:
    Room(string _name, string _description)
    :name(_name), description(_description){}
    
    string getName();
    
    string getDescription();
    
    void link(string direction, Room* r);
    
    Room *goToRoom(string direction);
    
    void printLinked();
    
};


#endif /* defined(__escapeSadako__room__) */
