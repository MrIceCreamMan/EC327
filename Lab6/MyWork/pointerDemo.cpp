#include "print.h"
#include "reverse.h"
#include "bubbleSort.h"
#include <iostream>
using namespace std;

int main(){
	int* list = new int[6];
	
	for (int i = 0; i < 6; i++)
		list[i] = i + 1;
	printArray(list, 6);	
	
	char list2[] = { 'a', 'b', 'c', 'd', 'e'};
	printArray(list2, 6);
	
	int * p = reverse(list, 6);
	char * p2 = reverse(list2, 5);
	
	printArray(p, 6);
	printArray(list, 6);
	printArray(p2, 6);
	printArray(list2, 6);

	int myilist[] = {5,9,4,2,1,6};
	printArray(myilist,6);
	char myclist[] = {'c','p','g','w','i','e'};
	printArray(myclist,6);
	bubbleSort(myilist,6);
	bubbleSort(myclist,6);
	printArray(myilist,6);
	printArray(myclist,6);

	return 0;
}
