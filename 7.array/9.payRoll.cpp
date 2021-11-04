/*
This program store work pay information. It should create 4 arrays
that associated with each other:
        + emID: store empoyee id number
	+ hours: store employee worked hours( user's input)
	+ payRate: employee pay rate( user's input)
	+ wage: store employee wage(payRate * hours)
Program should display each employee's ID and gross wage at the end
*/

#include <iostream>
#include <vector>
using namespace std;

const vector<string>  emId = { "5658845", "4520125", "7895122", "8777541", "8451277", "1302850", "7580489" };
const int NUMBER_OF_EMPLOYEE = 7;


int main() {
	vector<int> hours;
	vector<double> payRate;
	vector<double> wages;

	// get data
	int hourElement, payRateElement;
	for (int count = 0; count < NUMBER_OF_EMPLOYEE; count++) {
		cout << "Enter information for employee " << emId[count] << ".\n";
		cout << "Hours worked: ";
		cin >> hourElement;
		hours.push_back(hourElement);
		cout << "Pay rate: $";
		cin >> payRateElement;
		payRate.push_back(payRateElement);
		double total = hours[count] * payRate[count];
		wages.push_back(total);
	}

	// display data
	for (int count = 0; count < NUMBER_OF_EMPLOYEE; count++) {
		cout << "\nEmployee " << emId[count] << ": $" << wages[count] << endl;
	}

	// notify and terminate program
	cout << "\nDone.\n";
	return 0;
}
