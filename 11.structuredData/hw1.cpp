#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct EmployeePay {
	string name;
	int empNum;
	double payRate;
	double hours;
	double grossPay;
};

int main() {
	
	EmployeePay employee1 = {"Betty Ross", 141, 18.75};
	EmployeePay employee2 = {"Jill Sandburg", 142, 17.50};
	
	cout << setprecision(2) << fixed << showpoint;
	
	// Calculate pay for employee1
	cout << "Name: " << employee1.name << endl;
	
	cout << "Employee Number: " << employee1.empNum << endl;
	cout << "Enter the hours worked by this employee: ";
	cin >> employee1.hours;
	
	employee1.grossPay = employee1.hours * employee1.payRate;
	cout << "Gross pay: " << employee1.grossPay << endl << endl;
	
	// Calculate pay for employee2
	cout << "Name: " << employee2.name << endl;
	
	cout << "Employee Number: " << employee2.empNum << endl;
	cout << "Enter the hours worked by this employee: ";
	cin >> employee2.hours;
	
	employee2.grossPay = employee2.hours * employee2.payRate;
	cout << "Gross pay: " << employee2.grossPay << endl << endl;
	
	return 0;
}


