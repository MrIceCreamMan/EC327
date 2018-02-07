#include <iostream>
using namespace std;

int main()
{
  char* const pCity = "Dallas";
  cout << pCity << endl;
  cout << *pCity << endl;
  cout << *(pCity + 1) << endl;
  cout << *(pCity + 2) << endl;
  cout << *(pCity + 3) << endl;
  return 0;
}
