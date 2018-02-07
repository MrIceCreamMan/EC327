#include <iostream>
using namespace std;
int main()
{
  return 0;
}
int function1(int n)
{
  cout << n;
}
int function2(int n,int m)
{
  n+= m;
  function1(3.4);
}
