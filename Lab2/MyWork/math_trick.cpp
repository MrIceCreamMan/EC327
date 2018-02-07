#include <iostream>
using namespace std;

int main(){
	int number;
	cout << "Enter number here: ";
	cin >> number;
	int answer = 0;
	answer = (number*2+8)/2 - number;
	cout << "The answer is "<<answer<<endl;
	cout << "Most probably, your answer is 4;)Check with a neighbour!" << endl;
	return 0;
	}
