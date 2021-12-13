/*
Write a program that dynamically allocates an array large enough to hold a userdefined number of test scores. 
Once all the scores are entered, the array should be passed to a function that sorts them in ascending order.
Another function should be called that calculates the average score. 
The program should display the sorted list of scores and averages with appropriate headings.
Use pointer notation rather than array notation whenever possible.
Input Validation: Do not accept negative numbers for test scores.
*/

#include <iostream>
using namespace std;

// fill pointer
int* fillPtr(int* ptr, const int size) {
	for (int index = 0; index < size; index++) {
		do {
			cout << "Enter test score #" << index + 1 << ": ";
			if (!(cin >> ptr[index])) {
				cout << "Please enter numbers only!\n";
			} else if (ptr[index] < 0) {
				cout << "Test score entered can not less than 0\n";
			} else {
				break;
			}
		} while (true);
	}
	
	return (ptr);
}

// sort pointer
int* selectionSort(int* ptr, const int size) {
	for (int start = 0; start < size - 1; start++) {
		int minIndex = start;
		int minValue = ptr[start];
		for (int index = start +1; index < size; index++) {
			if (ptr[index] < minValue) {
				minValue = ptr[index];
				minIndex = index;
			}
		}
		
		ptr[minIndex] = ptr[start];
		ptr[start] = minValue;
	}
	
	return (ptr);
}

// display pointer
void displayPtr(const int* ptr, const int size) {
	for (int index = 0; index < size; index++) {
		cout << ptr[index] << endl;
	}
}

//  drop lowest score and calculate average
void displayAverage(int* ptr, const int size) {
	int total = 0;
	for (int index = 1; index < size; index++) {
		total += ptr[index];
	}
	cout << "\nAverage score of student: " << total / (size - 1) << endl;
}


int main() {
	// number of test score
	int testsNumber = 0;
	int* ptr = nullptr;
	
	do {
		cout << "Enter number of test: ";
		if (!(cin >> testsNumber)) {
			cout << "Please enter numbers only!\n";
		} else if (testsNumber <= 0) {
			cout << "Please enter positive number only!\n";
		} else {
			break;
		}
	} while (true);
	
	// pointer point to array
	ptr = new int[testsNumber];
	
	// Call filll pointer function
	ptr = fillPtr(ptr, testsNumber);
	
	// sort pointer
	ptr = selectionSort(ptr, testsNumber);
	
	// display sorted pointer
	cout << "\nScore list in ascending order: \n";
	displayPtr(ptr, testsNumber);
	
	// display Average
	displayAverage(ptr, testsNumber);

	
	delete [] ptr;
	ptr = nullptr;
	
	cout << "\nDone\n";
	return 0;
}