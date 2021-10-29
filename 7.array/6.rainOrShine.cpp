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

void retrieveData(char[][NUMBER_OF_DAYS]);
void displayStats(char[][NUMBER_OF_DAYS], string);
void displayStatWholePeriod(char[][NUMBER_OF_DAYS]);
void compareRainnyDay(char[][NUMBER_OF_DAYS]);

ifstream inputFile("RainOrShine.txt");

int main(){
  // create 2 dimension array to store weather information
  char weatherRecord[NUMBER_OF_MONTHS][NUMBER_OF_DAYS];

  // retrieve data from file to inputFile
  retrieveData(weatherRecord);

  //display june, july, august statistic
  displayStats(weatherRecord, "June");
	displayStats(weatherRecord, "July");
	displayStats(weatherRecord, "Agust");
	displayStatWholePeriod(weatherRecord);

  // display the month that has most rainny days
	compareRainnyDay(weatherRecord);
	
	
  // notify and terminate program
  inputFile.close();
  cout << "\nDone\n";
 return 0;
}

void retrieveData(char array[NUMBER_OF_MONTHS][NUMBER_OF_DAYS]) {
  char byte = 0;
  for (int month = 0; month < NUMBER_OF_MONTHS; month++) {
    for (int day = 0; day < NUMBER_OF_DAYS; day++) {
      inputFile.get(byte);
			if (byte == '\n') {inputFile.get(byte);}
      array[month][day] = byte;
    }
  } 
}

void displayStats(char array[NUMBER_OF_MONTHS][NUMBER_OF_DAYS],string monthName) {
	int rainnyDay = 0,
	    cloudyDay = 0,
			sunnyDay = 0;
	int index;
	if (monthName == "June") {
		index = 0;
	} else if (monthName == "July") {
		index = 1;
	} else {
		index = 2;
	}
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
	cout << "Rainy days in " << monthName << ": " << rainnyDay << endl;
  cout << "cloudy days in " << monthName << ": " << cloudyDay << endl;
	cout << "Sunny days in " << monthName << ": " << sunnyDay << endl << endl;
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
