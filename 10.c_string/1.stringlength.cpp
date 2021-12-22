/*
Write a function that returns an integer and accepts a pointer to a C-string as an argument. 
The function should count the number of characters in the string and return that number. 
Demonstrate the function in a simple program that asks the user to input a string, passes 
it to the function, then displays the function’s return value.
*/


#include <iostream>
using namespace std;

int count(char* ptr) {
	int count = 0;
	while (*ptr != '\0') {
		count++;
		ptr++;
	}
	
	return count;
}

int main() {
	
	const int maxChar = 1000;
	char input[maxChar];
	
	cout << "Enter a sentence no more than " << maxChar - 1 << " characters: ";
	cin.getline(input, maxChar);
	
	int charsCount;
	charsCount = count(input);
	cout << "The string you entered has " << charsCount << " characters\n";
	
	return 0;
}

