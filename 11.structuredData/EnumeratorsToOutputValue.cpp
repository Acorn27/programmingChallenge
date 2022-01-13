#include <iostream>
#include <iomanip>
using namespace std;

enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};

string displayName(int d) {
	
	string str;
	
	switch (d) 
	{
		case 0 : str = "Monday";
		         break;
		case 1 : str = "Tuesday";
		         break;
		case 2 : str = "Wednesday";
		         break;
		case 3 : str = "Thursday";
		         break;
		case 4 : str = "Friday";
		         break;
	}
	
	return str;
}

int main() {
	
	const int NUM_DAY = 5;
	double sale[NUM_DAY];
	double total = 0;
	Day workDay;
	
	for (workDay = MONDAY; workDay <= FRIDAY; workDay = static_cast<Day>(workDay + 1)) {
		
		cout << "Enter the sale for day "
		     << displayName(workDay)
				 << ": ";
		cin >> sale[workDay];
		total += sale[workDay];
	}
	
	cout << setprecision(2) << fixed << showpoint;
	cout << "The total sale are: $" << total;
	
	return 0;
	
}