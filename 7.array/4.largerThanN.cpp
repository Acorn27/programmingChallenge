// This program create an iteger function
// that accept three arguments: an array, 
// the size of the array and a number n
// the function should display all the n
// in an array that are greater than number n

#include <iostream>
#include <iomanip>
using namespace std;

void getArray(int[], int);
void greaterFilter(int[], int, int);

int main() {
	
	int size;
	cout << "Enter size of the array: ";
	cin >> size;
	
	int listOfNumbers[size];
	getArray(listOfNumbers, size);
	
	int n;
	cout << "Enter number n: ";
	cin >> n;
	
	greaterFilter(listOfNumbers, size, n);
	
	return 0;
}

void getArray(int array[], int size) {
	for (int pos = 0; pos < size; pos++) {
		cout << "Enter element " << pos + 1 << ": ";
		cin >> array[pos];
	}
}

void greaterFilter(int array[], int size, int number) {
	cout << "Number in array that greater than " << number << " is: ";
	for (int pos = 0; pos < size; pos++) {
		if (array[pos] > number) {
			cout << array[pos] << endl;
		}
	}
}