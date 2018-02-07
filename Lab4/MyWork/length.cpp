#include <iostream>
#include "length.h"
using namespace std;


double length(double a, double b, double c, double tol)
{
  double o;
  o = sqrt(a*a+b*b+c*c,tol);
  return o;
}


double abs(double a)
{
  double b;
  if (a < 0)
    b = -a;
  else
    b = a;
  return b;
}

double min(double a,double b)
{
  double o;
  if (a < b)
    {
      o = a;
    }
  else
    {
      o = b;
    }
  return o;
}


double sqrt(double N, double tol)
{
  double guess = 3;
  guess = (guess + ( N/guess))/2;
  int flag = 0;
  double g;
  while (flag == 0)
    {
      guess = (guess + (N/guess))/2;
      g = (abs(guess - N/guess))/min(guess,N/guess);
      flag = (g <= tol);
      //cout << guess << endl;
      //cout << flag << endl;
      //cout << g << endl;
      //cout << tol << endl;
      //cout << " hello " << endl;
    }
  return guess;
}
