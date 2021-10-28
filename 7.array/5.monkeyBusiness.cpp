/*
This program create a two dimensional 3x5 array
where each row represent each monky, each column
represent each day in the week. Then it do the following task:
  + calculate average amount of food eaten per day by the all monkey
  + the least amount of food eaten during the week by any money
  + the greatest amount of food eaten during the week by any monkey
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int NUMBER_OF_MONKEY = 3;
const int	NUMBER_OF_DAY = 5;

void getInformation(int[][NUMBER_OF_DAY], int, int);
float calcaverage(int[][NUMBER_OF_DAY], int, int);
void displayExtreme(int[][NUMBER_OF_DAY], int, int);

int main() {
	// an array to store food eaten information
	int foodEaten[NUMBER_OF_MONKEY][NUMBER_OF_DAY];

	// get array information
	getInformation(foodEaten, NUMBER_OF_MONKEY, NUMBER_OF_DAY);

	float average;
	average = calcaverage(foodEaten, NUMBER_OF_MONKEY, NUMBER_OF_DAY);
	cout << "\nThe average amount of food eaten by three monkey during the week is: " << average << " pounds.\n";

	displayExtreme(foodEaten, NUMBER_OF_MONKEY, NUMBER_OF_DAY);

	cout << "\nDone.\n";
	return 0;
}

void getInformation(int array[][NUMBER_OF_DAY], int monkeyNumbers, int dayNumbers) {
	for (int monkey = 0; monkey < monkeyNumbers; monkey++) {
		for (int day = 0; day < dayNumbers; day++) {
			string dayName;
			switch (day) {
			case 0:
				dayName = "Monday";
				break;
			case 1:
				dayName = "Tuedays";
				break;
			case 2:
				dayName = "Wednesday";
				break;
			case 3:
				dayName = "Thursday";
				break;
			case 4:
				dayName = "Friday";
				break;
			}
			do {
				cout << "Enter amount of food eaten by monkey " << monkey + 1 << " in " << dayName << ": ";
				if (!(cin >> array[monkey][day])) {
					cout << "Please enter number only.\n";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else if (array[monkey][day] < 0) {
					cout << "Number of pound of food eaten can not negate.\n";
				}
				else {
					break;
				}
			} while (true);
		}
		cout << endl;
	}
}

float calcaverage(int array[][NUMBER_OF_DAY], int monkeyNumbers, int dayNumbers) {
	int total = 0;
	for (int monkey = 0; monkey < monkeyNumbers; monkey++) {
		for (int day = 0; day < dayNumbers; day++) {
			total += array[monkey][day];
		}
	}
	int unit;
	unit = monkeyNumbers * dayNumbers;
	return (float(total) / unit);
}

void displayExtreme(int array[][NUMBER_OF_DAY], int monkeyNumbers, int dayNumbers) {
	int highest = 0;
	int lowest = 9999;
	int total = 0;
	for (int monkey = 0; monkey < monkeyNumbers; monkey++) {
		for (int day = 0; day < dayNumbers; day++) {
			total += array[monkey][day];
		}
		(total > highest ? highest = total : highest = highest);
		(total < lowest ? lowest = total : lowest = lowest);
		total = 0;
	}

	cout << "The least amount of food eaten during this week is: " << lowest << " pounds.\n";
	cout << "The greatest amount of food eaten during this week is: " << highest << " pounds.\n";
}