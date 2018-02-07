//
//  pa3.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include <iostream>
#include "CartPoint.h"
#include "CartPoint.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"

using namespace std;

int main()
{
    char command;
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2015" << endl;
    cout << "Programming Assignment 3" << endl;
    
    //create a default Model class using the defaul constructor
    Model* model = new Model();
    //create a default View class using the defaul constructor
    View* view = new View();
    //clear and make the grid to have default values
    view->clear();
    //list out the status of each GameObjects
    do_list_command(model);
    
    //loop through until "quit" command is given
    while (true)
    {
        //display the grid to output a picture
        model->display(view);
        
        //get input from the user
        cout << "Enter command: ";
        cin >> command;
        
        //depends on what user's inputs are, call the corresponding fucntions
        switch (command)
        {
            case 's':
                do_sail_command(model);
                break;
                
            case 'p':
                do_port_command(model);
                break;
                
            case 'a':
                do_anchor_command(model);
                break;
                
            case 'd':
                do_dock_command(model);
                break;
                
            case 'h':
                do_hide_command(model);
                break;
                
            case 'g':
                do_go_command(model);
                do_list_command(model);
                break;
                
            case 'r':
                do_run_command(model);
                do_list_command(model);
                break;
                
            case 'l':
                do_list_command(model);
                break;
                
            //Terminate the program and destruct view and model
            case 'q':
                cout << "Terminating Program" << endl;
                model->display(view);
                view->~View();
                model->~Model();
                return 0;
                
            default:
                break;
        }
    }
}

