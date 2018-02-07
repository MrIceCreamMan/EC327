//
//  Dock.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "Dock.h"
#include <iostream>
#include "CartPoint.h"
#include "GameObject.h"
#include "Sailor.h"

using namespace std;

//default constructor. Inherited from GameObject.
Dock::Dock():GameObject('d',0)
{
    state = 'u';
    berths = 30;
    cout << "Dock default constructed" << endl;
}

//constructor. Inherited from GameObject.
Dock::Dock(int in_id, CartPoint in_loc):GameObject('d',in_id,in_loc)
{
    state = 'u';
    berths = 30;
    cout << "Dock constructed" << endl;
}

//destructor
Dock::~Dock()
{
    cout << "Dock destructed." << endl;
}

//check if there are enough berth for sailor, if so, update berth and dock the boat
bool Dock::dock_boat(Sailor* sailor_to_dock)
{
    if (berths >= (*sailor_to_dock).get_size())
    {
        berths = berths-(*sailor_to_dock).get_size();
        return true;
    }
    else
        return false;
}

//check if the sailor has done unloading, if so let the sailor leave and update berth
bool Dock::set_sail(Sailor* sailor_to_sail)
{
    if ((*sailor_to_sail).get_cargo() == 0)
    {
        berths = berths+sailor_to_sail->get_presize();
        return true;
    }
    else
        return false;
}

//update the state of dock, if state changes, return true.
bool Dock::update()
{
    if ((berths == 0)&&(state != 'p'))
    {
        state = 'p';
        display_code = 'D';
        cout << "Dock " << get_id() << " is packed" << endl;
        return true;
    }
    else if ((berths != 0)&&(state == 'p'))
    {
        display_code = 'd';
        state = 'u';
        return false;
    }
    else
        return false;
}

//show the status of the dock.
void Dock::show_status()
{
    cout << "Dock Status: "<<display_code<<" with ID "<<get_id()<<" at location " << location << " has " << berths << " berths" << endl;
}





