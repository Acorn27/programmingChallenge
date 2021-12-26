/*
Write a program that reads a sentence as input and converts each word to “Pig Latin.” 
In one version, to convert a word to Pig Latin, you remove the first letter and place 
that letter at the end of the word. Then you append the string “ay” to the word. Here is an example: 
English: I SLEPT MOST OF THE NIGHT 
Pig Latin: IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(const string input, const string delim, vector<string> &token) {
	
	int startPos = 0;
	int endPos = input.find(delim, startPos);
	
	while (endPos != string::npos) {
		
		string tok = input.substr(startPos, endPos - startPos);
		token.push_back(tok);
		
		startPos = ++endPos;
		endPos = input.find(delim, startPos);
		
		
		if (endPos == string::npos) {
			string tok = input.substr(startPos, endPos - startPos);
			token.push_back(tok);
		}
	}
}

string convert(const string input) {
	
	string pigLatin;
	vector<string> token;
	split(input, " ", token);
	
  for (int i = 0; i < token.size(); i++ ) {
		
		string str = token[i];
		string firstChar;
		firstChar = str[0];
		str.append(firstChar);
		str.erase(0,1);
		str.append("AY");
		pigLatin.append(str);
		pigLatin.append(" ");
	}
	
	return pigLatin;
}

int main() {

  string input;
	cout << "Enter string: ";
	getline(cin,input);
	
	string pigLatin;
	pigLatin = convert(input);
	
	cout << "\nEnglish: " << input << endl;
	cout << "Pig Latin: " << pigLatin << endl;
	
	return 0;
}