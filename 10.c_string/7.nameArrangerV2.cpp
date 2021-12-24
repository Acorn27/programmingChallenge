#include <iostream>
#include <cstring>
using namespace std;

const int LENGTH = 100;

int main() {
	
	char first[LENGTH], middle[LENGTH], last[LENGTH], fullName[LENGTH];
	
	cout << "Enter your name: ";
	cin >> first >> middle >> last;
	
	strcat(fullName, last);
	strcat(fullName, ", ");
	strcat(fullName, first);
	strcat(fullName, " ");
	strcat(fullName, middle);
	
	cout << "Your full name: " << fullName << endl;
	return 0;
}