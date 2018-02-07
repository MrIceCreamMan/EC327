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
#include "Merchant.h"
#include "Pirate.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include "Kraken.h"
#include <fstream>

using namespace std;

//default constructor. create 3 docks, 3 sailors and 4 ports on the heap.
//10 GameObects all together.
Model::Model()
{
    time = 0;
    count_time = 0;
    srand(time);
    Dock* dock1 = new Dock(1,CartPoint(5,1));
    Dock* dock2 = new Dock(2,CartPoint(6,2));
    Dock* dock3 = new Dock(3,CartPoint(1,8));
    Port* port1 = new Port(1,CartPoint(1,20));
    Port* port2 = new Port(2,CartPoint(20,1));
    Port* port3 = new Port(3,CartPoint(20,20));
    Port* port4 = new Port(4,CartPoint(7,2));
    Merchant* merchant1 = new Merchant(1,dock1,this);
    Merchant* merchant2 = new Merchant(2,dock1,this);
    Merchant* merchant3 = new Merchant(3,dock2,this);
    Pirate* pirate4 = new Pirate(4,this);
    Pirate* pirate5 = new Pirate(5,this);
    krak = Kraken::Instance();
    
    object_ptrs.push_back(merchant1);
    object_ptrs.push_back(merchant2);
    object_ptrs.push_back(merchant3);
    object_ptrs.push_back(pirate4);
    object_ptrs.push_back(pirate5);
    object_ptrs.push_back(dock1);
    object_ptrs.push_back(dock2);
    object_ptrs.push_back(dock3);
    object_ptrs.push_back(port1);
    object_ptrs.push_back(port2);
    object_ptrs.push_back(port3);
    object_ptrs.push_back(port4);
    
    
    //4444444444444444444444444444444444444444
    active_ptrs.push_back(dock1);
    active_ptrs.push_back(dock2);
    active_ptrs.push_back(dock3);
    active_ptrs.push_back(port1);
    active_ptrs.push_back(port2);
    active_ptrs.push_back(port3);
    active_ptrs.push_back(port4);
    active_ptrs.push_back(merchant1);
    active_ptrs.push_back(merchant2);
    active_ptrs.push_back(merchant3);
    active_ptrs.push_back(pirate4);
    active_ptrs.push_back(pirate5);
    //________________________________________*/
    
    dock_ptrs.push_back(dock1);
    dock_ptrs.push_back(dock2);
    dock_ptrs.push_back(dock3);
    sailor_ptrs.push_back(merchant1);
    sailor_ptrs.push_back(merchant2);
    sailor_ptrs.push_back(merchant3);
    sailor_ptrs.push_back(pirate4);
    sailor_ptrs.push_back(pirate5);
    port_ptrs.push_back(port1);
    port_ptrs.push_back(port2);
    port_ptrs.push_back(port3);
    port_ptrs.push_back(port4);

    cout << "Model default constructed" << endl;
}

Model::Model(int intime, int inctime)
{
    time = intime;
    count_time = inctime;
    srand(time);
    krak = Kraken::Instance();
}

Model::Model(Model* world, GameObject* go)
{
    Dock* dock = dynamic_cast<Dock*>(go);
    Port* port = dynamic_cast<Port*>(go);
    Merchant* mer = dynamic_cast<Merchant*>(go);
    Pirate* pir = dynamic_cast<Pirate*>(go);
    if ((dock != NULL)&(port == NULL)&(mer == NULL)&(pir == NULL))
    {
        
    }
    else if ((dock == NULL)&(port != NULL)&(mer == NULL)&(pir == NULL))
    {
        
    }
    else if ((dock == NULL)&(port == NULL)&(mer != NULL)&(pir == NULL))
    {
        
    }
    else if ((dock == NULL)&(port == NULL)&(mer == NULL)&(pir != NULL))
    {
        
    }
    else
    {
        cout << "else in model restore, problem" << endl;
    }
}

