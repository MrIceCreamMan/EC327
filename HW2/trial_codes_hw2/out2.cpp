#include <iostream>
using namespace std;
int main()
{
  int *length;
  int *width;
  length = new int;
  *length = 5;
  width = length;
  length = new int;
  *length = 2 * (*width);
  cout << *length << " " << *width << " " << (*length) * (*width) << endl;
  return 0;
}
