#include <iostream>
#include <string>
using namespace std;

struct Date {
	int month;
	int day;
	int year;
};

struct Place {
	
	string address;
	string city;
	string state;
	string zipCode;
};

struct EmployeeInfo {
	string name;
	int employeeNumber;
	Date birthDay;
	Place residence;
};

int main() {
	
	EmployeeInfo manager;
	
	//get manager's name and employee's number;
	cout << "Enter the manager's name: ";
	getline(cin, manager.name);
	cout << "Enter the manager's employee number: ";
	cin >> manager.employeeNumber;
	
	// get manager's birth day
	cout << "Enter Manager date of birth\n";
	cout << "Month: ";
	cin >> manager.birthDay.month;
	cout << "Day: ";
	cin >> manager.birthDay.day;
	cout << "Year: ";
	cin >> manager.birthDay.year;
	
	// get manager's residence information
	cin.ignore();
	cout << "Enter the manager's residence information.\n";
	cout << "Address: ";
	getline(cin,manager.residence.address);
	cout << "City: ";
	getline(cin,manager.residence.city);
	cout << "State: ";
	getline(cin,manager.residence.state);
	cout << "Zip Code: ";
	getline(cin,manager.residence.zipCode);

  // display the information
	cout << "\nHere is the manger's information\n";
	cout << "Name: " << manager.name << endl;
	cout << "Employee ID: " << manager.employeeNumber << endl;
	cout << "Date of birth: "
	     << manager.birthDay.month
			 << "/"
			 << manager.birthDay.day
			 << "/"
			 << manager.birthDay.year
			 << endl;
	cout << "Place of residence: "
	     << manager.residence.address
			 << ", "
			 << manager.residence.city
			 << ", "
			 << manager.residence.state
			 << ", "
			 << manager.residence.zipCode
			 << endl;
	
	
	return 0;
	
	
	
	
	return 0;
	
}