//desturctor, also free the heap to prevent memory leak
Model::~Model()
{
    krak->history();
    for (object_it = object_ptrs.begin(); object_it != object_ptrs.end(); object_it++)
    {
        delete *object_it;
    }
    cout << "Model destructed" << endl;
    krak->resetInstance();
}

//get the pointer of a sailor according to the input ID number
Sailor* Model::get_Sailor_ptr(int id_num)
{
    for (sailor_it = sailor_ptrs.begin(); sailor_it != sailor_ptrs.end(); sailor_it++)
    {
        if ((*sailor_it)->get_id() == id_num)
        {
            return (*sailor_it);
        }
    }
    return  NULL;
}

//get the pointer of a port according to the input ID number
Port* Model::get_Port_ptr(int id_num)
{
    for (port_it = port_ptrs.begin(); port_it != port_ptrs.end(); port_it++)
    {
        if ((*port_it)->get_id() == id_num)
        {
            return (*port_it);
        }
    }
    return  NULL;
}

//get the pointer of a dock according to the input ID number
Dock* Model::get_Dock_ptr(int id_num)
{
    for (dock_it = dock_ptrs.begin(); dock_it != dock_ptrs.end(); dock_it++)
    {
        if ((*dock_it)->get_id() == id_num)
        {
            return (*dock_it);
        }
    }
    return  NULL;
}

//advance the time by one tick, and updtate each GameObjects.
//return true if anyone GameObject changes state.
bool Model::update()
{
    bool TF = false;
    time++;
    count_time++;
    srand(time);
    if (count_time == 15)
    {
        TF = true;
        count_time = 0;
        for (active_it = active_ptrs.begin(); active_it != active_ptrs.end(); active_it++)
        {
         //   cout << (*active_it)->get_dispCode() << (*active_it)->get_id() << endl;
            Sailor* sailor = NULL;
            sailor = dynamic_cast<Sailor*>(*active_it);
            if (sailor == NULL)
            {
            }
            else
            {
                bool atDock = false;
                for (dock_it = dock_ptrs.begin(); dock_it != dock_ptrs.end(); dock_it++)
                {
                    if (cart_compare(sailor->get_location(),(*dock_it)->get_location()))
                        atDock = true;
                }
                if (!atDock)
                {
                    krak->Ksailor_ptrs.push_back(sailor);
                    for (sailor_it=sailor_ptrs.begin();sailor_it!=sailor_ptrs.end();sailor_it++)
                    {
                        if (sailor->get_id() == (*sailor_it)->get_id())
                        {
                            sailor_ptrs.erase(sailor_it);
                            sailor_it--;
                        }
                    }
                    active_ptrs.erase(active_it);
                    active_it--;
                }
            }
        }
        krak->claim();
    }
    for (active_it = active_ptrs.begin(); active_it != active_ptrs.end(); active_it++)
    {
 //       cout << (*active_it)->get_dispCode() << (*active_it)->get_id() << (*active_it)->get_state() << endl;
        if ((*active_it)->update())
        {
            TF = true;
        }
    }
    if (count_time == 10)
    {
        krak->warning();
        TF = true;
    }
    return TF;
}

//a function to display time, and also plot grid and draw it out to give a visual output
//also clear the grid after each draw to prepare a new drawing.
void Model::display(View *view)
{
    cout << "Time: " << time << endl;
    for (active_it = active_ptrs.begin(); active_it != active_ptrs.end(); active_it++)
    {
        view->plot(*active_it);
    }
    view->draw();
    view->clear();
}

//show the status of each GameObjects
void Model::show_status()
{
    for (active_it = active_ptrs.begin(); active_it != active_ptrs.end(); active_it++)
    {
        (*active_it)->show_status();
    }
}

int Model::get_time()
{
    return time;
}

int Model::get_sailor_in_dock(Sailor * sailor)
{
    int count = 0;
    for (sailor_it = sailor_ptrs.begin(); sailor_it != sailor_ptrs.end(); sailor_it++)
    {
        if (cart_compare(sailor->get_location(), (*sailor_it)->get_location()))
            {
                count = count + 1;
            }
    }
    return count;
}

