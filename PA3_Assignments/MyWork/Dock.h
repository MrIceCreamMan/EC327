//
//  Dock.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__Dock__
#define __PA3__Dock__

#include <iostream>
#include "GameObject.h"
#include "CartPoint.h"
class Sailor;

using namespace std;

class Dock: public GameObject
{
private:
    double berths;
    
public:
    Dock();
    Dock(int in_id, CartPoint in_loc);
    ~Dock();
    
    //public member functions
    bool dock_boat(Sailor* sailor_to_dock);
    bool set_sail(Sailor* sailor_to_sail);
    bool update();
    void show_status();
};


#endif /* defined(__PA3__Dock__) */
