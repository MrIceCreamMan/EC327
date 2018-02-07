//
//  View.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__View__
#define __PA3__View__

#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"

using namespace std;

const int view_maxsize=20;

class View
{
private:
    int size;
    double scale;
    CartPoint origin;
    char grid[view_maxsize][view_maxsize][2];
    
    //private member function
    bool get_subscripts(int &ix, int &iy, CartPoint location);
public:
    View();
    ~View();
    
    //public member functions
    void clear();
    void plot(GameObject* ptr);
    void draw();
};



#endif /* defined(__PA3__View__) */
