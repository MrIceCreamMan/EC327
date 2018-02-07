int* reverse(int* intArray, int size){
	for(int i = 0, j = size - 1; i < j; i++, j--){
		//swap intArray[i] with intArray[j]
		int temp = intArray[j];
		intArray[j] = intArray[i];
		intArray[i] = temp;
	}
	
	return intArray;
}

	//you need to write the functionality for this
}
