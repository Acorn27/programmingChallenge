/* 
Program: Name Search
this program reads the content of 2 files into 2 vector: GirlNames.txt
and Boynames.txt. Both of them contains popular names 
given to boys na d girl who was born between 200 and 2009
The program should be able to:
  + let user enter a boy's name, a girl's name or both
  +	display a message indicate wether the entered name is popular or not
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const string GIRL_NAMES_FILE = "GirlNames.txt";
const string BOY_NAMES_FILE = "BoyNames.txt";

// To Do: create read file into vector function
// take 2 argument: vector name and file name
// return bool value
bool readFile(vector<string> &namesList, const string fileName) {
	
	ifstream inputFile(fileName);
	string name;
	int count = 0;
	
	if (!inputFile) {
		cout << "Error opening file " << fileName << endl;
		cout << "Please re-run the program and chek for " << fileName;
    cout << " in your current working directory." << endl;
    return false;
	} else {
		cout << fileName << " opening successfully\n";
	}
	
	while (!inputFile.eof()) {
		inputFile >> name;
		count++;
		namesList.push_back(name);
	}
	
	inputFile.close();
	
	cout << count << " items has been read from " << fileName << endl << endl;
	return true;
	
}

// To DO: check popular name function
// take 3 argument: name, boyList, girlList
// return bool value
bool isPopularName(const string name, const vector<string> boyNamesList, const vector<string> girlNamesList) {
	for (string popularName : boyNamesList) {
		if (popularName == name) {
			return true;
		}
	}
	
	for (string popularName : girlNamesList) {
		if (popularName == name) {
			return true;
		}
	}
	
	return false;
	
}

int main() {
  
	vector<string> boyNames;
	vector<string> girlNames;
	
	// To DO: call read file function
	if (readFile(boyNames, BOY_NAMES_FILE) && readFile(girlNames, GIRL_NAMES_FILE)) {
		string name;
	  cout << "Please enter name: ";
	  cin >> name;
		if (isPopularName(name, boyNames, girlNames)) {
			cout << name << " is among the popular names in US\n";
		} else {
			cout << name << " is not among the popular name in US\n";
		}
	}
	
	// Notify and terminate program
	cout << "\nDone!\n";
	return 0;
	
}