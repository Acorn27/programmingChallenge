/*
Write a function that accepts either a pointer to a C-string, or a string object, 
as its argument. The function should return the character that appears most 
frequently in the string. Demonstrate the function in a complete program. 
*/

#include <iostream>
#include <cstring>
using namespace std;

char mostFreq(char* str) {
	
	int maxTime = 1;
	char finalChar;
	for (int start = 0; start < (strlen(str) - 1); start++) {
		
		char sample = toupper(str[start]);
		if (isspace(sample)) {continue;};
		int sampleTime = 1;
		for (int index = start + 1; index < strlen(str); index++ ) {
			
			if (str[index] == sample) {
			  sampleTime++;
			}
		}
		
		if (sampleTime >= maxTime) {
			finalChar = sample;
			maxTime = sampleTime;
		}
	}
	
	return (finalChar);
}

int main() {
	
	char input[100];
	cout << "Enter a string and I will tell you the most frequent character: ";
	cin.getline(input, 100);
	
	char character = mostFreq(input);
	cout << "The most frequent character is: " << character << endl;
	
	return 0;
}