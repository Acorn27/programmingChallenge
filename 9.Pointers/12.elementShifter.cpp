/*
Write a function that accepts an int array and the array’s size as arguments. 
The function should create a new array that is one element larger than the argument array. 
The first element of the new array should be set to 0. 
Element 0 of the argument array should be copied to element 1 of the new array, 
element 1 of the argument array should be copied to element 2 of the new array, 
and so forth. The function should return a pointer to the new array.
*/

#include <iostream>
using namespace std;

//todo : elementShifter function
int* elementShifter(const int* originalArr, const int size) {
	int* modifiedArr = new int[size+1];
	
	modifiedArr[0] = 0;
	for (int index = 0; index < size; index++) {
		modifiedArr[index+1] = originalArr[index];
	}
	
	return modifiedArr;
}
//todo : display array
void displayArr(const int* ptr, const int size) {
	for (int index = 0; index < size; index++) {
		cout << ptr[index] << " ";
	}
	cout << endl;
}

int main() {
	
	// original array
	const int SIZE = 13;
	int originalArr[SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	
	//todo: call elementShifter array
	int* secondArr = elementShifter(originalArr, SIZE);
	
	//Display both array
	cout << "Original Array: ";
	displayArr(originalArr,SIZE);
	cout << "\nModified Array: ";
	displayArr(secondArr, SIZE+1);
	
	delete[] secondArr;
	secondArr = nullptr;
	
	cout << "\nDone\n";
	return 0;
}