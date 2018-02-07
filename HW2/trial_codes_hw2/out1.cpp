#include <iostream>
using namespace std;
int main()
{
  int num1;
  int num2;
  int *p = &num1;
  p = &num2;
  *p + 25;
  num1 = num2 +6;
  p = &num1;
  num2 = 73;
  *p = 47;
  cout << *p << " " << num1 << " " << num2 << endl;
  return 0;
}
