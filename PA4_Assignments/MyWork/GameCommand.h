//
//  GameCommand.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__GameCommand__
#define __PA3__GameCommand__

#include <iostream>
#include "InputHandling.h"
class Model;

//these are the functions in GameCommand header file
void do_sail_command(Model* model);
void do_go_command(Model* model);
void do_run_command(Model* model);
void do_port_command(Model* model);
void do_hide_command(Model* model);
void do_anchor_command(Model* model);
void do_list_command(Model* model);
void do_dock_command(Model* model);
void do_plunder_command(Model* model);
void handle_new_command(Model* model);
void do_save_command(Model* model);
void do_restore_command(Model* model);

//void do_showall(Model*);


#endif /* defined(__PA3__GameCommand__) */

