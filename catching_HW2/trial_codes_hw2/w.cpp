#include <iostream>
using namespace std;

int main()
{
  int number, sum = 0, count;

  for  (count =0; count < 5; count++)
    {
      cin >> number;
      sum += number;
    }

  cout << "sum is " << sum << endl;
  cout << "count is " << count << endl;

  return 0;
}
