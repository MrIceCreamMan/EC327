#include <iostream>
#include <fstream>
using namespace std;
#include "pa2Functions.h"

extern const int ENTRIES = 10;
extern ofstream* mystream = new ofstream();

int main()
{

  initiallize();
  //Print the title, which is a requirment;
  char incode;

  //start an infinite loop until 'quit' is given
  while (true)
    {
      cout << "Please enter command code: ";
      (*mystream) << "Please enter command code: ";
      cin >> incode;
      (*mystream) << incode << endl;
      //if 'o' is given, then file stream is on, and writes on it.
      //if not, writes on nothing

      //check if the command code is valid
      if (checkCode(incode))
	{
	  //do factorial calculation
	  if (incode=='F'||incode=='f')
	    {
	      int factor,inpara;
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      cin >> inpara;
	      (*mystream) << inpara << endl;
	      factor = factorial(inpara);
	      cout << "factorial(" << inpara << ") = " << factor << endl;
	      (*mystream) << "factorial(" << inpara << ") = " << factor << endl;
	    }
	  //return fibanacci number
	  else if (incode=='B'||incode=='b')
	    {
	      int fib,inpara;
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      cin >> inpara;
	      (*mystream) << inpara << endl;
	      fib = fibonacci(inpara);
	      cout << "fibonacci(" << inpara << ") = " << fib << endl;
	      (*mystream) << "fibonacci(" << inpara << ") = " << fib << endl;
	    }
	  //return square root
	  else if (incode=='R'||incode=='r')
	    {
	      double first,last,delta;
	      double result;
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      cin >> first >> last >> delta;
	      (*mystream) <<first<<" "<<last<<" "<<delta<< endl;
	      if ((first > last)||(delta<=0))
		{
		  cout << "No computation needed." << endl;
		  (*mystream) << "No computation needed." << endl;
		}
	      //something about formatting
	      //no comma after the last number, things like that
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
			  (*mystream) << fixed << result << endl;
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
	      //get the inputs
	      int first,last;
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      cin >> first >> last;
	      (*mystream) << first << " " << last << endl;
	      if (first > last)
		{
		  cout << "No computation needed." << endl;
		  (*mystream) << "No computation needed." << endl;
		}
	      //format it, and also writes on the stream when 'o' is called
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
	  //return natural log
	  else if (incode=='L'||incode=='l')
	    {
	      double first,last,delta;
	      double result;
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      cin >> first >> last >> delta;
	      (*mystream) <<first<<" "<<last<<" "<<delta<< endl;
	      if ((first > last)||(delta<=0))
		{
		  cout << "No computation needed." << endl;
		  (*mystream) << "No computation needed." << endl;
		}
	      //same thing with sqaure root.
	      //format to make it beautiful
	      //set precision or not accoding to the instructions
	      //and alse writes on fstream
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
			  (*mystream) << fixed << result << endl;
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
			  cout << fixed <<result << endl;
			  (*mystream) << "Natural Log of " << i << " = ";
			  (*mystream)  << fixed << result << endl;
			  cout.unsetf(std::ios::floatfield);
			  std::cout.precision(10);
			  (*mystream).unsetf(std::ios::floatfield);
			  (*mystream).precision(10);
			}
		    }
		}
	    }
	  //return NyanCatValue the magic number
	  //and format, and fstream
	  else if (incode=='N'||incode=='n')
	    {
	      double first,last,delta;
	      double result;
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      cin >> first >> last >> delta;
	      (*mystream) <<first<<" "<<last<<" "<<delta<< endl;
	      if ((first > last)||(delta<=0))
		{
		  cout << "No computation needed." << endl;
		  (*mystream) << "No computation needed." << endl;
		}
	      //comment is good practice
	      //from the symmetry, i can tell this one is the same thing as 
	      //the previous three.
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
			  (*mystream) <<fixed << result << endl;
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
	  //i spent a lot of time on this
	  //it's is file io
	  //i should have learned fstream pointers early
	  //what i did was copy paste main function to this function
	  //which makes this function extremely long
	  else if (incode=='I'||incode=='i')
	    {
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      string mystr;
	      cin >> mystr;
	      (*mystream) << mystr << endl;
	      readDataFromFile(mystr.c_str());
	    }
	  //i learned ofstream pointer from julian
	  //so i did not copy paste main function again to this function
	  //but i am sure there are many people did that
	  else if (incode=='O'||incode=='o')
	    {
	      cout << "Please enter command parameters: ";
	      (*mystream) << "Please enter command parameters: ";
	      string mystr;
	      cin >> mystr;
	      (*mystream) << mystr << endl;
	      writeDataToFile(mystr.c_str());
	    }
	  //my favorite command
	  else if (incode=='Q'||incode=='q')
	    {
	      return 0;
	    }
	}
      else 
	{
	  //tell user it's wrong, retype it!!!
	  cout <<"Invalid command code" << endl;
	  (*mystream) <<"Invalid command code" << endl;
	}
    }
}
