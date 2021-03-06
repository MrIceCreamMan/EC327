//
//  Model.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "Model.h"
#include "GameObject.h"
#include "Dock.h"
#include "Port.h"
#include "Sailor.h"
#include "View.h"
#include <iostream>

using namespace std;

//default constructor. create 3 docks, 3 sailors and 4 ports on the heap.
//10 GameObects all together.
Model::Model()
{
    time = 0;
    num_objects = 10;
    num_sailors = 3;
    num_ports = 4;
    num_docks = 3;

    Dock* dock1 = new Dock(1,CartPoint(5,1));
    Dock* dock2 = new Dock(2,CartPoint(6,2));
    Dock* dock3 = new Dock(3,CartPoint(1,8));
    Port* port1 = new Port(1,CartPoint(1,20));
    Port* port2 = new Port(2,CartPoint(20,1));
    Port* port3 = new Port(3,CartPoint(20,20));
    Port* port4 = new Port(4,CartPoint(7,2));
    Sailor* sailor1 = new Sailor(1,dock1);
    Sailor* sailor2 = new Sailor(2,dock2);
    Sailor* sailor3 = new Sailor(3,dock3);


    object_ptrs = new GameObject*[num_objects];
    dock_ptrs = new Dock*[num_docks];
    sailor_ptrs = new Sailor*[num_sailors];
    port_ptrs = new Port*[num_ports];
    
    object_ptrs[0] = dock1;
    object_ptrs[1] = dock2;
    object_ptrs[2] = dock3;
    object_ptrs[3] = sailor1;
    object_ptrs[4] = sailor2;
    object_ptrs[5] = sailor3;
    object_ptrs[6] = port1;
    object_ptrs[7] = port2;
    object_ptrs[8] = port3;
    object_ptrs[9] = port4;

    dock_ptrs[0] = dock1;
    dock_ptrs[1] = dock2;
    dock_ptrs[2] = dock3;
    sailor_ptrs[0]= sailor1;
    sailor_ptrs[1]= sailor2;
    sailor_ptrs[2]= sailor3;
    port_ptrs[0] = port1;
    port_ptrs[1] = port2;
    port_ptrs[2] = port3;
    port_ptrs[3] = port4;

    cout << "Model default constructed" << endl;
}

//desturctor, also free the heap to prevent memory leak
Model::~Model()
{
    for (int i = 0; i < num_objects; i++)
    {
        delete object_ptrs[i];
    }
    cout << "Model destructed" << endl;
}

//get the pointer of a sailor according to the input ID number
Sailor* Model::get_Sailor_ptr(int id_num)
{
    for (int i = 0; i < num_sailors; i++)
    {
        if (sailor_ptrs[i]->get_id() == id_num)
        {
            return sailor_ptrs[i];
        }
    }
    return  NULL;
}

//get the pointer of a port according to the input ID number
Port* Model::get_Port_ptr(int id_num)
{
    for (int i = 0; i < num_ports; i++)
    {
        if (port_ptrs[i]->get_id() == id_num)
        {
            return port_ptrs[i];
        }
    }
    return  NULL;
}

//get the pointer of a dock according to the input ID number
Dock* Model::get_Dock_ptr(int id_num)
{
    for (int i = 0; i < num_docks; i++)
    {
        if (dock_ptrs[i]->get_id() == id_num)
        {
            return dock_ptrs[i];
        }
    }
    return  NULL;
}

//advance the time by one tick, and updtate each GameObjects.
//return true if anyone GameObject changes state.
bool Model::update()
{
    time++;
    bool TF = false;
    for (int i = 0; i < num_objects; i++)
    {
        if (object_ptrs[i]->update())
        {
            TF = true;
        }
    }
    return TF;
}

//a function to display time, and also plot grid and draw it out to give a visual output
//also clear the grid after each draw to prepare a new drawing.
void Model::display(View *view)
{
    cout << "Time: " << time << endl;
    for (int i = 0; i < num_objects; i++)
    {
        view->plot(object_ptrs[i]);
    }
    view->draw();
    view->clear();
}

//show the status of each GameObjects
void Model::show_status()
{
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->show_status();
    }
}



















