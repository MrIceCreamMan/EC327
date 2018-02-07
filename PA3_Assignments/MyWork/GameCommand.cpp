//
//  GameCommand.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "GameCommand.h"
#include "Model.h"
#include "Sailor.h"
#include <iostream>
using namespace std;

//check if the sailor exists, if so, call  the start_sailing function in sailor
void do_sail_command(Model* model)
{
    int ID;
    double x,y;
    cin >> ID >> x >> y;
    Sailor* s_sailor;
    s_sailor = model->get_Sailor_ptr(ID);
    if (s_sailor == NULL)
    {
        cout << "Sailor does not exist" << endl;
    }
    else
    {
        s_sailor->start_sailing(CartPoint(x,y));
    }
    return;
}

//check if the sailor and the port exist, if so, call the start_supplying function in sailor
void do_port_command(Model* model)
{
    int ID1,ID2;
    cin >> ID1 >> ID2;
    Sailor* p_sailor;
    p_sailor = model->get_Sailor_ptr(ID1);
    if (p_sailor == NULL)
    {
        cout << "Sailor does not exist" << endl;
        return;
    }
    Port* p_port;
    p_port = model->get_Port_ptr(ID2);
    if (p_port == NULL)
    {
        cout << "Port does not exist" << endl;
        return;
    }
    else
    {
        p_sailor->start_supplying(p_port);
    }
    return;
}

//check if the sailor exists, if so, call the anchor function in sailor
void do_anchor_command(Model* model)
{
    int ID;
    cin >> ID;
    Sailor* a_sailor;
    a_sailor = model->get_Sailor_ptr(ID);
    if (a_sailor == NULL)
    {
        cout << "Sailor does not exist" << endl;
    }
    else
    {
        a_sailor->anchor();
    }
    return;
}

//check if the sailor and the dock exist, if so, call the start_docking function in sailor
void do_dock_command(Model* model)
{
    int ID1,ID2;
    cin >> ID1 >> ID2;
    Sailor* d_sailor;
    d_sailor = model->get_Sailor_ptr(ID1);
    if (d_sailor == NULL)
    {
        cout << "Sailor does not exist" << endl;
        return;
    }
    Dock* d_dock;
    d_dock = model->get_Dock_ptr(ID2);
    if (d_dock == NULL)
    {
        cout << "Dock does not exist" << endl;
        return;
    }
    else
    {
        d_sailor->start_docking(d_dock);
    }
    return;
}

//check if the sailor exists, if so, call the start_hiding function in sailor
void do_hide_command(Model* model)
{
    int ID;
    cin >> ID;
    Sailor* h_sailor;
    h_sailor = model->get_Sailor_ptr(ID);
    if (h_sailor == NULL)
    {
        cout << "Sailor does not exist" << endl;
    }
    else
    {
        h_sailor->start_hiding();
    }
    return;
}

//Advance time by one tick, update the model once
void do_go_command(Model* model)
{
    cout << "Advancing time one tick" << endl;
    model->update();
    return;
}

//Advance time either five ticks or untill model update function returns true.
void do_run_command(Model* model)
{
    cout << "Advancing to next event or 5 ticks" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (model->update())
            return;
    }
    return;
}

//show the status of all the GameObjects in the model pointer
void do_list_command(Model* model)
{
    model->show_status();
    return;
}

















