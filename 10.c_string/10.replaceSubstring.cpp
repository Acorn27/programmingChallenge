/*
Write a function named replaceSubstring. The function should accept three C-string or string object arguments. 
Let’s call them string1, string2, and string3. It should search string1 for all occurrences of string2. 
When it finds an occurrence of string2, it should replace it with string3. For example, suppose the 
three arguments have the following values:
string1: ﻿
“the dog jumped over the fence”
string2: 	“the”
string3:	“that”
With these three arguments, the function would return a string object with the value “that dog jumped over that fence.” 
Demonstrate the function in a complete program.
*/

#include <iostream>
#include <string>
using namespace std;

//mystring.replace(x, n, str)	Replaces the n characters in mystring beginning at position x with the characters in string object str.
string replaceSubstring(string s1,const string s2, const string s3) {
	
	int foundIndex = 0;
	int examplePos = 0;
	foundIndex = s1.find(s2, examplePos);
	
	while (foundIndex != string::npos) {
		s1.replace(foundIndex, s2.length(), s3);
		examplePos = foundIndex + s3.length();
		foundIndex = s1.find(s2, examplePos);
	}
	
	return (s1);
}

int main() {
	
	string s1, s2, s3;
	
	cout << "Enter a sentence: ";
	getline(cin, s1);
	
	cout << "Enter a word you would like to replace: ";
	getline(cin, s2);
	
	cout << "Enter a word you would like to replace " << s2 << " with: ";
	getline(cin, s3);
	
	cout << "\nEdited sentence: " << replaceSubstring(s1, s2, s3) << endl;
	
	return 0;
}