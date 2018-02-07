//
//  main.cpp
//  PA4
//
//  Created by MazeRunner on 15-11-24.
//  Copyright (c) 2015 Reno Jackson. All rights reserved.
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
    Model* world = new Model();
    //create a default View class using the defaul constructor
    View* view = new View();
    //clear and make the grid to have default values
    view->clear();
    //list out the status of each GameObjects
    do_list_command(world);
    
    //loop through until "quit" command is given
    while (true)
    {
        //display the grid to output a picture
        world->display(view);
        
        try
        {
            //get input from the user
            cout << "Enter command: ";
            if(!(cin >> command))
                throw InvalidInput("Expected char");
            
            //depends on what user's inputs are, call the corresponding fucntions
            switch (command)
            {
                case 's':
                    do_sail_command(world);
                    break;
                    
                case 'p':
                    do_port_command(world);
                    break;
                    
                case 'a':
                    do_anchor_command(world);
                    break;
                    
                case 'd':
                    do_dock_command(world);
                    break;
                    
                case 'h':
                    do_hide_command(world);
                    break;
                    
                case 'g':
                    do_go_command(world);
                    do_list_command(world);
                    break;
                    
                case 'r':
                    do_run_command(world);
                    do_list_command(world);
                    break;
                    
                case 'l':
                    do_list_command(world);
                    break;
                    
                case 'u':
                    do_plunder_command(world);
                    break;
                    
                case 'x':
                    world->showall();
                    break;
                    
                case 'n':
                    handle_new_command(world);
                    break;
                    
                case 'S':
                    do_save_command(world);
                    break;
                    
                case 'L':
                    do_restore_command(world);
                    break;
                    
                    //Terminate the program and destruct view and world
                case 'q':
                    cout << "Terminating Program" << endl;
                    world->display(view);
                    view->~View();
                    world->~Model();
                    return 0;
                    
                default:
                    throw InvalidInput("unrecognized command");
                    break;
            }
        }
        catch (InvalidInput& except)
        {
            
            cout << "Invalid input - " << except.msg_ptr << endl;
        }
    }
}


