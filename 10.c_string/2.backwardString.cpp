/*
Write a function that accepts a pointer to a C-string as an argument and displays its contents backward. 
For instance, if the string argument is "Gravity" the function should display "ytivarG". 
Demonstrate the function in a program that asks the user to input a string then passes it to the function.
*/

#include <iostream>
#include <cstring>
//#include <cstdlib>
using namespace std;

// display string in backward direction
void displayBackward(char* ptr) {
	cout << "Your string in backward: ";
	int last = strlen(ptr) -1;
	for (int index = last; index >= 0; index--) {
		cout << ptr[index];
	}
}

int main() {
	
	// const max character for c string
	const int SIZE = 51;
	char input[SIZE];
	
	// get string from user
	cout << "Enter a string (up to 50 character): ";
	cin.getline(input, SIZE);
	
	displayBackward(input);
	
	return 0;
	
}