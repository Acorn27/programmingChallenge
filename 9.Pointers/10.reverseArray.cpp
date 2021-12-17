/*
Write a function that accepts an int array and the array’s size as arguments. 
The function should create a copy of the array, 
except that the element values should be reversed in the copy. 
The function should return a pointer to the new array. 
Demonstrate the function in a complete program.
*/

#include <iostream>
using namespace std;

// return a reverse coppied of an array
int* reverseCoppy(int* ptr, const int size) {
	int* coppiedPtr = nullptr;
	coppiedPtr = new int[size];
	int j = size - 1;
	for (int index = 0; index < size; index++, j--) {
		coppiedPtr[index] = ptr[j];
	}
	return coppiedPtr;
}

// display sorted ptr
void displayPtr(const int* ptr, const int size) {
	for (int index = 0; index < size; index++ ) {
		cout << ptr[index] << " ";
	}
	cout << endl;
}

int main() {
	
	// number of elements in array
	int size;
	// array notation 
	int* ptr = nullptr;
	
	// fill array
	do {
		cout << "\nEnter number of elements: ";
		if (!(cin >> size)) {
			cout << "Please enter integer only.\n";
		} else if (size <= 0) {
			cout << "Please enter number greater than 0\n";
		} else {
			ptr = new int[size];
			cout << "\nEnter value for: \n";
			for (int index = 0; index < size; index++) {
				cout << "Element #" << index + 1 << ": ";
				cin >> ptr[index];
			}
			break;
		}
	} while (true);
	
	int* reversePtr = reverseCoppy(ptr, size);
	cout << "Reversed array: ";
	displayPtr(reversePtr,size);
	
	
	delete [] ptr;
	ptr = nullptr;
	
	return 0;
}