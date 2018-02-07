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
#include "Merchant.h"
#include "Pirate.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//check if the sailor exists, if so, call  the start_sailing function in sailor
void do_sail_command(Model* model)
{
    int ID;
    double x,y;
    try
    {
       
        if(!(cin >> ID))
            throw InvalidInput("Expected Integer");
        if(!(cin >> x))
            throw InvalidInput("Expected Double");
        if (!(cin >> y))
            throw InvalidInput(("Expected Double"));
        Sailor* s_sailor;
        s_sailor = model->get_Sailor_ptr(ID);
        if (s_sailor == NULL)
        {
            throw InvalidInput("Invalid Sailor ID");
        }
        else
        {
            s_sailor->start_sailing(CartPoint(x,y));
        }
    }
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
    return;
}

//check if the sailor and the port exist, if so, call the start_supplying function in sailor
void do_port_command(Model* model)
{
    int ID1,ID2;
    
    try
    {
        if (!(cin >> ID1))
            throw InvalidInput("Expected Integer");
        if (!(cin >> ID2))
            throw InvalidInput("Expected Integer");
        Sailor* p_sailor;
        p_sailor = model->get_Sailor_ptr(ID1);
        if (p_sailor == NULL)
        {
            throw InvalidInput("Wrong ID");
        }
        Port* p_port;
        p_port = model->get_Port_ptr(ID2);
        if (p_port == NULL)
        {
            throw InvalidInput("Wrong ID");
        }
        else
        {
            p_sailor->start_supplying(p_port);
        }
    }
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
    return;
}

//check if the sailor exists, if so, call the anchor function in sailor
void do_anchor_command(Model* model)
{
    int ID;
    try
    {
        if(!(cin >> ID))
        {
            throw InvalidInput("Was expecting an integer");
        }
        Sailor* a_sailor;
        a_sailor = model->get_Sailor_ptr(ID);
        if (a_sailor == NULL)
        {
            throw InvalidInput("Wrong ID");
        }
        else
        {
            a_sailor->anchor();
        }
    }
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
    return;
}

//check if the sailor and the dock exist, if so, call the start_docking function in sailor
void do_dock_command(Model* model)
{
    int ID1,ID2;
    try
    {
        if (!(cin >> ID1))
            throw InvalidInput("Was expecting an integer");
        if (!(cin >> ID2))
            throw InvalidInput("Was expecting an integer");
        Sailor* d_sailor;
        d_sailor = model->get_Sailor_ptr(ID1);
        if (d_sailor == NULL)
        {
            throw InvalidInput("Wrong ID");
        }
        Dock* d_dock;
        d_dock = model->get_Dock_ptr(ID2);
        if (d_dock == NULL)
        {
            throw InvalidInput("Wrong ID");
        }
        else
        {
            d_sailor->start_docking(d_dock);
        }
    }
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
    return;
}

//check if the sailor exists, if so, call the start_hiding function in sailor
void do_hide_command(Model* model)
{
    int ID;
    try
    {
        if (!(cin >> ID))
            throw InvalidInput("Was expecting an integer");
        Sailor* h_sailor;
        h_sailor = model->get_Sailor_ptr(ID);
        if (h_sailor == NULL)
        {
            throw ("Wrong ID");
        }
        else
        {
            h_sailor->start_hiding();
        }
    }
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
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

void do_plunder_command(Model* model)
{
    int ID1,ID2;
    try
    {
        if(!(cin >> ID1))
            throw InvalidInput("Was expecting an integer");
        if (!(cin>> ID2))
            throw InvalidInput("Was expecting an integer");
        Sailor* p_pirate;
        p_pirate = model->get_Sailor_ptr(ID1);
        if (p_pirate == NULL)
        {
            throw InvalidInput("Wrong ID");
        }
        Sailor* p_tartget;
        p_tartget = model->get_Sailor_ptr(ID2);
        if (p_tartget == NULL)
        {
            throw InvalidInput("Was expecting an integer");
        }
        else
        {
           p_pirate->start_plunder(p_tartget);
        }
    }
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
    return;
}

void handle_new_command(Model* model)
{
    char type;
    int id, idD;
    double x,y;
    
    try
    {
        if(!(cin >> type))
        {
            throw InvalidInput("Expected Char");
        }
        if (type == 'M')
        {
            if (!(cin >> id))
                throw InvalidInput("Was expecting an integer");
            if (!(cin >> idD))
                throw InvalidInput("Was expecting an integer");
//            if (!(cin >> x))
//                throw InvalidInput("Was expecting a double");
//            if (!(cin >> y))
//                throw InvalidInput("Was expecting a double");
            if (model->check_id('M', id))
                throw InvalidInput("Duplicate ID");
            if (!(model->check_id('D', idD)))
                throw InvalidInput("Invalid Dock ID");
            Dock* hideout = model->get_Dock_ptr(idD);
            Merchant* merchantn = new Merchant(id, hideout, model);
            model->add_new_object(merchantn);
        }
        else if (type == 'P')
        {
            if (!(cin >> id))
                throw InvalidInput("Was expecting an integer");
            if (!(cin>> x))
                throw InvalidInput("Was expecting a double");
            if (!(cin >> y))
                throw InvalidInput("Was expecting an integer");
            if (model->check_id('P', id))
                throw InvalidInput("Duplicate ID");
            Port* portn = new Port(id,CartPoint(x,y));
            model->add_new_object(portn);
        }
        else if (type == 'D')
        {
            if (!(cin >> id))
                throw InvalidInput("Was expecting an integer");
            if (!(cin>> x))
                throw InvalidInput("Was expecting a double");
            if (!(cin >> y))
                throw InvalidInput("Was expecting an integer");
            if (model->check_id('D', id))
                throw InvalidInput("Duplicate ID");
            Dock* dockn = new Dock(id,CartPoint(x,y));
            model->add_new_object(dockn);
        }
        
        else if (type == 'R')
        {
            if(!(cin >> id))
                throw InvalidInput("Was expecting an integer");
            if (model->check_id('R', id))
                throw InvalidInput("Duplicate ID");
            Pirate* piraten = new Pirate(id, model);
            model->add_new_object(piraten);
        }
        else
        {
            throw InvalidInput("Invalid Display Code");
        }
    }
    
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
    return;
}

void do_save_command(Model* model)
{
    string filename;
    cin >> filename;
    ofstream savefile;
    savefile.open(filename.c_str());
    model->save(savefile);
    savefile.close();
}

void do_restore_command(Model* model)
{
    try
    {
        string filename;
        cin >> filename;
        ifstream restorefile;
        restorefile.open(filename.c_str());
        if (restorefile.fail())
            throw InvalidInput("File does not exist");
        model->restore(restorefile);
        restorefile.close();
    }
    catch(InvalidInput& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
    }
}





