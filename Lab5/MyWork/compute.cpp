/****

P1: Median and array reversal

****/
#include "compute.h"
#include <iostream>
using namespace std;

/*****************************************
magic and findMedian functions go here
************************************/

/*****************************************
printStats funciton provided to print result
************************************/

void printStats(int input[], int size, double median, double result_magic[], int result_count){

    cout << "Input: ";
    for(int i = 0; i < size; i++) {
        cout << input[i];
        if (i != size -1)
            cout << ", ";
    }
    cout << endl;
    cout << "Median: " << median << endl;
    cout << "Magic result: ";
    for(int i = 0; i < result_count; i++) {
        cout << result_magic[i];
        if (i != result_count -1)
            cout << ", ";
    }
    cout << endl;
    cout << endl;
}

double findMedian(int input[], int size)
{
  int med1,med2;
  double median;
  if (size % 2)
    {
      med1 = (size+1)/2;
      med2 = med1;
    }
  else
    {
      med1 = size/2;
      med2 = med1 + 1;
    }
  //cout << input[med1-1] << input[med2-1] << endl;
  median = static_cast<double>((input[med1-1] + input[med2-1])/2.0);
  //cout << "hello" << median <<endl;
  return median;
}

void magic(int input[], int size, double result_magic[], int& result_size)
{
  int j = size - 1;
  int i = 0;
  result_size = size;
  double median = findMedian(input, size);
  for (i;i<size;i++)
    {
      result_magic[i] = (input[j] - median);
      j = j - 1;
    }
}
