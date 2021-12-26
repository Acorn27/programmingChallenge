/*
Write a program that has an array of at least 10 string objects that hold people’s names and phone numbers. 
You may make up your own strings, or use the following:
     "Alejandra Cruz, 555–1223" 
     "Joe Looney, 555–0097" 
     "Geri Palmer, 555–8787" 
     "Li Chen, 555–1212" 
     "Holly Gaddis, 555–8878" 
     "Sam Wiggins, 555–0998" 
     "Bob Kain, 555–8712" 
     "Tim Haynes, 555–7676" 
     "Warren Gaddis, 555–9037" 
     "Jean James, 555–4939" 
     "Ron Palmer, 555–2783" 
The program should ask the user to enter a name or partial name to search for in the array. 
Any entries in the array that match the string entered should be displayed. 
For example, if the user enters "Palmer" the program should display the following names from the list:
     Geri Palmer, 555–8787 
     Ron Palmer, 555–2783 
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	
	const int NUM_PEOPlE = 11;
	const int LENGTH = 100;
	
	char phoneNumber[NUM_PEOPlE][LENGTH] = {"Alejandra Cruz, 555–1223", 
     "Joe Looney, 555–0097", 
     "Geri Palmer, 555–8787", 
     "Li Chen, 555–1212", 
     "Holly Gaddis, 555–8878", 
     "Sam Wiggins, 555–0998", 
     "Bob Kain, 555–8712", 
     "Tim Haynes, 555–7676", 
     "Warren Gaddis, 555–9037", 
     "Jean James, 555–4939", 
     "Ron Palmer, 555–2783"};
	
	char lookUp[LENGTH];
	char *strPtr = nullptr;
	int index;
	
	cout << "\nPhone Number Database\n";
	cout << "Enter a product number to search for: ";
	cin.getline(lookUp, LENGTH);
	
	for (int i = 0; i < NUM_PEOPlE; i++) {
		
		strPtr = strstr(phoneNumber[i], lookUp);
		if (strPtr != nullptr) {
			cout << phoneNumber[i] << endl;
		  strPtr = nullptr;
		}
	}
	
}