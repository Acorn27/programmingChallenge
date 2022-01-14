/*
Write a program that uses a structure to store the following weather data for a particular month:
Total Rainfall
High Temperature
Low Temperature
Average Temperature
The program should have an array of 12 structures to hold weather data for an entire year. 
When the program runs, it should ask the user to enter data for each month. 
(The average temperature should be calculated.) Once the data are entered for all the months, 
the program should calculate and display the average monthly rainfall, the total rainfall for the 
year, the highest and lowest temperatures for the year (and the months they occurred in), 
and the average of all the monthly average temperatures.
Input Validation: Only accept temperatures within the range between –100 and +140 degrees Fahrenheit.
VideoNote 11.3: 
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum {LOWER_BOUND = -100, UPPER_BOUND = 140};
const int MONTH_COUNT = 12;
const string monthName[MONTH_COUNT] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

struct WeatherData {
	
	double total,					//total rainfall in month
	       highTemp,			// highest temperature in month
				 lowTemp,				// lowest temperature in month
				 average;				// average temperature in month
	
};

struct Report {
	
	double yearAverage,		// average monthly rainfall for anual
	       yearTotal,			// total rainfall for the year
	       highestTemp,		// highest temperature for the year
				 lowestTemp;		// lowest temperature for the year
	
};


void getData(WeatherData* c) {
	
	cout << "Total Rainfall: ";
	cin >> c->total;
	
	do {
		cout << "High Temperature: ";
	  cin >> c->highTemp;
		if ((c->highTemp < LOWER_BOUND) || (c->highTemp > UPPER_BOUND) ){
			cout << "Invalid input!\n";
			cout << "Please enter temperature in range between -100 and +140 degree Fahrenheit only.\n";
		} else {
			break;
		}
	} while (true);
	
	do {
		cout << "Low Temperature: ";
	  cin >> c->lowTemp;
		if ((c->lowTemp < LOWER_BOUND) || (c->lowTemp > UPPER_BOUND)) {
			cout << "Invalid input!\n";
			cout << "Please enter temperature in range between -100 and +140 degree Fahrenheit only\n";
		} else {
			break;
		}
	} while (true);
	
	c->average = (c->lowTemp + c->highTemp) / 2;
	
}

int main() {
	
	WeatherData month[MONTH_COUNT];
	
	// get data for 12 months
	cout << "Enter weather information for this year\n";
	for (int i = 0; i < MONTH_COUNT; i++) {
		cout << "   " <<  monthName[i] << endl;
		getData(&month[i]);
		cout << endl;
	}
	
	// calculate report
	Report finalReport;
	int tempTotal = 0;
	finalReport.yearTotal += month[0].total;
	finalReport.highestTemp = month[0].highTemp;
	finalReport.lowestTemp = month[0].lowTemp;
	int lowestMonth = 0;
	int highestMonth = 0;
	for (int i  = 1; i < MONTH_COUNT; i++) {
		finalReport.yearTotal += month[i].total;
		tempTotal += month[i].average;
		if (finalReport.highestTemp < month[i].highTemp) {
			finalReport.highestTemp = month[i].highTemp;
			highestMonth = i;
		}
		if (finalReport.lowestTemp > month[i].lowTemp) {
			finalReport.lowestTemp = month[i].lowTemp;
			lowestMonth = i;
		}
		finalReport.yearTotal += month[i].total;
	}
	finalReport.yearAverage = finalReport.yearTotal / MONTH_COUNT;
	
	
	// display final report;
	cout << setprecision(2) << fixed << showpoint;
	cout << "Average monthly rainfall: " << finalReport.yearAverage << endl;
	cout << "Total rainfall: " << finalReport.yearTotal << endl;
	cout << "Highest temperature: " << finalReport.highestTemp << ", which occured in " << monthName[highestMonth] << endl;
	cout << "Lowest temperature: " << finalReport.lowestTemp << ", which occured in " << monthName[lowestMonth] << endl;
	cout << "Average monthly temperature " << tempTotal / MONTH_COUNT << endl;
	
	return 0;
	
}