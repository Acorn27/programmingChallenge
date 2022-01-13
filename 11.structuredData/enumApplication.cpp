#include <iostream>
using namespace std;

enum water { FREEZING = 32, BOILING = 212};

int main() {
	
	int waterTemp;
	cout << "Enter the current water temperature: ";
	cin >> waterTemp;
	
	if (waterTemp <= FREEZING) {
		cout << "The water is frozen.\n";
	} else if (waterTemp >= BOILING) {
		cout << "The water is boiling\n";
	}
	
	return 0;
	
}