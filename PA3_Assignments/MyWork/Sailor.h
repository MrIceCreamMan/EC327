//
//  Sailor.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__Sailor__
#define __PA3__Sailor__

#include <iostream>
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Port.h"
#include "Dock.h"

class Sailor: public GameObject
{
private:
    double health;
    double size;
    double presize;
    double hold;
    double cargo;
    CartPoint destination;
    CartVector delta;
    Port* port;
    Dock* dock;
    Dock* hideout;
    
    //private member functions
    bool update_location();
    void setup_destination(CartPoint dest);
public:
    Sailor();
    Sailor(int in_id, Dock* hideout);
    ~Sailor();
    
    //public member functions
    bool update();
    double get_size();
    double get_presize();
    double get_cargo();
    void start_sailing(CartPoint dest);
    void start_supplying(Port* destPort);
    void start_hiding();
    bool is_hidden();
    void start_docking(Dock* destDock);
    void anchor();
    void show_status();
    double get_speed();
};




#endif /* defined(__PA3__Sailor__) */
