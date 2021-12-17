/*
In statistics, when a set of values is sorted in ascending or descending order, 
its median is the middle value. If the set contains an even number of values, 
the median is the mean, or average, of the two middle values. 
Write a function that accepts as arguments the following:
  A) An array of integers
  B) An integer that indicates the number of elements in the array
The function should determine the median of the array. 
This value should be returned as a double. (Assume the values in the array are already sorted.)
Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// ascending selection sort 
void selectionSort(int* ptr, const int size ) {
	for (int start = 0; start < size - 1; start++ ) {
		int minValue = ptr[start];
		int minIndex = start;
		for (int index = start + 1; index < size; index++) {
			if (minValue > ptr[index]) {
				minValue = ptr[index];
				minIndex = index;
			}
		}
		ptr[minIndex] = ptr[start];
		ptr[start] = minValue;

	}
}

// return median
double returnMedian(const int* ptr, const int size) {
	double median;
	if (size%2 != 0) {
		median = ptr[(size - 1) / 2];
	} else {
		median = (double(ptr[size/2]) + ptr[(size/2) -1]) / 2;
	}
	
	return median;
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
	
	// sorting pointer
	selectionSort(ptr, size);
	
  // display sort pointer
	cout << "Sorted arry: ";
	displayPtr(ptr, size);
	
	double median;
	median = returnMedian(ptr, size);
	cout << "\nMedian of the enter array is: " << setprecision(2) << fixed << median << endl;

  delete [] ptr;
  ptr = nullptr;	
	return 0;
	
	
	
} 