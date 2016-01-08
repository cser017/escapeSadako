//
//  agent.h
//  homework 7
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//


#ifndef __escapeSadako__agent__
#define __escapeSadako__agent__

#include <iostream>
#include <string>
using namespace std;

#include "thing.h"

class Agent: public Thing{
protected:
    Agent(string _name="agent genetic name", string _description="agent genetic description ", int _size=0):Thing(_name, _description){};
    
public:
    virtual bool act()=0;
};

class Player: public Agent{
public:
    Player(string _name, string _description): Agent(_name, _description){};
    bool act();
};


#endif /* defined(__escapeSadako__agent__) */
