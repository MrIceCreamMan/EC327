#include <iostream>
using namespace std;
int** matrix = new int*[9];
int count = 0;
int count2 = 0;
bool done = false;
bool DONE = false;
bool reverse = false;
int i = 0;
int reset = 1;

void PrintRhombus(int n)
{
  if (DONE)
    {
      count = count + 1;
      if (count == count2)
	{
	  return;
	}
      else
	{
	  for (int i = 0; i < count; i++)
	    {
	      cout << "  ";
	    }
	  for (int i = 0; i < (count2-count)*2-1; i++)
	    {
	      cout << matrix[count][i] << " ";
	    }
	  cout << endl;
	  PrintRhombus(count);
	}
       
    }
  else if (done)
    {
      for (int i = 1; i < count; i++)
	{
	  cout << "  ";
	}
      for (int i = 0; i <(count2-count+1)*2-1 ;i++)
	{
	  cout << matrix[count-1][i] << " ";
	}
      cout << endl;
      count = count -1;
      if (count == 0)
	{
	  DONE = true;
	  PrintRhombus(count);
	}
      else
	{
	  PrintRhombus(count);
	}
    }
  else
    {
      if (reset == 1)
	{
	  *(matrix+count) = new int[2*n-1];
	  reverse = false;
	}
      if (reverse)
	{
	  if (n==1)
	    {
	      count = count + 1;
	      count2 = count;
	      done = true;
	      PrintRhombus(count);
	    }
	  *(*(matrix+count)+i) = 2*n-i-1;
	  i = i+1;
	  if (i == 2*n-1)
	    {
	      reset = 1;
	      i = 0;
	      count = count + 1;
	      if (n > 1)
		PrintRhombus(n-1);
	    }
	  else
	    PrintRhombus(n);
	}
      else
	{
	  *(*(matrix+count)+i) = i+1;
	  i = i + 1;
	  reset = 0;
	  if (i == n)
	    {
	      reverse = true;
	      PrintRhombus(n);
	    }
	  else
	    {
	      PrintRhombus(n);
	    }
   	 }
    }
}


int main()
{
  cout << "Enter a number [1-9]: ";
  int n;
  cin >> n;
  while ((n>9)||(n<1))
    {
      cout << "Wrong input, please enter a single digit number between 1 and 9." << endl << endl;
      cout << "Enter a number [1-9]: ";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> n;
    }
  PrintRhombus(n);
  return 0;
}
