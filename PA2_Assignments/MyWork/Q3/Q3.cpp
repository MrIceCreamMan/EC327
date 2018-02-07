#include <iostream>
#include <iomanip>
using namespace std;
#include "q3func.h"
#include "statistics.h"

int main()
{
  int fail,large,small;
  int myArray[1000];
  //the maximum file size is 1000; 
  int size;
  fail = DataFromFile("numbers.txt", myArray, size);
  //check if successful
  if (fail == 1)
    {
      cout << "Function DataFromFile did not run successfully." << endl;
      cout << "Make sure \"numbers.txt\" exists in current directory" << endl;
    }
  else
    {
      float mean,std;
      mean = getMean(myArray, size);
      std = getStdDev(myArray, size);
      cout << "Array size is: " << size << endl;
      //if size is 0, print none to all the other parts
      if (size == 0)
	{
	  cout <<"Mean is: None\nStdDev is: None\nArray values forward are: None\n";
	  cout <<"Array values reverse are: None\nThe largest array value is: None\n";
	  cout <<"The smallest array value is: None\n";
	}
      else
	//format the output to meet the requirements
	//print the forward array
	{
	  std::cout.precision(2);
	  cout << "Mean is: " << fixed << mean << endl;
	  cout << "StdDev is: " << fixed << std << endl;
	  cout.unsetf(std::ios::floatfield);
	  std::cout.precision(10);
	  cout << "Array values forward are: ";
	  large = myArray[0];
	  small = myArray[0];
	  for (int i = 0; i < size; i++)
	    {
	      cout << myArray[i];
	      if (i != size-1)
		cout << ", ";
	      if (large < myArray[i])
		large = myArray[i];
	      if (small > myArray[i])
		small = myArray[i];
	    }
	  cout << endl;
	  //print the reverse array
	  cout << "Array values reverse are: ";
	  for (int i = 0; i < size; i++)
	    {
	      cout << myArray[size-1-i];
	      if (i!=size-1)
		cout << ", ";
	    }
	  cout << endl;
	  cout << "The largest array value is: " << large << endl;
	  cout << "The smallest array value is: " << small << endl;
	}
      return 0;
    }
}
