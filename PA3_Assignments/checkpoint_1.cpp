/*
  TestCheckPoint1.cpp
  PA3 --- "Pirates on the High C's"
  
  https://www.youtube.com/watch?v=OosYFs3cyZ8
  
Modified by Douglas Densmore 10/31/15
Copyright (c) 2015 Boston University. All rights reserved.
*/

#include <iostream>

#include "CartVector.h"
#include "CartPoint.h"

//Students need to build on this
int main()
{
	
	// Testing CartPoint
	CartPoint p1 = CartPoint(0, 0);
	if(p1.x != 0 && p1.y != 0) 
	{
		cout << "CartPoint is not working!" << endl;
		return 1;
	}

	CartVector v1 = CartVector(4,-3);
	CartPoint p2 = p1+v1;
	cout << p2 << endl;
	p2 = p2+v1;
	cout << p2 << endl;
	cout << v1 << endl;
	
	double a=0.0;
	double b=3.0;
	//creating CartPoint objects
	CartPoint p3 (a,b);
	CartPoint p4;

	//checking behavior of non-member functions of CartPoint.cpp
	cout<<"Distance: "<<cart_distance(p3,p4)<<endl;
	cout<<"Compare: "<<cart_compare(p3,p4)<<endl;
	
	//checking behavior of overloading operators defined in CartPoint.cpp
	cout<<"p3= "<<p3<<endl;
	
	
	/* your code here: test '<<', '-', '+' overloaded operators */

	
	
	//creating CartVector objects
	CartVector v2(5.0, 10.0);
	CartVector v3(15.0, 20.0);
    
	
	/*your code here: test '<<', '*','/' overloaded operators */

	
	//Add more tests...
	//YOU NEED TO CONVINCE YOURSELF THAT EVERYTHING WORKS AS EXPECTED
	//Make sure to try corner cases, negative values, v1/0, etc.
	
	// all tests passed!
    cout << "Checkpoint1 passed!" << endl;
	return 0;
}