//
//  CartPoint.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__CartPoint__
#define __PA3__CartPoint__

#include <iostream>
class CartVector;
using namespace std;


class CartPoint
{
public:
    double x,y;
    CartPoint();
    CartPoint(double in_x, double in_y);
};

//nonmember functions
double cart_distance(CartPoint p1, CartPoint p2);
bool cart_compare(CartPoint p1, CartPoint p2);

//nonmember overloaded operators
ostream& operator<<(ostream& mycout,const CartPoint& p1);
CartPoint operator+(const CartPoint& p1, const CartVector& v1);
CartVector operator-(const CartPoint& p1, const CartPoint& p2);

#endif /* defined(__PA3__CartPoint__) */
