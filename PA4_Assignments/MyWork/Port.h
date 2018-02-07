//
//  Port.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__Port__
#define __PA3__Port__

#include <iostream>
#include "CartPoint.h"
#include "GameObject.h"
using namespace std;

class Port: public GameObject
{
private:
    double inventory;
    
public:
    Port();
    Port(int in_id, CartPoint in_loc);
    ~Port();
    
    //public member functions
    bool is_empty();
    double provide_supplies(double amount_to_provide = 50);
    bool update();
    void show_status();
    void save(ofstream& file);
    void restore(ifstream& file, Model& model);
};


#endif /* defined(__PA3__Port__) */
