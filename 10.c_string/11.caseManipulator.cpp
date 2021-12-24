/*
Write a program with three functions: upper, lower, and reverse. 
The upper function should accept a pointer to a C-string as an argument. 
It should step through each character in the string, converting it to 
uppercase. The lower function, too, should accept a pointer to a C-string 
as an argument. It should step through each character in the string, 
converting it to lowercase. Like upper and lower, reverse should also accept 
a pointer to a string. As it steps through the string, it should test each 
character to determine whether it is uppercase or lowercase. If a character 
is uppercase, it should be converted to lowercase. Likewise, if a character 
is lowercase, it should be converted to uppercase. Test the functions by asking 
for a string in function main, then passing it to them in the following order: reverse, lower, and upper.
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void upper(char* input) {
	while (*input != '\0') {
		*input = toupper(*input);
		input++;
	}
}

void lower(char* input) {
	while (*input != '\0') {
		*input = tolower(*input);
		input++;
	}
}

void reverse(char* input) {
	
	char chr = *input;
	
	if (isupper(chr)) {
		lower(input);
	} else {
		upper(input);
	}
	
}

int main() {
	
	const int SIZE = 101;
	char input[SIZE] = "The letter you entered is lowercase.\n";
	
	upper(input);
	cout << "Upper version: " << input << endl;
	
	lower(input);
	cout << "Lower version: " << input << endl;
	
	reverse(input);
	cout << "First Reverse Version: " << input << endl;
	
	reverse(input);
	cout << "Second Reverse Version: " << input << endl;
	
	return 0;
}