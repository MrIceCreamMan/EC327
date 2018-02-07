//
//  Kraken.cpp
//  PA4
//
//  Created by MazeRunner on 15-12-10.
//  Copyright (c) 2015 Reno Jackson. All rights reserved.
//

#include "Kraken.h"
#include <iostream>
#include "GameObject.h"
#include "Sailor.h"

using namespace std;

Kraken* Kraken::m_pInstance = NULL;

Kraken::Kraken():GameObject('K',1)
{
    Ksailor_it = Ksailor_ptrs.begin();
    it_record = 0;
}
Kraken::~Kraken()
{
    cout << "Kraken destructed" << endl;
}
void Kraken::resetInstance()
{
    delete m_pInstance;
    m_pInstance = NULL;
}

Kraken* Kraken::Instance()
{
    if (m_pInstance==NULL)
    {
        m_pInstance = new Kraken();
    }
    return m_pInstance;
}

bool Kraken::update()
{
    cout << "yeah" << endl;
    return false;
}

void Kraken::warning()
{
    cout << "The Kraken is coming!" << endl;
}

void Kraken::claim()
{
    cout << "The Kraken is upon us!" << endl;
    cout << "----------The Kraken Claimed----------" << endl;
    int i = 1;
    Ksailor_it = Ksailor_ptrs.begin();
    for (int j = 0; j < it_record; j++)
        Ksailor_it++;
    for (; Ksailor_it != Ksailor_ptrs.end(); Ksailor_it++)
    {
        cout << "(" << i << ") - " << (*Ksailor_it)->get_dispCode() << (*Ksailor_it)->get_id() << endl;
        i++;
        it_record++;
    }
    cout << "-----------------------------------------" << endl;
}

void Kraken::history()
{
    cout << "----------The History of Kraken's Wrath----------" << endl;
    int i = 1;
    for (Ksailor_it = Ksailor_ptrs.begin(); Ksailor_it != Ksailor_ptrs.end(); Ksailor_it++)
    {
        cout << "(" << i << ") - " << (*Ksailor_it)->get_dispCode() << (*Ksailor_it)->get_id() << endl;
        i++;
    }
    cout << "----------------------------------------------------" << endl;
}

void Kraken::save(ofstream& file)
{
    file << "K" << " ";
    file << it_record;
    for (Ksailor_it = Ksailor_ptrs.begin(); Ksailor_it!=Ksailor_ptrs.end(); Ksailor_it++)
        file << " " << (*Ksailor_it)->get_id();
    file << endl;
}

void Kraken::restore(ifstream& file, Model& model)
{
    
}




