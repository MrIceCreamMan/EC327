/*
  TestCheckPoint4.cpp
  PA3 --- "Pirates on the High C's"
  
  https://www.youtube.com/watch?v=OosYFs3cyZ8
  Modified by Douglas Densmore 10/31/15
  Copyright (c) 2015 Boston University. All rights reserved.
*/

#include <iostream>

#include "CartVector.h"
#include "CartPoint.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
#include "GameCommand.h"
#include "Model.h"

//Students need to build on this
int main()
{

	//YOU NEED TO DO MUCH MORE THAN THIS TO TEST THE FUNCTIONALITY!
	Model* model = new Model();
    model->show_status();
	
	//You are going to have to type something for cin
	cout << "Tell what to anchor: " << endl;
	doAnchorCommand(model);
	doRunCommand(model);
	
	//You are going to have to type something for cin
	cout << "Tell what to sail: " << endl;
	doSailCommand(model);
	doRunCommand(model);
	
	cout << "Tell what to port: " << endl;
	doPortCommand(model);
	doRunCommand(model);
	
	cout << "Tell what to dock: " << endl;
	doDockCommand(model);
	doRunCommand(model);
	
	cout << "Tell what to hide: " << endl;
	doHideCommand(model);
	doRunCommand(model);
	
	doListCommand(model);
	
	// all tests passed!
    cout << "Checkpoint4 passed!" << endl;
	return 0;
}