Merchant* Model::get_sailor_mate(Merchant* merchant)
{
 //   cout << "size" << sailor_ptrs.size() << endl;
    for (sailor_it = sailor_ptrs.begin(); sailor_it != sailor_ptrs.end(); sailor_it++)
    {
   //     cout << "id " << (*sailor_it)->get_dispCode() << (*sailor_it)->get_id() << endl;
        bool con1 = cart_compare(merchant->get_location(), (*sailor_it)->get_location());
        bool con2 = (merchant->get_id()!=(*sailor_it)->get_id());
        bool con3 = ((*sailor_it)->get_state()=='a'|(*sailor_it)->get_state()=='r');
        if (con1&con2&con3)
        {
//            sailor_it++;
//            cout << "id " << (*sailor_it)->get_dispCode() << (*sailor_it)->get_id() << endl;
//            sailor_it--;
            return dynamic_cast<Merchant*>(*sailor_it);
        }
        
    }
    return NULL;
}

int Model::get_new_ID(GameObject* GO_ptr)
{
    int new_id = 0;
    bool exist = true;
    switch (GO_ptr->get_dispCode())
    {
        case 'P':
            while(exist)
            {
                new_id++;
                exist = false;
                for (port_it = port_ptrs.begin(); port_it != port_ptrs.end(); port_it++)
                {
                    if (new_id == (*port_it)->get_id())
                    {
                        exist = true;
                    }
                }
            }
            return new_id;
            break;
            
        case 'D':
            while (exist)
            {
                new_id++;
                exist = false;
                for (dock_it = dock_ptrs.begin(); dock_it != dock_ptrs.end(); dock_it++)
                {
                    if (new_id == (*dock_it)->get_id())
                    {
                        exist = true;
                    }
                }
            }
            return new_id;
            break;
            
        case 'M':
            while (exist)
            {
                new_id++;
                exist = false;
                for (sailor_it = sailor_ptrs.begin(); sailor_it != sailor_ptrs.end(); sailor_it++)
                {
    //                if (isActive(*sailor_it))
                    if (true)
                    {
                        if (new_id == (*sailor_it)->get_id())
                        {
                            exist = true;
                        }
                    }
                }
            }
            return new_id;
            break;
            
        case 'R':
            while (exist)
            {
                new_id++;
                exist = false;
                for (sailor_it = sailor_ptrs.begin(); sailor_it != sailor_ptrs.end(); sailor_it++)
                {
                    if (new_id == (*sailor_it)->get_id())
                    {
                        exist = true;
                    }
                }
            }
            return new_id;
            break;
            
        default:
            cout << "get_new_ID wrong in Model.cpp" << endl;
            return 0;
            break;
    }
}

bool Model::check_id(char inCode, int ID)
{
    int exist_id;
    int TF = 0;
    switch (inCode)
    {
        case 'P':
            for (port_it = port_ptrs.begin(); port_it != port_ptrs.end(); port_it++)
            {
                exist_id = (*port_it)->get_id();
                if (exist_id == ID)
                {
                    TF = TF + 1;
                }
            }
            break;
            
        case 'D':
            for (dock_it = dock_ptrs.begin(); dock_it != dock_ptrs.end(); dock_it++)
            {
                exist_id = (*dock_it)->get_id();
                if (exist_id == ID)
                {
                    TF = TF + 1;
                }
            }
            break;
            
        case 'M':
            for (sailor_it = sailor_ptrs.begin(); sailor_it != sailor_ptrs.end(); sailor_it++)
            {
                exist_id = (*sailor_it)->get_id();
                if (exist_id == ID)
                {
                    TF = TF + 1;
                }
            }
            break;
            
        case 'R':
            for (sailor_it = sailor_ptrs.begin(); sailor_it != sailor_ptrs.end(); sailor_it++)
            {
                exist_id = (*sailor_it)->get_id();
                if (exist_id == ID)
                {
                    TF = TF + 1;
                }
            }
            break;
            
        default:
            cout << "check_ID wrong in Model.cpp" << endl;
            return true;
            break;
    }
    if (TF > 0)
        return true;
    else
        return false;
}

