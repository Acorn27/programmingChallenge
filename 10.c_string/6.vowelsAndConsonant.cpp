/*
Write a function that accepts a pointer to a C-string as its argument. 
The function should count the number of vowels appearing in the string and return that number.
Write another function that accepts a pointer to a C-string as its argument. 
This function should count the number of consonants appearing in the string and return that number.
Demonstrate these two functions in a program that performs the following steps:
1. The user is asked to enter a string.
2. The program displays the following menu:
A) Count the number of vowels in the string
B) Count the number of consonants in the string
C) Count both the vowels and consonants in the string
D) Enter another string
E) Exit the program
3. The program performs the operation selected by the user and repeats until the user selects E to exit the program.
*/

#include <iostream>
#include <cstring>
using namespace std;

int calcVowels(const char* str) {
	
	int vowel = 0;
	
	while (*str != '\0') {
		char temp = tolower(*str);
		if (temp == 'a' || temp == 'e' || temp == 'o' || temp == 'u' || temp == 'i') {
			vowel++;
		}
		str++;
	}
	
	return vowel;
}

int calcConsonants(const char* str) {
	
	int consonant = 0;
	int letter = 0;
	while (*str != '\0') {
		if (isalpha(*str)) {
			letter++;
		}
		str++;
	}
	consonant = letter - calcVowels(str);
	
	return (consonant);
}

int main() {
		
	// hold user input
	const int SIZE = 101;
	char input[SIZE];
	
	cout << "Enter a string no more than " << SIZE - 1 << " characters: ";
	cin.getline(input, SIZE);
	
	char choice;
	do {
		cout << "\tProgram Menu\t\t\t\n";
		cout << "A) Count the number of vowels in the string.\n";
		cout << "B) Count the number of consonants in the string.\n";
		cout << "C) Count both the vowels and consonants in the string.\n";
		cout << "D) Enter another string.\n";
		cout << "E) Exit the program\n";
		cin >> choice;
		choice = toupper(choice);
		
		switch(choice) {
			
			case 'A' : cout << "There are " << calcVowels(input) << " vowels in your string.\n";
			           break;
			
			case 'B' : cout << "There are " << calcConsonants(input) << " consonants in your string.\n";
			           break;
		
		  case 'C' : cout << "There are " << calcVowels(input) << " vowels and " << calcConsonants(input) << " consonants in your string.\n";
			           break;
			
			case 'D' : cout << "Enter another string: ";
			           cin.ignore();
			           cin.getline(input, SIZE);
								 continue;
			
			case 'E' : cout << "Exiting . . . \n";
			           break;
		  default  : cout << "I assume that you don't know what the fuck you're doing so I just exit the program.\n";
			           choice  = 'E';
			           break;
		}
	} while (choice != 'E');
	
	return 0;
}