/*
Write a program that displays a simulated paycheck. 
The program should ask the user to enter the date, 
the payee’s name, and the amount of the check (up to $10,000). 
It should then display a simulated check with the dollar amount spelled out, as shown here:
                                                   Date: 11/24/2021 
     Pay to the Order of: John Phillips            $1920.85  
     One thousand nine hundred twenty and 85 cents 
Be sure to format the numeric value of the check in fixed-point 
notation with two decimal places of precision. Be sure the 
decimal place always displays, even when the number is zero 
or has no fractional part. Use either C-strings or string class objects in this program.
Input Validation: Do not accept negative dollar amounts, or amounts over $10,000.
*/

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 9
string number[SIZE] = {"zero", "one", "two", "thee", "four", "five", "six", "seven", "eigth", "night", "ten"};

int main() {
	
	string payeeName, date, amountSpellOut, amount;
	
	cout << "Enter payee's name: ";
	getline(cin,payeeName);
	
	cout << "Enter the date of the transaction (mm/dd/yyyy): ";
	getline(cin, date);
	
	double digit;
	do {
		
		cout << "Enter amount of the transaction: ";
	  getline(cin, amount);
		digit = stod(amount);
		if (digit > 10000) {
			cout << "Amount over $10,000 is invalid.\n";
		} else if (digit <= 0) {
			cout << "Negative dollar amounts is invalid.\n";
		} else {
			break;
		}
		
	} while (true);
	
	
	return 0;
	
}