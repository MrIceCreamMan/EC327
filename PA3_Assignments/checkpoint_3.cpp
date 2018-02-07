/*
  TestCheckPoint3.cpp
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

//Students need to build on this
int main()
{
	CartPoint p1(10,20);
	CartPoint p2(30,40);
	Dock dock1(1,p1);
	Port port1(2, p2);
	Sailor sailor1(3, &dock1);
	
	cout << "******************" << endl;
	port1.update();
	port1.show_status();
	cout << "******************" << endl;
	dock1.update();
	dock1.show_status();
	cout << "******************" << endl;
	sailor1.update();
	sailor1.show_status();
	cout << "******************" << endl;
	
	CartPoint p3(11,20);
	sailor1.start_sailing(p3);
	sailor1.update();
	sailor1.show_status();
	cout << "******************" << endl;
	sailor1.start_supplying(&port1);
	sailor1.update();
	sailor1.show_status();
	cout << "******************" << endl;
	sailor1.update();
	sailor1.show_status();
	cout << "******************" << endl;
	sailor1.update();
	sailor1.show_status();
	cout << "******************" << endl;
	sailor1.update();
	sailor1.show_status();
	cout << "******************" << endl;
	sailor1.update();
	sailor1.show_status();
	cout << "******************" << endl;
	
	// all tests passed!
    cout << "Checkpoint3 passed!" << endl;
	return 0;
}