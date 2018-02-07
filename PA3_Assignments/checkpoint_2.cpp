/*
  TestCheckPoint2.cpp
  PA3 --- "Pirates on the High C's"
  
  https://www.youtube.com/watch?v=OosYFs3cyZ8
  
  Modified by Douglas Densmore 10/31/15
  Copyright (c) 2015 Boston University. All rights reserved.
*/

#include <iostream>

#include "CartPoint.h"
#include "Port.h"

//Students need to build on this
int main()
{

	CartPoint p1(45,90);
	Port port1(1, p1);
	port1.update();
	port1.show_status();
	port1.provide_supplies(10);
	port1.update();
	port1.show_status();
	port1.provide_supplies(491);
	port1.update();
	port1.show_status();
	
	//Add more tests...
	//Make sure you try everything out...
	
	// all tests passed!
    cout << "Checkpoint2 passed!" << endl;
	return 0;
}