//
//  agent.cpp
//  homework 7
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//

#include "agent.h"
#include <iostream>
#include <string>
using namespace std;

bool Player::act(Agent * a){
    
    curr_room->printLinked();
    
    cout<<"Where to go:"<<endl;
    string dir;
    cin>>dir;
    
    curr_room = curr_room->goToRoom(dir);
    curr_room->enter(a);
    if (dir=="quit")
    {
        return false;
    }
    if (curr_room->getName()=="space_ship") {
        cout<<"***********************"<<"Congratulation!!\nYou are sent back home safely!"<<endl;
        return false;
    }
    if (curr_room->meet()==true)
    {
        cout<<"A long hair dead women in white cloth is crawling towards you and you find yourself freezed. Then you are scared to death. "<<endl;
        return false;
    }
    curr_room->leave(a);
    return true;
}

bool Monster::act(Agent * m)
{
    curr_room->enter(m);
    curr_room->printMonster();
    curr_room->leave(m);
    
    int n=rand() % 8;
    string direction;
    switch (n) {
        case 0: direction= "north"; break;
        case 1: direction= "south"; break;
        case 2: direction= "west"; break;
        case 3: direction= "east"; break;
        case 4: direction= "up"; break;
        case 5: direction= "down"; break;
        case 6: direction= "north"; break;
        case 7: direction= "up"; break;
    }
    
    if (curr_room->goToRoom(direction)!=NULL)
    {
        
        curr_room=curr_room->goToRoom(direction);
        curr_room->enter(m);
        
    }
    return true;
}