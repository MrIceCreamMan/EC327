//
//  CartVector.h
//  PA3
//
//  Created by MazeRunner on 15-11-9.
//  Copyright (c) 2015 Jack. All rights reserved.
//

#ifndef __PA3__CartVector__
#define __PA3__CartVector__

#include <iostream>
class CartPoint;
using namespace std;


class CartVector
{
public:
    double x,y;
    CartVector();
    CartVector(double in_x, double in_y);
};

//nonmember overloaded operators
CartVector operator*(const CartVector& v1, const double& d);
CartVector operator/(const CartVector& v1, const double& d);
ostream& operator<<(ostream& mycout,const CartVector& v1);

#endif /* defined(__PA3__CartVector__) */
