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
#include <iomanip>
using namespace std;

const int SIZE = 9;

string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };
                 
string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };

string numToWord(int n, string s) {
    
    string str = "";
    
    if (n > 19) {
        str += ten[n / 10] + one[n % 10];
    } else {
        str += one[n];
    }
    
    if (n) {
        str += s;
    }
    
    return str;
}

string convertToWords(int n) {
    
    string out;
    
    out += numToWord(((n / 1000) % 100), "thousand ");
    
    out += numToWord(((n / 100) % 10), "hundred ");
    
    out += numToWord((n % 100), "");
		
    return out;
}


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
	
	double fixpoint = (digit - int(digit)) * 100;
	cout << "Fix point is: " << fixpoint << endl;
	
	// Display
	cout << "\t\tDate: " << date << endl;
	cout << "Pay to the Order of: " << payeeName;
	cout << "\t$" << setprecision(2) << fixed << digit << endl;
	cout << convertToWords(digit)  << "dollar" << " and " << convertToWords(fixpoint) << "cents.\n";
	
	
	
	
	return 0;
	
}