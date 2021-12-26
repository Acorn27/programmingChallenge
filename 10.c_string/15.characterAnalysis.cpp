/*
For this programming problem, download the file text.txt. Write a program that reads the file’s contents and determines the following:
• The number of uppercase letters in the file
• The number of lowercase letters in the file
• The number of digits in the file
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void retrieveData(const string fileName, vector<string> &text) {
	
	fstream inputFile(fileName);
	
	if (!inputFile) {
		cout << "Error opening file named " << fileName << endl;
		cout << "Please check your local directory and re-run program.\n";
	} else {
		cout << "Successfully open a file name " << fileName << endl;
		while (!(inputFile.eof())) {
			string line;
			getline(inputFile, line);
			text.push_back(line);
		}
	}
	
	inputFile.close();
}

void displayVector(const vector<string> text) {
	
	cout << "\nFile Contents: \n";
	for (int index = 0; index < text.size(); index++) {
		cout << text[index] << endl;
	}
	
}

void characterAnalysis(const vector<string> text) {
	
	cout << "Characters Analysis:\n";
	
	int uppercase = 0, lowercase = 0, digit = 0;
	for (int i = 0; i < text.size(); i++) {
		
		string str = text[i];
		
		for (int j = 0; j < str.length(); j ++) {
			
			char c = str[j];
			
			if (isupper(c)) {
				uppercase++;
			} else if (islower(c)) {
				lowercase++;
			} else if (isdigit(c)) {
				digit++;
			}
			
		}
	}
	
	cout << "Number of uppercase letters: " << uppercase << endl;
	cout << "Number of lowercase letters: " << lowercase << endl;
	cout << "Number of digit: " << digit << endl;
}

const string FILE_NAME = "Text.txt";

int main() {
	
	vector<string> text;
	
	retrieveData(FILE_NAME, text);
	
	displayVector(text);
	
	characterAnalysis(text);
	
	return 0;
	
}