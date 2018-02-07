//
//  Model.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__Model__
#define __PA3__Model__

#include <iostream>
class GameObject;
class Sailor;
class Port;
class Dock;
class View;

class Model
{
private:
    int time;
    GameObject** object_ptrs;
    int num_objects;
    Sailor** sailor_ptrs;
    int num_sailors;
    Dock** dock_ptrs;
    int num_docks;
    Port** port_ptrs;
    int num_ports;
    
    //make the copy constructor private to prevent Model from being copied
    Model(const Model&);
public:
    Model();
    virtual ~Model();
    
    //public member functions
    Sailor* get_Sailor_ptr(int id_num);
    Port* get_Port_ptr(int id_num);
    Dock* get_Dock_ptr(int id_num);
    bool update();
    void display(View* view);
    void show_status();
};


#endif /* defined(__PA3__Model__) */
