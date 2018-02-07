//
//  Port.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "Port.h"
#include <iostream>
#include "CartPoint.h"
#include "GameObject.h"

using namespace std;

//default constructor. Inherited from GameObject
Port::Port():GameObject('P',0)
{
    state = 'f';
    inventory = 500;
    cout << "Port default constructed" << endl;
}

//constructor. Inherited from GameObject
Port::Port(int in_id, CartPoint in_loc):GameObject('P', in_id, in_loc)
{
    inventory = 500;
    state = 'f';
    cout << "Port constructed" << endl;
}

//destructor
Port::~Port()
{
    cout << "Port destructed." << endl;
}

//a function to check if inventory is zero
bool Port::is_empty()
{
    if (inventory == 0)
        return true;
    else
        return false;
}

//a function to provide supplies from a port to a sailor
double Port::provide_supplies(double amount_to_provide)
{
    if (inventory>=amount_to_provide)
    {
        inventory = inventory - amount_to_provide;
        return amount_to_provide;
    }
    else
    {
        amount_to_provide = inventory;
        inventory = 0;
        return amount_to_provide;
    }
}

//update the state of port, if state changes, return true.
bool Port::update()
{
    if (is_empty()&&(state!='e'))
    {
        state = 'e';
        display_code = 'p';
        cout << "Port " << get_id() << "has been depleted of supplies" << endl;
        return true;
    }
    else
        return false;
}

//show the status of the port.
void Port::show_status()
{
    cout << "Port Status: " << display_code << " with ID " << get_id() << " at location " << location << " containing supplies " << inventory << endl;
}

void Port::save(ofstream& file)
{
    file << display_code << " " << get_id() << " " << state << " " << location << " " << inventory << endl;
}

void Port::restore(ifstream &file, Model &model)
{
    
}



