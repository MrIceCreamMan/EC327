//
//  Kraken.h
//  PA4
//
//  Created by MazeRunner on 15-12-10.
//  Copyright (c) 2015 Reno Jackson. All rights reserved.
//

#ifndef __PA4__Kraken__
#define __PA4__Kraken__

#include <iostream>
#include <list>
#include "GameObject.h"
class Sailor;

class Kraken: public GameObject
{
private:
    Kraken();
    Kraken(Kraken const&);
    void operator=(Kraken const&);
    static Kraken* m_pInstance;
public:
    ~Kraken();
    static Kraken* Instance();
    list<Sailor*> Ksailor_ptrs;
    list<Sailor*>::iterator Ksailor_it;
    int it_record;
    void warning();
    bool update();
    void claim();
    void history();
    void resetInstance();
    void save(ofstream& file);
    void restore(ifstream& file, Model& model);
};

#endif /* defined(__PA4__Kraken__) */
