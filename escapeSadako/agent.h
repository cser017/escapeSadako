//
//  agent.h
//  homework 7
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//

#ifndef __homework_7__agent__
#define __homework_7__agent__

#include <iostream>
#include <string>
using namespace std;

#include "thing.h"

class Agent: public Thing{
protected:
    Agent(string _name, string _description):Thing(_name, _description){};
public:
    virtual bool act(Agent * a)=0;
};

class Player: public Agent{
public:
    Player(string _name, string _description): Agent(_name, _description){};
    bool act(Agent * a);
};


class Monster: public Agent
{
public:
    Monster(string n,string d):Agent(n,d){};
    bool act(Agent * m);
};

#endif /* defined(__homework_7__agent__) */
