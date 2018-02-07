//
//  Merchant.cpp
//  PA4
//
//  Created by MazeRunner on 15-11-24.
//  Copyright (c) 2015年 Reno Jackson. All rights reserved.
//

#include "Merchant.h"
#include "Pirate.h"
#include <iostream>
#include "Sailor.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Port.h"
#include "Dock.h"
#include "Model.h"

using namespace std;

Merchant::Merchant(Model* m_model):Sailor('M',m_model)
{
    size = 10;
    presize = 10;
    health = 60;
    recruit_time = 0;
    state = 'h';
}

Merchant::Merchant(int id, Dock* home, Model* m_model):Sailor('M', id, home, m_model)
{
    size = 10;
    presize = 10;
    health = 60;
    recruit_time = 0;
    state = 'h';
}

Merchant::~Merchant()
{
}

double Merchant::get_speed()
{
    return (1/size)*health*4;
}

bool Merchant::start_recruiting(Merchant* sailor_mate)
{
//    cout << get_id() << get_state() << recruit_time << endl;
// ******************************************************************
    if (this->hideout->get_id() == sailor_mate->hideout->get_id())
    {
        if (this->is_hidden()&sailor_mate->is_hidden())
        {
            if (this->hideout->get_berth()>=10)
            {
                if (this->health>=40 && this->health <=60)
                {
                    if (sailor_mate->health>= 40 && sailor_mate->health<=60)
                    {
                        if (s_model->get_sailor_in_dock(this) == 2)
                        {
                            sailor_mate->state = 'r';
                            this->recruit_time++;
                            sailor_mate->recruit_time++;
                         //   cout << "time ++" << endl;
                            if (this->recruit_time == 3)
                            {
                                sailor_mate->state = 'a';
                                sailor_mate->recruit_time = 0;
                                this->recruit_time = 0;
                                cout << get_dispCode() << get_id() << ": I found a new recruit!" << endl;
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                        }
                        else
                        {
                            this->recruit_time = 0;
                            sailor_mate->recruit_time = 0;
                            sailor_mate->state = 'a';
//                            cout << "other merchants in the dock" << endl;
                            return false;
                        }
                    }
                    else
                    {
//                        cout << "sailor mate health is low" << endl;
                    }
                }
                else
                {
//                    cout << "sailor health is low" << endl;
                }
            }
            else
            {
//                cout << "Home dock does not have enough space" << endl;
            }
        }
        else
        {
//            cout << "they are not in their hideouts" << endl;
        }
    }
    else
    {
//        cout << "two sailors have different hideout locations" << endl;
    }
    return  false;
}

void Merchant::start_plunder(Sailor* sailor)
{
    cout << "I cannot plunder." << endl;
}

bool Merchant::update()
{
    bool TF1 = false;
    if (state == 'r')
    {
        Merchant* mate = this->s_model->get_sailor_mate(this);
        if (mate == NULL)
        {
        //    cout << "mate Null " << endl;
            recruit_time = 0;
            state = 'a';
        }
        else if (mate->get_state() != 'a')
        {
        //    cout << mate->get_dispCode() << mate->get_id() << mate->get_state() << endl;
            recruit_time = 0;
            state = 'a';
        }
        else
        {
      //      cout << mate->get_dispCode() << mate->get_id() << mate->get_state() << endl;
     //       cout << "recruiting " << recruit_time << endl;
        }
        
    }
    else if (state == 'a')
    {
     //   cout << endl << endl << get_id() << " called a " << recruit_time << endl << endl;
        //00p================================================
        Merchant* mate = this->s_model->get_sailor_mate(this);
        if (mate != NULL)
        {
            if (start_recruiting(mate))
            {
                int newID = this->s_model->get_new_ID(this);
                Merchant* recruited_m_ptr = new Merchant(newID,this->hideout,this->s_model);
                this->s_model->add_new_object(recruited_m_ptr);
                TF1 = true;
            }
            else if ((this->recruit_time == 0)&(this->s_model->AtDock(this)))
            {
               // cout << "recruit not good in else 1" << endl;
                if (health < 5)
                    state = 'x';
                else
                    health = health -5;
            }
            else if (this->recruit_time == 1)
            {
               // cout << "recruit not good in else if 2" << endl;
                TF1 = true;
            }
            else
            {
              //  cout << "recruit not successful in else " << endl;
            }
        }
        else if (this->s_model->AtDock(this))
        {
            if (health < 5)
                state = 'x';
            else
                health = health -5;
        }
    }
    else
    {
        recruit_time = 0;
    }
    bool TF2;
    TF2 = Sailor::update();
    bool TF = (TF1|TF2);
    return TF;
}

void Merchant::show_status()
{
    if (is_alive())
        cout << "Merchant status: ";
    if ((recruit_time != 0) & (state == 'a'))
    {
        Merchant* mate = this->s_model->get_sailor_mate(this);
        cout << get_dispCode() << " with ID " << get_id() << " at location " << get_location() << " is recruiting a merchant with " << mate->get_dispCode() << mate->get_id() << "." << endl;
    }
    else if ((recruit_time != 0) & (state == 'r'))
    {
        Merchant* mate = this->s_model->get_sailor_mate(this);
        cout << get_dispCode() << " with ID " << get_id() << " at location " << get_location() << " is recruiting a merchant with " << mate->get_dispCode() << mate->get_id() << "." << endl;
    }
    else
    {
        Sailor::show_status();
    }
}

void Merchant::save(ofstream& file)
{
    file << display_code << " " << get_id() << " " << state << " " << location << " ";
    file << hold << " " << cargo << " " << size << " " << presize << " " << health << " " << destination << " " << delta << " " << recruit_time << " " ;
    if (port == NULL)
        file << -1 << " ";
    else
        file << port->get_id() << " ";
    if (dock == NULL)
        file << -1 << " ";
    else
        file << dock->get_id() << " ";
    if (hideout == NULL)
        file << -1;
    else
        file << hideout->get_id();
    file << endl;
}

void Merchant::restore(ifstream &file, Model &model)
{
    
}





