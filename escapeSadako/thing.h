//
//  thing.h
//  escapeSadako
//
//  Created by Chen Cai on 7/28/15.
//  Copyright (c) 2015 Chen Cai. All rights reserved.


#ifndef __escapeSadako__thing__
#define __escapeSadako__thing__

#include <string>
#include "room.h"
using namespace std;

class Room;

class Thing{
private:
    string name;
    string description;
    
protected:
    Room * curr_room;
    
public:
    Thing(string n="NAME",string d="DESC"): name(n),description(d){curr_room=NULL;}
    string getName(){return  name;}
    string getDescription (){return description;}
    void moveTo(Room* R){curr_room=R;}
    
};


#endif /* defined(__escapeSadako__thing__) */
