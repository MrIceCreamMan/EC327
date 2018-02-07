//
//  Merchant.h
//  PA4
//
//  Created by MazeRunner on 15-11-24.
//  Copyright (c) 2015年 Reno Jackson. All rights reserved.
//

#ifndef __PA4__Merchant__
#define __PA4__Merchant__

#include "Sailor.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Port.h"
#include "Dock.h"
class Model;
class Pirate;

class Merchant: public Sailor
{
public:
    ~Merchant();
    int recruit_time;
    Merchant(Model*);
    Merchant(int, Dock*, Model*);
    double get_speed();
    bool start_recruiting(Merchant*);
    bool update();
    void show_status();
    void start_plunder(Sailor*);
    void save(ofstream& file);
    void restore(ifstream& file, Model& model);
};

#endif /* defined(__PA4__Merchant__) */
