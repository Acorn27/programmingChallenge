/*
This program is used to keep track of weather condition in 
three-month summer season. store the information in a 2-dimemsion
array that has 3 rows, each row has 30 columns. The program should:
  +read data from the a file names RainOrShine.txt
  +display number of rainy, sunny, cloudy day in each month and whole period
  +display month that has largest rainy days
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int NUMBER_OF_MONTHS = 3,
          NUMBER_OF_DAYS = 30;
					
const string monthName[3] = {"June", "July", "August"};

void retrieveData(char[][NUMBER_OF_DAYS], string);
void displayStats(char[][NUMBER_OF_DAYS], int);
void displayStatWholePeriod(char[][NUMBER_OF_DAYS]);
void compareRainnyDay(char[][NUMBER_OF_DAYS]);

int main(){
  // 2 dimensional array: row to store number of months, column to store number of days
  char weatherRecord[NUMBER_OF_MONTHS][NUMBER_OF_DAYS];

  // get data from file
  retrieveData(weatherRecord,"RainOrShine.txt");

  //display june, july, august statistic
  displayStats(weatherRecord, 0);
	displayStats(weatherRecord, 1);
	displayStats(weatherRecord, 2);
	displayStatWholePeriod(weatherRecord);

  // display the month that has most rainny days
	compareRainnyDay(weatherRecord);
	
  cout << "\nDone\n";
 return 0;
}

void retrieveData(char array[NUMBER_OF_MONTHS][NUMBER_OF_DAYS], string fileName) {
  ifstream inputFile(fileName);
  for (int month = 0; month < NUMBER_OF_MONTHS; month++) {
    for (int day = 0; day < NUMBER_OF_DAYS; day++) {
	    inputFile >> array[month][day];
    }
  }
  inputFile.close();	
}

void displayStats(char array[NUMBER_OF_MONTHS][NUMBER_OF_DAYS], int index) {
	int rainnyDay = 0,
	    cloudyDay = 0,
			sunnyDay = 0;
	int index;
  for (int day = 0; day < NUMBER_OF_DAYS; day++) {
    if (array[index][day] == 'R') {
			rainnyDay++;
		} else if (array[index][day] == 'C') {
			cloudyDay++;
		} else {
			sunnyDay++;
		}
	}
	
	// display stat
	cout << "Rainy days in " << monthName[index] << ": " << rainnyDay << endl;
  cout << "cloudy days in " << monthName[index] << ": " << cloudyDay << endl;
	cout << "Sunny days in " << monthName[index] << ": " << sunnyDay << endl << endl;
}

void displayStatWholePeriod(char array[NUMBER_OF_MONTHS][NUMBER_OF_DAYS]) {
		int rainnyDay = 0,
	      cloudyDay = 0,
			  sunnyDay = 0;
	for (int month = 0; month < NUMBER_OF_MONTHS; month++) {
		for (int day = 0; day < NUMBER_OF_DAYS; day++) {
			if (array[month][day] == 'R') {
			  rainnyDay++;
		  } else if (array[month][day] == 'C') {
			  cloudyDay++;
		  } else if (array[month][day] = 'S') {
			  sunnyDay++;
		  }
		}
	}
	cout << "Rainy days in a whole period: " << rainnyDay << endl;
  cout << "cloudy days in a whole period: " << cloudyDay << endl;
	cout << "Sunny days in a whole period: " << sunnyDay << endl << endl;
}

void compareRainnyDay(char array[][NUMBER_OF_DAYS]) {
	int juneRainnyDays = 0,
	    julyRainnyDays = 0,
			augustRainnyDays = 0;
	for (int day = 0; day < NUMBER_OF_DAYS; day++) {
		if (array[0][day] == 'R') {
			 juneRainnyDays++;
		}
	}
	for (int day = 0; day < NUMBER_OF_DAYS; day++) {
		if (array[1][day] == 'R') {
			julyRainnyDays++;
		}
	}
	for (int day = 0; day < NUMBER_OF_DAYS; day++) {
		if (array[2][day] == 'R') {
			augustRainnyDays++;
		}
	}
	if (juneRainnyDays >= julyRainnyDays && juneRainnyDays >= augustRainnyDays) {
		cout << "June has the largest number of rainy days.\n";
	} else if (julyRainnyDays > juneRainnyDays && julyRainnyDays > augustRainnyDays) {
		cout << "July has the largest number of rainny days.\n";
	} else {
		cout << "August has the largest number of rainny days\n";
	}
}
