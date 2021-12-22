#include <iostream>
#include <string>
#include <vector>
using namespace std;

void split(const string& s, const char delimiter, vector<string>& tokens) {
	
	// Starting position of the first token, which we can safely assume equal 0
	int tokenStart = 0;
	
	//Find the first occurrence of the first delimiter, which also mean of end position of the first token
	int delimPos = s.find(delimiter);
	
	while (delimPos != string::npos) {  // only execute loop if there is a delimiter, if there is no delimiter, find member function will return npos
		
		// note: mystring.substr(x, n)	Returns a copy of a substring. The substring is n characters long and begins at position x of mystring.
		string tok = s.substr(tokenStart, delimPos - tokenStart);
		
		//push the token onto the token vector
		tokens.push_back(tok);
		
		//find the next starting position for the next token
		tokenStart = ++delimPos;		// This is a one arrow for two bird because we also need to increase delimPos later in order to find the end postion of next the next token
		                            // if delimPos stay the same, the find function will return the same position as the last run.
		
		// find the end position for the next token
		// note: 
		// mystring.find(str, x)	Returns the first position at or beyond position x where the string str is found in mystring. str may be either a string object or a character array.
    // mystring.find('z', x)	Returns the first position at or beyond position x where 'z' is found in mystring. If 'z' is not found, the function returns the special value string::npos.
		delimPos = s.find(delimiter, delimPos);
		
		if (delimPos == string::npos) {
			string tok = s.substr(tokenStart, delimPos - tokenStart);
			tokens.push_back(tok);
		}
	}
}

int main() {
	
	string input;
	cout << "Enter string you want to find tokens: ";
	getline(cin,input);
	
	char delimiter;
	cout << "Enter delimiter: ";
	cin.get(delimiter);                   // IMPORTANT: use cin.get to take only one character, wich is able to take white space as input
  
	vector<string> tokens;
	
	split(input, delimiter, tokens);
	
	// Print out vector content
	cout << "Here is your tokens list: ";
	for (int index = 0; index < tokens.size(); index++) {
		cout << tokens[index] << " ";
	}
	
	return 0;
}