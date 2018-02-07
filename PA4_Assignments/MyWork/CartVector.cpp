//
//  CartVector.cpp
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#include "CartVector.h"
#include "CartPoint.h"
#include <iostream>
#include <cmath>
using namespace std;

//default constructor
CartVector::CartVector()
{
    x=0;
    y=0;
}

//constructor
CartVector::CartVector(double in_x, double in_y)
{
    x=in_x;
    y=in_y;
}

//overload * operator to perform calculation for a double and a CartVector class
CartVector operator*(const CartVector& p1, const double& d)
{
    if (d!=0)
    {
        double newx = p1.x * d;
        double newy = p1.y * d;
        return CartVector(newx,newy);
    }
    else
        return CartVector(p1.x,p1.y);
}

//overload / operator to perform calculation for a double and a CartVector class
CartVector operator/(const CartVector& p1, const double& d)
{
    if (d!=0)
    {
        double newx = p1.x/d;
        double newy = p1.y/d;
        return CartVector(newx,newy);
    }
    else
        return CartVector(p1.x,p1.y);
}

//overload << operator to be able to output CartVector class
ostream& operator<<(ostream& mycout,const CartVector& v1)
{
    mycout << "<" << v1.x << ", " << v1.y << ">";
    return mycout;
}
