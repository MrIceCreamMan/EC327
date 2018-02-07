#include <iostream>
using namespace std;
int main()
{
  int x = 3;
  int y = 3;
  y =((true) && (3>4));
  cout << y << endl;
  y = (!(x>0) && (x>0));
  cout << y << endl;
  y = ((x>0)||(x<0));
  cout << y << endl;
  if (x>2)
    if (y>2)
      {
	int z = x+y;
	cout << "z is " << z << endl;
      }
    else 
      cout << "x is " << x << endl;
  return 0;
}
