//
//  View.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "View.h"

//default constructor
View::View()
{
    size = 11;
    scale = 2;
    origin = CartPoint(0,0);
}

//destructor
View::~View()
{
    cout << "View destructed." << endl;
}

//find the correct subscripts in the grid for the input location CartPoint
//if the subsripts are out of the grid range, display an error message
bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
    CartVector scriptVec;
    scriptVec = (location - origin)/scale;
    iy = static_cast<int>(scriptVec.x);
    int tempx;
    tempx = static_cast<int>(scriptVec.y);
    ix = size -1 - tempx;
    if ((ix <= size)&&(iy <= size)&&(ix >= 0)&&(iy >= 0))
    {
        return true;
    }
    else
    {
        return false;
        cout << "An Object is outside the display" << endl;
    }
}

//clear the grid to a defaul state
void View::clear()
{
    for (int i = 0; i < view_maxsize; i++)
    {
        for (int j = 0; j < view_maxsize; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

//plot each input GameOject into the coresponding location in the grid
void View::plot(GameObject *ptr)
{
    int ix,iy;
    if (get_subscripts(ix, iy, ptr->get_location()))
    {
        if (grid[ix][iy][0] == '.')
        {
            ptr->drawself(grid[ix][iy]);
        }
        else
        {
            grid[ix][iy][0] = '*';
            grid[ix][iy][1] = ' ';
        }
    }
    return;
}

//draw the grid to output a visual picture
//also label the the axis with some numbers
void View::draw()
{
    int ylabel = (size-1)*scale;
    int num_label = ylabel/5;
    for (int i = 0; i < size; i++)
    {
        int scalei = scale*i;
        if ((ylabel-scalei)%num_label)
        {
            cout << "  ";
        }
        else if (ylabel - scalei >= 10)
        {
            cout << ylabel - scalei;
        }
        else
        {
            cout << ylabel - scalei << " ";
        }
        for (int j = 0; j < size; j++)
        {
            cout << grid[i][j][0];
            cout << grid[i][j][1];
        }
        cout << endl;
    }
    cout << "  ";
    for (int j = 0; j <= size; j++)
    {
        int scalej = j*scale;
        if (scalej%num_label)
        {
            cout << "  ";
        }
        else if (scalej < 10)
        {
            cout << scalej << " ";
        }
        else
        {
            cout << scalej;
        }
    }
    cout << endl;
}




