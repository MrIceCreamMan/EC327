//
//  GameObject.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__GameObject__
#define __PA3__GameObject__

#include <iostream>
#include "CartVector.h"
#include "CartPoint.h"
#include <fstream>
class Model;
using namespace std;

class GameObject
{
private:
    int id_num;
    
protected:
    CartPoint location;
    char display_code;
    char state;
    
public:
    GameObject(char in_code, int in_id);
    GameObject(char in_code, int in_id, CartPoint in_loc);
    virtual ~GameObject();

    void drawself(char* grid);
    virtual bool is_alive();
    virtual void show_status();
    virtual bool update() = 0;
    
    CartPoint get_location();
    char get_state();
    char get_dispCode();
    int get_id();
    
    virtual void save(ofstream& file);
    virtual void restore(ifstream& file, Model& model);
};



#endif /* defined(__PA3__GameObject__) */
