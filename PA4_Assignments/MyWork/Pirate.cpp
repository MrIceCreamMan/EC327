//
//  Pirate.cpp
//  PA4
//
//  Created by MazeRunner on 15-12-1.
//  Copyright (c) 2015 Reno Jackson. All rights reserved.
//

#include "Pirate.h"
#include "Merchant.h"
#include <cstdlib>
#include <iostream>
#include "Sailor.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Port.h"
#include "Dock.h"
#include "Model.h"

int Pirate::c =0;

Pirate::Pirate(Model* p_model):Sailor('R',p_model)
{
    attack_strength = 2;
    range = 1;
    size = 15;
    state = 'a';
    health = 25;
    state = 'a';
}

Pirate::Pirate(int ID, Model* p_model):Sailor('R',ID, p_model)
{
    attack_strength = 2;
    range = 1;
    size = 15;
    state = 'a';
    health = 25;
    state = 'a';
    
    //from here*************************************************
    
    
    double x,y;
    if (c == 0)
    {
        x = 6;
        y = 3;
        c = 40;
    }
    else if (c == 40)
    {
        x = 15;
        y = 17;
        c = 80;
    }
    else
    {
        x = 14;
        y = 0;
    }
    //to here*************************************************
    
    
    //double x = rand() % 20;
    //double y = rand() % 20;
    location = CartPoint(x,y);
}

Pirate::~Pirate()
{
}

double Pirate::get_speed()
{
    return 0;
}

void Pirate::start_plunder(Sailor* target)
{
    if (target->is_alive())
    {
        if (cart_distance(location,target->get_location())<=1)
        {
            cout << get_dispCode() << get_id() << ": Arrrggghhhh!" << endl;
            state = 'p';
            this->target = target;
        }
        else
        {
            state = 'a';
            cout << get_dispCode() << get_id() << ": I will be back for you!" << endl;
        }
    }
    else
    {
    }
}

bool Pirate::start_recruiting(Sailor* sailor)
{
    cout << get_dispCode() << get_id() << ": I dont recruit" << endl;
    return false;
}

bool Pirate::update()
{
    bool TF;
    switch (state)
    {
        case 'x':
            TF = false;
            break;
            
        case 'a':
            TF = false;
            break;
            
        case 'p':
          //  cout << " P " << endl;
            if (cart_distance(location, target->get_location()) <= 1)
            {
                target->get_plundered(this->attack_strength);
                if (target->is_alive())
                {
                    cout << get_dispCode() << get_id() << ": Arrghh matey!" << endl;
                    TF = false;
                }
                else
                {
                    cout << get_dispCode() << get_id() << ": I triumph!" << endl;
                    state = 'a';
                    TF = true;
                    health = health + 5;
                }
            }
            else
            {
                cout << get_dispCode() << get_id() << ": Darn! It escaped" << endl;
                target = NULL;
                state = 'a';
                TF = true;
            }
            break;
            
        default:
            cout << "update default in pirate, something wrong" << endl;
            break;
            
        }
        return TF;
}

void Pirate::show_status()
{
    cout << "Pirate status: ";
    Sailor::show_status();
}

Sailor* Pirate::get_target()
{
    return target;
}

void Pirate::save(ofstream& file)
{
    file << display_code << " " << get_id() << " " << state << " " << location << " ";
    file << health << " " << attack_strength << " " << range << " ";
    if (target == NULL)
        file << -1;
    else
        file << target->get_id();
    file << endl;
}

void Pirate::restore(ifstream &file, Model &model)
{
    
}




