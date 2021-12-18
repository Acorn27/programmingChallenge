/*
Write a program that can be used to gather statistical data about the number of movies college students see in a month. The program should perform the following steps:
A) Ask the user how many students were surveyed. An array of integers with this many elements should then be dynamically allocated.
B) Allow the user to enter the number of movies each student saw into the array.
C) Calculate and display the average, median, and mode of the values entered. (Use the functions you wrote in Programming Challenges 8 and 9 to calculate the median and mode.)
Input Validation: Do not accept negative numbers for in
*/

#include <iostream>
#include <iomanip>
using namespace std;

// fill pointer
void fillPtr(int* ptr, const int size) {
	int moviesNumber;
	cout << "\nEnter number of movies each students saw:\n";
	for (int index = 0; index < size; index++) {
		cout << "Student #" << index + 1 << ": ";
		do {
			if (!(cin >> moviesNumber)) {
				cout << "Please enter numbers only;\n";
			}
			else if (moviesNumber < 0) {
				cout << "Number of movies watched can not be negative.\n";
			}
			else {
				ptr[index] = moviesNumber;
				break;
			}
		} while (true);
	}

}

// todo:  find average functions
double findAverage(const int* ptr, const int size) {
	double total = 0;
	for (int index = 0; index < size; index++) {
		total += ptr[index];
	}

	return (total / size);
}


// todo: selection sort
int* selectionSort(int* ptr, const int size) {
	for (int start = 0; start < size - 1; start++) {
		int minIndex = start;
		int minValue = ptr[start];
		for (int index = start + 1; index < size; index++) {
			if (minValue > ptr[index]) {
				minValue = ptr[index];
				minIndex = index;
			}
		}
		ptr[minIndex] = ptr[start];
		ptr[start] = minValue;
	}
	cout << "\nArray in ascending order: \n";
	for (int index = 0; index < size; index++) {
		cout << ptr[index] << " ";
	}
	return (ptr);
}
// todo: find median functions, need selection sort in order to find median
double findMedian(int* ptr, const int size) {
	ptr = selectionSort(ptr, size);
	// display sorted array for debug 
	cout << endl;
	double median;
	if (size % 2 != 0) {
		median = ptr[(size - 1) / 2];
	}
	else {
		median =(double((ptr[size / 2])) + ptr[(size / 2) - 1]) / 2;
	}
	return median;
}

// todo: find mode functions
int findMode(int* ptr, const int size) {
	int mostFrequency = 1;
	int mode = -1;
	for (int start = 0; start < size - 1; start++) {
		int sample = ptr[start];
		if (sample == -1) { continue; };
		int sampleFrequency = 1;
		for (int index = start + 1; index < size; index++) {
			if (sample == ptr[index]) {
				sampleFrequency++;
				ptr[index] = -1;
			}
		}
		if (sampleFrequency > mostFrequency) {
			mode = sample;
			mostFrequency = sampleFrequency;
		}
	}

	return (mode);
}


int main() {

	// get number of students were surveyed
	int participantsNumber;
	do {
		cout << "How many students were surveyed: ";
		if (!(cin >> participantsNumber)) {
			cout << "Please enter number only.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (participantsNumber < 0) {
			cout << "Please enter positive numbers only.\n";
		}
		else {
			break;
		}
	} while (true);

	int* ptr = new int[participantsNumber];
	// call fill ptr functino
	fillPtr(ptr, participantsNumber);


	// call average fucntion
	double average;
	average = findAverage(ptr, participantsNumber);

	// call median functions
	double median;
	median = findMedian(ptr, participantsNumber);

	// call mode functions
	int mode;
	mode = findMode(ptr, participantsNumber);

	cout << "\nAverage is: " << average << endl;
	cout << "Median is: " << median << endl;
	if (mode == -1) {
		cout << "Mode is: None\n";
	}
	else {
		cout << "Mode is: " << setprecision(2) << fixed << mode << endl;
	}

	// Notify done and terminate program
	cout << "\nDone\n";
	return 0;
	
	delete [] ptr;
	ptr = nullptr;


}