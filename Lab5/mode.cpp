/****

P2: Mode

****/

#include <iostream>
using namespace std;



/*****************************************
findModes function goes here
************************************/


/*****************************************
printModes funciton provided to print result
************************************/

void printModes(int input[], int size,  int frequency, int result[], int result_count){

    cout << "Input: ";
    for(int i = 0; i < size; i++) {
        cout << input[i];
        if (i != size -1)
            cout << ", ";
    }
    cout << endl;
    cout << "Modes: ";
    for(int i = 0 ; i < result_count; i++) {
        cout << result[i];
        if (i != result_count -1)
            cout << ", ";
    }
    cout << endl;
    cout << "Frequency : " << frequency << endl;;

}
