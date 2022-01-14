/*
Write a program that uses a structure to store the following data on a company division:
Division Name (such as East, West, North, or South)
First-Quarter Sales
Second-Quarter Sales
Third-Quarter Sales
Fourth-Quarter Sales
Total Annual Sales
Average Quarterly Sales
The program should use four variables of this structure. Each variable should represent one 
of the following corporate divisions: East, West, North, and South. The user should be asked 
for the four quarters’ sales figures for each division. Each division’s total and average 
sales should be calculated and stored in the appropriate member of each structure variable. 
These figures should then be displayed on the screen.
Input Validation: Do not accept negative numbers for any sales figures.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int DIVISION_TOTAL = 4;
string DIVISION_NAME[DIVISION_TOTAL] {"East", "West", "North", "South"};

// structure to hold company data
struct CompanyData {
	
	string divisionName;
	double firstSale,			// first-quarter sales, second quarter sales,...
				 secondSale,
				 thirdSale,
				 fourthSale;
	double total;					// total anual sale
	double average;
	
};

// get sale data from user's input
void getSale(CompanyData* c) {
	
	cout << "First-Quarter Sales: ";
	cin >> c->firstSale;
	cout << "Second-Quarter Sales: ";
	cin >> c->secondSale;
	cout << "Third-Quarter Sales: ";
	cin >> c->thirdSale;
	cout << "Fourth-Quarter Sales: ";
	cin >> c->fourthSale;
  // calculate total
	c->total = c->firstSale + c->secondSale + c->thirdSale + c->fourthSale;
	c->average = c->total / 4;
	
}

void showData(CompanyData* c) {
	
	cout << "Total Annual Sale: " << c->total << endl;
	cout << "Average Quarterly Sale: "  << c->average << endl;
	
}

int main() {
	
	// four companyData variable for East, West, North, and South
	CompanyData company[DIVISION_TOTAL];
	
	for (int i = 0; i < DIVISION_TOTAL; i++) {
		cout << "\nEnter information for " << DIVISION_NAME[i] << " division\n";
		company[i].divisionName = DIVISION_NAME[i];
		getSale(&company[i]);
	}
	
	for (int i = 0; i < DIVISION_TOTAL; i++) {
		cout << endl << DIVISION_NAME[i] << " division Data";
		showData(&company[i]);
	}
	
	return 0;
	
}