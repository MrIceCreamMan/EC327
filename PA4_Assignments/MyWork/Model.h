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
#include <list>
#include "InputHandling.h"
class GameObject;
class Sailor;
class Merchant;
class Port;
class Dock;
class View;
class Kraken;
using namespace std;

class Model
{
private:
    int time;
    int count_time;
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    list<Sailor*> sailor_ptrs;
    list<Dock*> dock_ptrs;
    list<Port*> port_ptrs;
    
    //make the copy constructor private to prevent Model from being copied
    Model(const Model&);
public:
    Model();
    Model(int time, int inctime);
    Model(Model* exsit, GameObject* GO);
    virtual ~Model();
    list<GameObject*>::iterator object_it;
    list<GameObject*>::iterator active_it;
    list<Sailor*>::iterator sailor_it;
    list<Dock*>::iterator dock_it;
    list<Port*>::iterator port_it;
    Kraken* krak;
    Sailor* get_Sailor_ptr(int id_num);
    Port* get_Port_ptr(int id_num);
    Dock* get_Dock_ptr(int id_num);
    Merchant* get_sailor_mate(Merchant*);
    int get_sailor_in_dock(Sailor*);
    int get_new_ID(GameObject*);
    int get_time();
    bool update();
    void display(View* view);
    void show_status();
    void add_new_object(GameObject*);
    bool check_id(char, int);
    bool AtDock(Sailor*);
    bool isActive(Sailor*);
    void save(ofstream& file);
    void restore(ifstream& file);
    
    void showall();
};


#endif /* defined(__PA3__Model__) */
