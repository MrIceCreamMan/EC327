#include <cmath>
#include <iostream>

#include "newton.h"

inline double pi_function(double x) {
  return std::cos(x) + 1;
}

inline double e_function(double x) {
  return std::log(x) - 1;
}

int main() {
  double dx = 1e-6,
         tol = 1e-6;
  std::cout << "derivative of cosine at 0 is "
            << deriv(&std::cos, 0, dx) << std::endl;
  std::cout << "pi is roughly " << newton(&pi_function, dx, tol)
            << std::endl;
  std::cout << "e is roughly " << newton(&e_function, dx, tol)
            << std::endl;
  return 0;
}