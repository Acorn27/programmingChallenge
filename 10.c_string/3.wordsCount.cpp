/*
Write a function that accepts a pointer to a C-string as an argument and 
returns the number of words contained in the string. For instance, if the 
string argument is “Four score and seven years ago” the function should return 
the number 6. Demonstrate the function in a program that asks the user to input 
a string then passes it to the function. The number of words in the string should 
be displayed on the screen. Optional Exercise: Write an overloaded version 
of this function that accepts a string class object as its argument. 
*/

#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

void wordsCount(const char* ptr) {
	
	cout << "First verison\n";
  int word = 0, letter = 0;
	
	for (int i = 0; i < strlen(ptr); i++) {
		
		if ((ptr[0] != '\0' && i == 0) || isspace(ptr[i])) {
			word++;
		}
		if (isalpha(ptr[i])) {
			letter++;
		}
	}
	
	cout << "Number of words: " << word << endl;
	cout << "Average number of letters in each words: " << setprecision(2) << fixed << double(letter) / word << endl;
	
}

// overloaded version of wordsCount, which accepts string class as argument
void wordsCount(const string input = "Four score and seven years ago") {
	
	cout << "\nOverloaded version\n";
	int size = input.size();
	int spaceCount = 0;
	
	for (int index = 0; index < size -1; index++) {
		if (input[index] == ' ') {
			spaceCount++;
		}
	}
	
	int wordsCount = spaceCount + 1;
	double average = (double(size) - spaceCount) / wordsCount;
	cout << "Number of words: " << wordsCount << endl;
	cout << "Average number of letters in each words: " << setprecision(2) << fixed << average << endl;
}

int main() {
	
	const int SIZE = 101;
	char input[SIZE];
	
	cout << "Enter a string and I will display the number of words: ";
	cin.getline(input, SIZE);
	
	wordsCount(input);
	
	wordsCount();
	
	return 0;
}