void Model::add_new_object(GameObject* G_O_ptr)
{
    object_ptrs.push_back(G_O_ptr);
    active_ptrs.push_back(G_O_ptr);
    switch (G_O_ptr->get_dispCode())
    {
        case 'P':
            if (dynamic_cast<Port*>(G_O_ptr) != NULL)
            {
                port_ptrs.push_back(dynamic_cast<Port*>(G_O_ptr));
            }
            else
            {
                cout << "cannot dynamically cast GameObject* to Port*" << endl;
            }
            break;
        
        case 'D':
            if (dynamic_cast<Dock*>(G_O_ptr) != NULL)
            {
                dock_ptrs.push_back(dynamic_cast<Dock*>(G_O_ptr));
            }
            else
            {
                cout << "cannot dynamically cast GameObject* to Dock*" << endl;
            }
            break;
            
        case 'M':
            if (dynamic_cast<Sailor*>(G_O_ptr) != NULL)
            {
                sailor_ptrs.push_back(dynamic_cast<Sailor*>(G_O_ptr));
            }
            else
            {
                cout << "cannot dynamically cast GameObject* to Sailor*(M)" << endl;
            }
            break;
            
        case 'R':
            if (dynamic_cast<Sailor*>(G_O_ptr) != NULL)
            {
                sailor_ptrs.push_back(dynamic_cast<Sailor*>(G_O_ptr));
            }
            else
            {
                cout << "cannot dynamically cast GameObject* to Sailor*(P)" << endl;
            }
            break;
            
        default:
            cout << "Wrong in add_new_object() in Model.cpp" << endl;
            break;
    }
}

bool Model::AtDock(Sailor* sailor)
{
    bool TF = false;
    for (dock_it = dock_ptrs.begin(); dock_it != dock_ptrs.end(); dock_it++)
    {
        if (cart_compare(sailor->get_location(), (*dock_it)->get_location()))
        {
            TF = true;
        }
    }
    return TF;
}

void Model::showall()
{
    cout << "active: " << endl;
    for (active_it=active_ptrs.begin();active_it!=active_ptrs.end();active_it++)
        cout << (*active_it)->get_dispCode() << (*active_it)->get_id() << endl;
    cout << "sailor: " << endl;
    for (sailor_it=sailor_ptrs.begin();sailor_it!=sailor_ptrs.end();sailor_it++)
        cout << (*sailor_it)->get_dispCode() << (*sailor_it)->get_id() << endl;
}

bool Model::isActive(Sailor* sailor)
{
    bool act = false;
    Sailor* cmpsailor = NULL;
    for (active_it=active_ptrs.begin();active_it!=active_ptrs.end();active_it++)
    {
        cmpsailor = dynamic_cast<Sailor*>(*active_it);
        if (cmpsailor!=NULL)
        {
            if (cmpsailor->get_id()==sailor->get_id())
                act = true;
        }
    }
    return act;
}

void Model::save(ofstream& file)
{
    file << time << " " << count_time << " " << active_ptrs.size() << endl;
    for (active_it = active_ptrs.begin(); active_it != active_ptrs.end(); active_it++)
    {
        (*active_it)->save(file);
    }
    krak->save(file);
}

void Model::restore(ifstream& file)
{
    int number;
    char code;
    file >> time;
    file >> count_time;
    file >> number;
    for (int i = 0; i < number; i++)
    {
        file >> code;
        switch (code)
        {
            case 'D':
                break;
                
            case 'd':
                break;
                
            case 'P':
                break;
                
            case 'R':
                break;
                
            case 'M':
                break;
                
            default:
                cout << "default in model restore" << endl;
                break;
        }
    }
}



















