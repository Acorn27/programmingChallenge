/*
This program will generate  a ramdom 5 elements array,
and let user enter another 5 elements array, then it will compare
the coresponding elements in two array and keep counts the of the 
digits match. This program should display the random number as well as 
the digit match. If all digits match, display that user win the grand prize.
*/

#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;

const int SIZE = 5;

void generateRandomList(vector<int> &randomList) {
	
	random_device myEngine;
	uniform_int_distribution<int> randomInt(0,9);
	
	for (int count = 0; count < SIZE; count++) {
	    int randomNumber = randomInt(myEngine);
		randomList.push_back(randomNumber);
	}
}

void getLUserList(vector<int> &userList) {
	
	string userInput;
	do {
	  cout << "Enter your 5-digits random number: ";
	  cin >> userInput;  
	  if (userInput.size() != 5) {
		  cout << "Please enter a 5 digit numbers only.\n";
	  } else {
		  break;
	  }
	} while (true);
	
	for (int count = 0; count < SIZE; count++) {
		string element;
		element = userInput[count];
		int number = stoi(element);
	    userList.push_back(number);
	}
}

void displayList(const vector<int> list) {
	for (int count = 0; count < list.size(); count ++) {
		cout << list[count];
	}
	cout <<  endl;
}

void compareList(const vector<int> random, const vector<int> prize) {
	int matchesCount = 0;
	for (int count = 0; count < SIZE; count++) {
		if (random[count] == prize[count]) {
			matchesCount++;
		} 
	}
	
	if (matchesCount == 5) {
		cout << "Unbelievable! You won the grand prize!!\n";
	} else {
		cout << "Better luck next time. There are " << matchesCount << " matching digits in your number.\n";
	}
}


int main() {
	
	vector<int> grandPrize;
	vector<int> userNumbers;
	
	generateRandomList(grandPrize);
	getLUserList(userNumbers);
	
	cout << "Our lucky number is: ";
	displayList(grandPrize);
	
	compareList(grandPrize, userNumbers);
	
	return 0;
}