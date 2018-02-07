/**
   Write a function for Newton's method for finding roots: iterate
   until convergence (within a specified relative threshold). Use an
   initial guess of 1.

   inputs:
   * function : double -> double
   * dx > 0, the stepsize used in computing the derivative
   * tol > 0, the relative tolerance

   Expose deriv and newton in a header file, and compile
   with newton_test.cpp.
**/

#include "newton.h"

double deriv(double (*f)(double), float x, float dx) {
  // Your code here.
  return 0.0;
}

double newton(double (*f)(double), float dx, float tol) {
  // Your code here.
  // You'll probably want to use deriv(f, x, dx) and f(x) somewhere.
  return 0.0;
}