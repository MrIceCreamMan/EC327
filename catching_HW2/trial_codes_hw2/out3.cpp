#include <iostream>
using namespace std;
int main()
{
  int *first = new int;
  int *second;
  *first = 85;
  second = first;
  *second = *second + *first;
  first = new int;
  *first = *second - 100;
  cout << *first << " " << *second << endl;
  return 0;
}
