//
//  Pirate.h
//  PA4
//
//  Created by MazeRunner on 15-12-1.
//  Copyright (c) 2015 Reno Jackson. All rights reserved.
//

#ifndef __PA4__Pirate__
#define __PA4__Pirate__

#include <iostream>
#include "Sailor.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Port.h"
#include "Dock.h"
class Merchant;
class Model;

class Pirate: public Sailor
{
private:
    int attack_strength;
    double range;
    Sailor* target;
public:
   static int c; //          hhhhhheeeeeeerrrrrreeeeeee
    Pirate(Model*);
    Pirate(int,Model*);
    ~Pirate();
    double get_speed();
    void start_plunder(Sailor* target);
    bool update();
    void show_status();
    bool start_recruiting(Sailor*);
    Sailor* get_target();
    void save(ofstream& file);
    void restore(ifstream& file, Model& model);
};


#endif /* defined(__PA4__Pirate__) */
