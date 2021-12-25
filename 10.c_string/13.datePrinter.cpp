/*
Write a program that reads a string from the user containing a date 
in the form mm/ dd/yyyy. It should print the date in the form 
March 12, 2018. 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(const string input, const char delim, vector<string> &token) {
	
	int startPos = 0;
	int endPos = input.find(delim);
	
	while (endPos != string::npos) {
		
		string element = input.substr(startPos, endPos - startPos);
		
		token.push_back(element);
		
		startPos = endPos + 1;
		endPos = input.find(delim, startPos);
		
		if (endPos == string::npos) {
			string element = input.substr(startPos, endPos - startPos);
			token.push_back(element);
		}
	}
}

void displayVector(const vector<string> arr) {
	for (int index = 0; index <  arr.size(); index++) {
		cout << index + 1 << ". " << arr[index] << endl;
	}
}

void readableFormat(const vector<string> token) {
  string arr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  
	cout << "Your entered date: ";
  int month = stoi(token[0]);
  cout << arr[month - 1] << " ";
	cout << token[1] << ", ";
	cout << token[2];
}

int main() {
	
	string input;
	cout << "Enter a date in the format (mm/dd/yyyy): ";
	getline(cin, input);
	
	vector<string> token;
	split(input, '/', token);
	
	readableFormat(token);
	
	return 0;
}