//
//  GameObject.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "GameObject.h"
#include <iostream>
#include "CartVector.h"
#include "CartPoint.h"
using namespace std;

//default constructor
GameObject::GameObject(char in_code, int in_id)
{
    display_code = in_code;
    id_num = in_id;
    location = CartPoint(0,0);
    cout << "GameObject constructed" << endl;
}

//constructor
GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    cout << "GameObject constructed" << endl;
}

//destructor
GameObject::~GameObject()
{
    cout << "GameObject destructed" << endl;
}

//a function to get location
CartPoint GameObject::get_location()
{
    return location;
}

//a function to get id_num
int GameObject::get_id()
{
    return id_num;
}

//a virtual function to show status
void GameObject::show_status()
{

    cout << display_code << " with ID " << id_num << " at location " << location << endl;
}

//a function to put a game object into the appropriate loaction in the grid
void GameObject::drawself(char* grid)
{
    grid[0] = display_code;
    grid[1] = static_cast<char>(get_id()+ 48);
}

char GameObject::get_state()
{
    return state;
}

bool GameObject::is_alive()
{
    return true;
}

char GameObject::get_dispCode()
{
    return display_code;
}

void GameObject::save(ofstream& file)
{
    
}

void GameObject::restore(ifstream &file, Model &model)
{
    
}


