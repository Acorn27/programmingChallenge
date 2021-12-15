
/*
Write a program that dynamically allocates an array large enough to hold a userdefined number of test scores. 
Once all the scores are entered, the array should be passed to a function that sorts them in ascending order.
Another function should be called that calculates the average score. 
The program should display the sorted list of scores and averages with appropriate headings.
Use pointer notation rather than array notation whenever possible.
Input Validation: Do not accept negative numbers for test scores.
*/

/*
Note:
+ getline only work with string
+ keyboard buffer does not clear after program exit (there is a probability that it still store '\n' character from last run
+ used pointer as array without allocating memory with NEW can leed to "program has stopped"
+ new syntax getline(cin, varibale, <seperate character>) seperate character used to stop cin from reading the whole input
+ we can used reference with pointer in order to change content of pointer
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// fill pointer function, I used referenced to change both pointer containt
// instead of returning a single pointer
void fillPtr(int* &ptr, string* &name, const int size) {
	cout << "\nEnter Student's Full Name followed by Test score\n";
	cout << "Ex: Chris Hanson-80\n";
	string fullName;
	int score;
	for (int index = 0; index < size; index++) {
		do {
			cout << "Student #" << index + 1 << ": ";
			cin.clear();
			cin.ignore(1000, '\n');
			string firstName, lastName, fullName;
			getline(cin, firstName, ' ');
			getline(cin, lastName, ' ');
			fullName = firstName + ' ' + lastName;
			cin >> score;
			if (score < 0) {
				cout << "Test score entered can not less than 0\n";
			} 
			else {
				ptr[index] = score;
				name[index] = fullName;
				break;
			}
		} while (true);
	}
}

// sort pointer function
void selectionSort(int* &ptr, string* &name, int size) {
	for (int start = 0; start < size - 1; start++) {
		int maxIndex = start;
		int maxValue = ptr[start];
		for (int index = start + 1; index < size; index++) {
			if (ptr[index] > maxValue) {
				maxValue = ptr[index];
				maxIndex = index;
			}
		}

		ptr[maxIndex] = ptr[start];
		ptr[start] = maxValue;
		string temp = name[maxIndex];
		name[maxIndex] = name[start];
		name[start] = temp;
	}

}

// display sorted result: student's name followed by score
void displayPtr(const int* ptr, const string* name, const int size) {
	cout << "\nSorted list of student score\n";
	for (int index = 0; index < size; index++) {
		cout << name[index] << "\t\t" << ptr[index] << endl;
	}
}

//  drop lowest score and calculate average
void displayAverage(int* ptr, const int size) {
	int total = 0;
	for (int index = 1; index < size; index++) {
		total += ptr[index];
	}
	if (size == 1) {
		cout << "\nAverage score of student: " << total << endl;
	}
	else {
		cout << "\nAverage score of student: " << total / (size - 1) << endl;
	}
}


int main() {
	// number of test score
	int testsNumber = 0;
	string* name = nullptr;
	int* ptr = nullptr;

	do {
		cout << "Enter number of test: ";
		if (!(cin >> testsNumber)) {
			cout << "Please enter numbers only!\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (testsNumber <= 0) {
			cout << "Please enter positive number only!\n";
		}
		else {
			break;
		}
	} while (true);

	// pointer point to array
	ptr = new int[testsNumber];

	// declare pointer point to string array
	name = new string[testsNumber];

	// Call filll pointer function
    fillPtr(ptr, name, testsNumber);

	// sort pointer
	selectionSort(ptr, name, testsNumber);

	// display sorted pointer
	displayPtr(ptr, name, testsNumber);

	// display Average
	displayAverage(ptr, testsNumber);


	delete[] ptr;
	delete[] name;
	name = nullptr;
	ptr = nullptr;

	cout << "\nDone\n";
	return 0;
}
