/*
Write a function that accepts an int array and the array’s size as arguments. 
The function should create a new array that is twice the size of the argument array. 
The function should copy the contents of the argument array to the new array 
and initialize the unused elements of the second array with 0. 
The function should return a pointer to the new array.
*/

// Note
// array only decay into pointer when it is passed as function argument
// It is ileagal to pass an array into a function that return pointer
// Moreover, it does make sence to create a new array to store data when we
// already has an existed pointer to do that task.

// Proper way
// Crate a function that create a pointer point to array inside that fucntion
// return the pointer 
// in the main function: create another poiner then asign to the created function
// delte that pointer after used;

#include <iostream>
#include <memory>
using namespace std;

void displayArr(const int* ptr, const int size) {
	for (int index = 0; index < size; index++) {
		cout << ptr[index] << " ";
	}
}

int* expandArr(int* ptr, int size) {
	int expandedSize = size * 2;
	int* expandedArr = new int[expandedSize];
	for (int index = 0; index < expandedSize; index++ ) {
		if (index < size) {
			expandedArr[index] = ptr[index];
		} else {
			expandedArr[index] = 0;
		}
	}
	
	return expandedArr;
}

int main() {
	
	// original array
	const int SIZE = 10;
	int arr[SIZE] = {0,1,2,3,4,5,6,7,8,9};
	
	// Treat a function as a pointer
	//displayArr(expandArr(arr, SIZE), SIZE*2);
	
	
	
	// Proper way
	int* doublePtr = expandArr(arr, SIZE);
	
	// display arrays
	cout << "\nOriginal array:\n";
	displayArr(arr, SIZE);
	cout << "\nExpanded array:\n";
	displayArr(doublePtr, SIZE*2);
	
	delete[] doublePtr;
  doublePtr = nullptr;
	
	return 0;
}