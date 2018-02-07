#include <iostream>
using namespace std;

int * ReverseMultiply(int *list,int size)
{
  int s=size*2+1;
  double sum = 1;
  int * reAry = new int[s];
  //store the array in forward order
  for (int i = 0; i < size; i++)
    {
      sum = sum * list[i];
      reAry[i] = list[i];
    }
  //store the array in reverse order
  for (int j = size; j < (s-1); j++)
    {
      reAry[j] = list[s-2-j];
    }
  //calculate the product and store it in last element
  reAry[s-1] = sum * sum;
  return reAry;
}
int main()
{
  int size;
  cout << "Enter the number of entries: ";
  cin >> size;
  if (size < 1)
    {
      cout << "Invalid size entered." << endl;
      return 0;
    }
  int * list = new int[size];
  //pointer pointer to heap so the size can be variable
  for(int i = 0; i < size; i++)
    {
      cout << "Entry " << i << " is: ";
      cin >> list[i];
    }
  cout << "*****" << endl;
  cout << "Original array is: ";
  for(int j = 0; j < size; j++)
    {
      cout << list[j] << " ";
    }
  cout << "and the address of the zero element is: ";
  cout << &list << endl;
  int* fAry = ReverseMultiply(list, size);
  cout << "Final array is: ";
  for(int k = 0; k < (size*2+1); k++)
    {
      cout << fAry[k] << " ";
    }
  cout << "and the address of the zero element is: ";
  cout << &fAry << endl;
  return 0;
}
