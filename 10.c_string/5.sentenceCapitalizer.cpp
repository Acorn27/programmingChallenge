/*
Write a function that accepts a pointer to a C-string as an argument and capitalizes 
the first character of each sentence in the string. For instance, if the string argument 
is "hello. my name is Joe. what is your name?" the function should manipulate the string 
so that it contains "Hello. My name is Joe. What is your name?" Demonstrate the function 
in a program that asks the user to input a string then passes it to the function. 
The modified string should be displayed on the screen. 
Optional Exercise: Write an overloaded version of this function that accepts a string class object as its argument. 
*/

#include <iostream>
#include <cstring>
using namespace std;

void sentenceCapilizer(char* Str) {
	
	// Capitalize the first character
	if (isalpha(*Str)) {*Str = toupper(*Str); Str++;};
	
	while (*Str != '\0') {
		if (ispunct(*Str)) {
			
			do {
				Str++;
			} while (*Str == ' ' || !(isalpha(*Str)));
			
			*Str = toupper(*Str);
		}
		Str++;
	}
}

void display(char* Str) {
	
	cout << "Modified string: ";
	while (*Str != '\0') {
		cout << *Str;
		Str++;
	}
}

int main() {
	
	const int SIZE = 101;
	char input[SIZE];
	
	cout << "Enter a string( up to 100 character): ";
	cin.getline(input, SIZE);
	
	sentenceCapilizer(input);
	
	display(input);
	
	return 0;
	
}