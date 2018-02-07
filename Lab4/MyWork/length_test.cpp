#include "length.h"
#include <iostream>

int main() {
  double tol = 1e-6;
  std::cout << std::fixed;
  std::cout << "sqrt(3) is roughly " << sqrt(3, tol) << std::endl;
  std::cout << "The length of (12, 16, 21) is "
            << length(12, 16, 21, tol) << std::endl;
  return 0;
}
