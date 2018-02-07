/****

P1: Median and array reversal

****/

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
