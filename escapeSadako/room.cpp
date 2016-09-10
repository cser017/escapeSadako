//
//  room.cpp
//  homework 7
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//

#include "room.h"
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;


string Room::getName(){
    return name;
}

string Room::getDescription(){
    return description;
}

void Room::link(string direction, Room* r){
    map4room.insert(make_pair(direction, r));
}

Room* Room::goToRoom(string direction){
    auto it=map4room.find(direction);
    if (it==map4room.end()) {
        return this;
    }
    else return it->second;
}

void Room::printLinked(){
    cout<<"Now you are in "<<getName()<<".\n"<<endl;
    if (!things.empty()) {
        cout<<"\nThis room has following stuff:\n"<<"***************************************************"<<endl;
        for (auto th:things){
            cout<<th->getName()<<"--"<<th->getDescription()<<endl;
        }
        cout<<"******************************************************"<<endl;
    }
    cout<<"\nDerictions you can go: \n";
    for (auto r:map4room){
        cout<<r.first<<endl;
    }
}
void Room::printMonster(){
    cout<<"\n\nSadako now is in "<<getName()<<".\n"<<endl;
}

void Room::enter(Agent *a)
{
    agents.insert(a);
}
void Room::leave(Agent *a)
{
    agents.erase(a);
}
bool Room::meet()
{
    if (agents.size()==2) {
        return true;
    }
    else return false;
}
void Room::getThings(Thing* T){
    things.insert(T);
}

