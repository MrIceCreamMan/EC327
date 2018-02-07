//
//  CartPoint.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "CartPoint.h"
#include "CartVector.h"
#include <iostream>
#include <cmath>
using namespace std;

//default constructor
CartPoint::CartPoint()
{
    x=0;
    y=0;
}

//constructor
CartPoint::CartPoint(double in_x, double in_y)
{
    x=in_x;
    y=in_y;
}

//calculate the distance between two cartesian points
double cart_distance(CartPoint p1, CartPoint p2)
{
    double horizontal = (p1.x - p2.x)*(p1.x - p2.x);
    double vertical = (p1.y - p2.y)*(p1.y - p2.y);
    return sqrt(horizontal+vertical);
}

//compare if two cartesian points are the same
bool cart_compare(CartPoint p1, CartPoint p2)
{
    return ((p1.x==p2.x)&&(p1.y==p2.y));
}

//overload the out stream operator to be able to output cartesian point class
ostream& operator<<(ostream& mycout,const CartPoint& p1)
{
    mycout << "(" << p1.x << ", " << p1.y << ")";
    return mycout;
}

istream& operator>>(istream& mycin, CartPoint& p1)
{
    mycin >> p1.x;
    mycin >> p1.y;
    return mycin;
}

istream& operator>>(istream& mycin, CartVector& v1)
{
    mycin >> v1.x;
    mycin >> v1.y;
    return mycin;
}

//overload the + operator to be able to do calculations for CartPoint and CartVector classes
CartPoint operator+(const CartPoint& p1, const CartVector& v1)
{
    double newx = p1.x + v1.x;
    double newy = p1.y + v1.y;
    return CartPoint(newx,newy);
}

//overload the - operator to be able to do calculations for two CartPoint class
CartVector operator-(const CartPoint& p1, const CartPoint& p2)
{
    double newx = p1.x - p2.x;
    double newy = p1.y - p2.y;
    return CartVector(newx,newy);
}






