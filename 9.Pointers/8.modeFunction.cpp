/*
In statistics, the mode of a set of values is the value that occurs most often or with the greatest frequency. 
Write a function that accepts as arguments the following:
A) An array of integers
B) An integer that indicates the number of elements in the array
The function should determine the mode of the array. 
That is, it should determine which value in the array occurs most often. 
The mode is the value the function should return. 
If the array has no mode (none of the values occur more than once), 
the function should return −1. 
(Assume the array will always contain nonnegative values.)
Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
*/

#include <iostream>
using namespace std;

int returnMode(int* ptr, const int size) {
	
	int mode = -1;
	int maxFrequecy = 1;
	for (int start = 0; start < size; start++) {
		int sampleFrequnecy = 1;
    int sample = ptr[start];
		if (sample == -1) {continue;};
		for (int index = start + 1; index < size; index++) {
			if(sample == ptr[index]) {
				sampleFrequnecy++;
				ptr[index] = -1;
			}
		}
		//cout << sample << " has passed compare step\n";
		//cout << sample << " frequency is " << sampleFrequnecy << endl;
		// compare sample frequency with maximum frequency
		if (sampleFrequnecy > maxFrequecy) {
			maxFrequecy = sampleFrequnecy; 
			mode = sample;
			//cout << sample << " has passed the final step\n";
		}
	}
	
	return mode;
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
	
	int mode;
	mode = returnMode(ptr, size);
	cout << "\nMode the entered set is: " << mode << endl;
	
	return 0;
	
	
	
} 