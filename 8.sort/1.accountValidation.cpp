/*
Program: Charge Account validation
this program used to validate account number
enter by user by checking a list stored in a vector
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<int> accoutNumber{5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
	
	int userAccountNum;
	cout << "Enter your checking account number: ";
	cin >> userAccountNum;
	
	bool isValid = false;
	for (int sample : accoutNumber) {
		if (userAccountNum == sample) {
			isValid = true;
			break;
		}
	}
	
	if (isValid) {
		cout << "\nAuthorized transaction!\n";
	} else {
		cout << "\nInvalid account number!\n";
	}
	
	cout << "\nDone!\n";
	return 0;
}
