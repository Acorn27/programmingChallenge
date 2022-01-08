#include <iostream>
#include <iomanip>
using namespace std;

struct PayInfo {
	int hour;
	double payRate;
};

int main() {
	
	const int NUM_WORKERS = 3;
	PayInfo worker[NUM_WORKERS];
	// Initialized array of structure
	// PayInfo worker[NUM_WORKERS] = {{10, 9.75}, {15, 8.62}, {40, 15.65}};
	
	for (int i = 0; i < NUM_WORKERS; i++) {
		
		cout << "Enter information for worker#" << i + 1 << endl;
		cout << "Hours worked: ";
		cin >> worker[i].hour;
		cout << "Pay rate: ";
		cin >> worker[i].payRate;
		cout << endl;
	}
	
	cout << "Gross pay for employee\n";
	for (int i = 0; i < NUM_WORKERS; i++) {
		double grossPay;
		grossPay = worker[i].hour * worker[i].payRate;
		cout << "Worker #" << i + 1 << ": $" << grossPay << endl;
	}
	
	return 0;
}