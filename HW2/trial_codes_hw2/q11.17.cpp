#include <iostream>
using namespace std;

void f1(int x, int& y, int* z)
{
  x++;
  y++;
  (*z)++;
}

int main()
{
  int i = 1, j = 1, k = 1;
  f1(i, j , &k);

  cout << "i is " << i << endl;
  cout << "j is " << j << endl;
  cout << "k is " << k << endl;

  return 0;
}
