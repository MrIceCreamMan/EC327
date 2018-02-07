#include <iostream>
using namespace std;

int main()
{
  int *myList = new int[5];
  int *yourList = new int [10];
  myList[0] = 3;
  for (int i = 1; i < 5; i++)
    myList[i] = myList[i-1] + i;
  for (int i = 0; i < 5; i++)
    {
      yourList[i] = myList[i] + 4;
      yourList[i + 5] = myList[4 - i] - 3;
    }
  cout << "myList: ";
  for (int i = 0; i < 5; i++)
    cout << myList[i] << " ";
  cout << endl;
  cout << "yourList: ";
  for (int i = 0; i < 10; i++)
    cout << yourList[i] << " ";
  cout << endl;
  return 0;
}
