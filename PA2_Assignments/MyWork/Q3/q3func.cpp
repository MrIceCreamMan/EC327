#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;



int DataToFile(const char *filename, int N, int M)
{
  srand(time(0));

  ofstream output;
  output.open("numbers.txt");
  //open output file stream

  for(int i = 0; i < N; i++)
    {
      int j = rand() % (M+1);
      //M is inlcusive
      output << j << endl;
    }
  output.close();
  //check if the file just created can be opened
  ifstream input;
  input.open("numbers.txt");
  if (input.fail())
    return 1;
  else
    return 0;
}

int DataFromFile(const char *filename, int myArray[], int& size)
{
  ifstream input;
  input.open(filename);
  //check if file exits and can be opened
  if (input.fail())
    return 1;
  size = 0;
  //read file to array
  while(!input.eof())
    {
        input >> *(myArray+size);
	size = size + 1;
    }
  size = size - 1;
  input.close();
  return 0;
}
