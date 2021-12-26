/*
Write a program that accepts as input a sentence in which all of the words 
are run together, but the first character of each word is uppercase. 
Convert the sentence to a string in which the words are separated by spaces 
and only the first word starts with an uppercase letter. For example, the string 
“StopAndSmellTheRoses.” would be converted to “Stop and smell the roses.” 
*/

#include <iostream>
#include <string>
using namespace std;

string convert(string &input) {
  
	int upperPos;
  for (int index = 0; index < input.size(); index++) {
		char c = input[index];
		
		if (isupper(c)) {
			if (index == 0) {
			  continue;
			}	else {
				input[index] = tolower(input[index]);
				input.insert(index, " ");
			}
		}
	}

  return input;	
}

int main() {
	
	string input;
	
	cout << "Enter a string: ";
	getline(cin, input);
	
	cout << "Pass1\n";
	convert(input);
	cout << "Modified string: " << input << endl;
	cout << "Pass2\n";
	
	return 0;
}