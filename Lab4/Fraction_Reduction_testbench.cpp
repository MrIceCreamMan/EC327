#include "fraction.h"
#include <iostream>

int main() {
    // Let's look at the aspect ratio of a full-HD display.
    int a = 1920,
        b = 1080;
    std::cout << "Sanity check: gcd(" << a << ", "
              << b << ") = " << gcd(a, b) << std::endl;
    reduce_fraction(a, b);
    std::cout << "Full HD has an aspect ratio of "
              << a << ":" << b << std::endl;
    return 0;
}