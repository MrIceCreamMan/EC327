#include <iostream>
#include <cmath>
using namespace std;
//return the mean value for an array
float getMean(int myArray[], int size)
{
  float sum = 0;
  for (int i = 0; i < size; i++)
    {
      sum = sum + myArray[i];
    }
  float mean = sum/size;
  return mean;
}
//calculate the standard deviation for an array
float getStdDev(int myArray[], int size)
{
  float mean;
  //calculate mean value first
  mean = getMean(myArray,size);
  float sqsum = 0;
  for (int i = 0; i < size; i++)
    {
      sqsum = sqsum + (mean-myArray[i])*(mean-myArray[i]);
    }
  float std = sqrt(sqsum/size);
  return std;
}


