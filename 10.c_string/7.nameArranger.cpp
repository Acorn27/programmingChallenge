/*
Write a program that asks for the user’s first, middle, and last names. 
The names should be stored in three different character arrays. 
The program should then store, in a fourth array, the name arranged in 
the following manner: the last name followed by a comma and a space, 
followed by the first name and a space, followed by the middle name. 
For example, if the user entered "Carol Lynn Smith", it should store 
"Smith, Carol Lynn" in the fourth array. Display the contents of the fourth array on the screen. 
*/

#include <iostream>
#include <cstring>
using namespace std;

void combine(char* first, char* middle, char* last, char* fullName) {
	
	for (int index = 0; index < strlen(last); index++) {
		*fullName = last[index];
		fullName++;
	}
	*fullName = ',';
	fullName++;
	*fullName = ' ';
	fullName++;
	for (int index = 0; index < strlen(first); index++) {
		*fullName = first[index];
		fullName++;
	}
	*fullName = ' ';
	fullName++;
	for (int index = 0; index < strlen(middle); index++) {
		*fullName = middle[index];
		fullName++;
	}
	*fullName = '\0';
}

int main() {
	 
	const int SIZE = 20;
	char first[SIZE];
	char last[SIZE];
	char middle[SIZE];
	
	cout << "Enter first name: ";
	cin.getline(first, SIZE);
	cout << "Enter middle name: ";
	cin.getline(middle, SIZE);
	cout << "Enter last name: ";
	cin.getline(last, SIZE);
	
	char fullName[SIZE* 3];
	combine(first, middle, last, fullName);
	cout << "\nYour full name is: " << fullName << endl; 
	
	return 0;
}