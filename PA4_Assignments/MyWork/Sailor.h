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
class Model;
class Merchant;
class Pirate;

class Sailor: public GameObject
{
protected:
    double hold;
    double cargo;
    double size;
    double presize;
    double health;
    Port* port;
    Dock* dock;
    Dock* hideout;
    Model* s_model;
    bool update_location();
    void setup_destination(CartPoint);
    CartPoint destination;
    CartVector delta;
    
public:
    Sailor(char,Model*);
    Sailor(char, int, Dock*, Model*);
    Sailor(char, int, Model*);
    virtual ~Sailor();
    
    //public member functions
    double get_size();
    double get_presize();
    double get_cargo();
    void start_sailing(CartPoint);
    void start_supplying(Port*);
    void start_hiding();
    bool is_hidden();
    bool is_alive();
    void start_docking(Dock*);
    void anchor();
    void show_status();
    
    virtual void start_plunder(Sailor*);
    virtual bool start_recruiting(Merchant*);
    void get_plundered(int);
    virtual double get_speed() = 0;
    virtual bool update();
    virtual void save(ofstream& file);
    virtual void restore(ifstream& file, Model& model);
};




#endif /* defined(__PA3__Sailor__) */
