#include <iostream>
#include "count.h"

int main()
{
    std::cout << "Flipping 4 coins, we can get 2 heads "
              << choose(4, 2) << " ways." << std::endl;
    // This one will require that you be somewhat clever, since 1000! will
    // overflow even a long long, undoubtedly. Expected result is 1001.
    std::cout << "Flipping 1000 coins, we can get at least 999 heads "
              << head_count(1000, 999) << " ways." << std::endl;
    return 0;
}