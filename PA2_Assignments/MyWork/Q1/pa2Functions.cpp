#include <iostream>
#include <typeinfo>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "pa2Functions.h"
using namespace std;

extern const int ENTRIES;
extern ofstream* mystream;

void initiallize()
{
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2015" << endl;
  cout << "Programming Assignment 2" << endl;
  cout << "Value of Entries is: "<< ENTRIES << endl;
  return;
}

bool checkCode(char incode)
{
  char Array[] = {'F','f','B','b','R','r','D','d','L','l','N','n','I','i','O','o','Q','q'};
  int count = 0;
  //compare every element in the array to see if the code is valid
  for (int i = 0; i < 18; i++)
    if (Array[i]==incode)
      count++;
  if (count==1)
    return true;
  else
    return false;
}

//write data to file
void writeDataToFile(const char * filename)
{
  mystream->open(filename);  
}
//read data from file
//i copied main function here
//it is huge
//i know it's hard to take a look at
//so just dont look at it, but  try to run it
//i spent hours to make it work
void readDataFromFile(const char *filename)
{
  char incode;
  ifstream input(filename);
  bool isQ = false;
  while (!input.eof())
    {
      input >> incode;
      if (input.eof())
	break;
      while (!checkCode(incode))
	{
	  cout <<"Invalid command code" << endl;
	  (*mystream) <<"Invalid command code" << endl;
	  input.clear();
	  input >> incode;
	}
      if (incode=='F'||incode=='f')
	{
	  int factor,inpara;
	  input >> inpara;
	  factor = factorial(inpara);
	  cout << "factorial(" << inpara << ") = " << factor << endl;
	  (*mystream) << "factorial(" << inpara << ") = " << factor << endl;
	}
      else if (incode=='B'||incode=='b')
	{
	  int fib,inpara;
	  input >> inpara;
	  fib = fibonacci(inpara);
	  cout << "fibonacci(" << inpara << ") = " << fib << endl;
	  (*mystream) << "fibonacci(" << inpara << ") = " << fib << endl;
	}
      else if (incode=='R'||incode=='r')
	{
	  double first,last,delta;
	  double result;
	  input >> first >> last >> delta;
	  if ((first > last)||(delta<=0))
	    {
	      cout << "No computation needed." << endl;
	      (*mystream) << "No computation needed." << endl;
	    }
	  else
	    {
	      int count=0;
	      for (double i = first; i < last+delta; i=i+delta)
		{
		  count = count + 1;
		  if (count>10)
		    break;
		  if (i>last)
		    {
		      result = findSqrtValue(last);
		      std::cout.precision(4);
		      (*mystream).precision(4);
		      cout << "Square root of " << last << " = ";
		      cout << fixed << result << endl;
		      (*mystream) << "Square root of " << last << " = ";
		      (*mystream)<< fixed <<result << endl;
		      cout.unsetf(std::ios::floatfield);
		      std::cout.precision(10);
		      (*mystream).unsetf(std::ios::floatfield);
		      (*mystream).precision(10);
		      break;
		    }
		  else
		    {
		      result = findSqrtValue(i);
		      std::cout.precision(4);
		      (*mystream).precision(4);
		      cout << "Square root of " << i << " = ";
		      cout << fixed << result << endl;
		      (*mystream) << "Square root of " << i << " = ";
		      (*mystream) << fixed << result << endl;
		      cout.unsetf(std::ios::floatfield);
		      std::cout.precision(10);
		      (*mystream).unsetf(std::ios::floatfield);
		      (*mystream).precision(10);
		    }
		}
	    }
	}
      else if (incode=='D'||incode=='d')
	{
	  int first,last;
	  input >> first >> last;
	  if (first > last)
	    {
	      cout << "No computation needed." << endl;
	      (*mystream) << "No computation needed." << endl;
	    }
	  else
	    {
	      int count=0;
	      for (double i = first; i < last+2; i=i+2)
		{
		  count = count + 1;
		  if (count>10)
		    break;
		  int result = findNextOddValue(i);
		  cout << result;
		  (*mystream) << result;
		  if (i < last&&count < 10)
		    {
		      cout << ", ";
		      (*mystream) << ", ";
		    }
		}
	      cout << endl;
	      (*mystream) << endl;
	    }
	}      
      else if (incode=='L'||incode=='l')
	{
	  double first,last,delta;
	  double result;
	  input >> first >> last >> delta;
	  if ((first > last)||(delta<=0))
	    {
	      cout << "No computation needed." << endl;
	      (*mystream) << "No computation needed." << endl;
	    }
	  else
	    {
	      int count=0;
	      for (double i = first; i < last+delta; i=i+delta)
		{
		  count = count + 1;
		  std::cout.precision(4);
		  (*mystream).precision(4);
		  if (count>10)
		    break;
		  if (i>last)
		    {
		      result = naturalLog(last);
		      cout << "Natural Log of " << last << " = ";
		      cout << fixed << result << endl;
		      (*mystream) << "Natural Log of " << last << " = ";
		      cout << fixed << result << endl;
		      cout.unsetf(std::ios::floatfield);
		      std::cout.precision(10);
		      (*mystream).unsetf(std::ios::floatfield);
		      (*mystream).precision(10);
		      break;
		    }
		  else
		    {
		      result = naturalLog(i);
		      cout << "Natural Log of " << i << " = ";
		      cout << fixed << result << endl;
		      (*mystream) << "Natural Log of " << i << " = ";
		      (*mystream) << fixed << result << endl;
		      cout.unsetf(std::ios::floatfield);
		      std::cout.precision(10);
		      (*mystream).unsetf(std::ios::floatfield);
		      (*mystream).precision(10);
		    }
		}
	    }
	}
      else if (incode=='N'||incode=='n')
	{
	  double first,last,delta;
	  double result;
	  input >> first >> last >> delta;
	  if ((first > last)||(delta<=0))
	    {
	      cout << "No computation needed." << endl;
	      (*mystream) << "No computation needed." << endl;
	    }
	  else
	    {
	      int count=0;
	      for (double i = first; i < last+delta; i=i+delta)
		{
		  count = count + 1;
		  std::cout.precision(4);
		  (*mystream).precision(4);
		  if (count>10)
		    break;
		  if (i>last)
		    {
		      result = findNyanCatValue(last);
		      cout << "NyanCat value of " << last << " = ";
		      cout << fixed << result << endl;
		      (*mystream) << "NyanCat value of " << last << " = ";
		      (*mystream) << fixed << result << endl;
		      cout.unsetf(std::ios::floatfield);
		      std::cout.precision(10);
		      (*mystream).unsetf(std::ios::floatfield);
		      (*mystream).precision(10);
		      break;
		    }
		  else
		    {
		      result = findNyanCatValue(i);
		      cout << "NyanCat value of " << i << " = ";
		      cout << fixed << result << endl;
		      (*mystream) << "NyanCat value of " << i << " = ";
		      (*mystream) << fixed << result << endl;
		      cout.unsetf(std::ios::floatfield);
		      std::cout.precision(10);
		      (*mystream).unsetf(std::ios::floatfield);
		      (*mystream).precision(10);
		    }
		}
	    }
	}
      else if (incode=='I'||incode=='i')
	{
	  string mystr;
	  cin >> mystr;
	  readDataFromFile(mystr.c_str());
	}
      else if (incode=='O'||incode=='o')
	{
	  string mystr;
	  cin >> mystr;
	  writeDataToFile(mystr.c_str());
	}
      else if (incode=='Q'||incode=='q')
	{
	  isQ = true;
	}
      if (input.eof()||isQ)
	{
	  break;     
	  input.close();
	  return;
	}
    }
}
//return some strange value
double findNyanCatValue(double para)
{
  double result;
  double expNum = pow(6,para);
  result = (2*para) + (para*expNum);
  return result;
}
//return factorial value
int factorial(int para)
{
  int product = 1;
  for (int i = 1; i <= para; i++)
     {
       product = product * i;
     }
  return product;
}
//return fabonacci number
int fibonacci(int para)
{
  int first = 0;
  int last = 1;
  if (para == 0)
    return first;
  if (para == 1)
    return last;
  int temp;
  for (int i = 1; i < para; i++)
    {
      temp = last;
      last = last + first;
      first = temp;
    }
  return last;
}
//this is for square root
double findSqrtValue(double para)
{
  return sqrt(para);
}
//return natural log
double naturalLog(double para)
{
  return log(para);
}
//very simple function
int findNextOddValue(int para)
{
  if (para%2)
    return para;
  else
    return (para+1);
}
