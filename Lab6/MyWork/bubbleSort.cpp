#include <iostream>
using namespace std;

void bubbleSort(int * intArray, int size)
{
  for (int j =0; j<size; j++)
    {
      for (int i = 0; i < size-1; i++)
	{
	  if (intArray[i] > intArray[i+1])
	    {
	      int temp = intArray[i];
	      intArray[i] = intArray[i+1];
	      intArray[i+1] = temp;
	    }
	}
    }
}


void bubbleSort(char * charArray, int size)
{
  for (int j =0; j<size; j++)
    {
      for (int i = 0; i < size-1; i++)
	{
	  if (charArray[i] > charArray[i+1])
	    {
	      char temp = charArray[i];
	      charArray[i] = charArray[i+1];
	      charArray[i+1] = temp;
	    }
	}
    }
}
