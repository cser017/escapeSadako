//
//  agent.cpp
//  escapeSadako
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.
//

#include "agent.h"
#include <iostream>
#include <string>
using namespace std;

bool Player::act(){
    curr_room->printLinked();
    cout<<"Where to go:"<<endl;
    string dir;
    cin>>dir;
    curr_room = curr_room->goToRoom(dir);
    if (dir=="quit" || curr_room->getName()=="SECRET ROOM") {
        return false;
    }
    
    return true;
}
