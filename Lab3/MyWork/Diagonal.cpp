# include <iostream>
using namespace std;

int main()
{
  int var;
  cout << "Enter a integer N greater than 0 and less than 10: " << endl;
  cin >> var;
while ((var >= 10)||(var < 1))
    {
      cout << "Invalid value for N!" << endl;
      cout << "Enter a integer N greater than 0 and less than 10: " << endl;
     cin >> var;
    }
  cout << "N: " << var << endl;
  for (int i = var; i > 0; i--)
    {
      for (int j = i;j > 1; j--)
	{
	  cout << " ";
	}
      cout << i << endl;
    }
  return 0;
 }
    
