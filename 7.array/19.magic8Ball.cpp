/*
Program: magic 8 ball
This program retrieve random answer form file 8_ball_responses.txt
which will display a random response to yes or no question
The program should repeat until the user is ready to quit
*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

const string supplementFile = "8_ball_responses.txt";

// To Do : read data from file into vector
// take 2 arguments: vector name and file name
// return bool value

bool readFile(vector<string> &randomResponseList, const string fileName) {
	
  ifstream inputFile(fileName);	
	if (!inputFile) {
		cout << " Error opening " << fileName << endl;
		return false;
	} else {
		cout << fileName << " has been opened successfully" << endl;
	}
	
	string response;
	int count = 0;
	while (!inputFile.eof()) {
		getline(inputFile, response);
		count++;
		randomResponseList.push_back(response);
	}
	
	inputFile.close();
	cout << count << " items has been successfully read from " << fileName << endl;
	return true;
}

// To Do: pick random item from list function
// take one arguments: list
// return string
string pickRandomResponse(const vector<string> randomResponseList) {
	
	int last_element = randomResponseList.size() - 1;
	int random;
	random_device myEngine;
	uniform_int_distribution<int> randomInt(0, last_element);
	random = randomInt(myEngine);
	
	return(randomResponseList[random]);
}

int main() {
	do {
		string idontcare;
		string randomRes
		cout << "Ask me anything you want (enter X to exit): ";
		cin >> idontcare;
		
	}
}