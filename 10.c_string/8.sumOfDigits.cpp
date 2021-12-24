/*
Write a program that asks the user to enter a series of single-digit numbers 
with nothing separating them. Read the input as a C-string or a string object. 
The program should display the sum of all the single-digit numbers in the string. 
For example, if the user enters 2514, the program should display 12, which is 
the sum of 2, 5, 1, and 4. The program should also display the highest and 
lowest digits in the string. 
*/
// individual element of cstring has cahr data type;

#include <iostream>
#include <cstring>
using namespace std;

const int SIZE  =	100;

int main() {
	
	char input[SIZE], d[1];
	cout << "Enter a seires of digits numbers in the string: ";
	cin.getline(input, SIZE);
	
	int total = 0;
	int max = 0, min = 9;
	
	for (int index = 0; index < strlen(input); index++) {
		
    int digit = input[index] - '0';                  // IMPORTANT: TO CONVERT FROM '4' TO 4. BECAUSE IN ASCII CODE DIGIT 
		                                                 // START AT 48 AND '0' HAS THE CODE OF 48
		cout << "Digit is: " << digit << endl;
		total += digit;
		
		if (digit >= max) {
			max = digit;
		}
		
		if (digit <= min) {
			min = digit;
		}
	}
	
	cout << "\nSum of digits: " << total << endl;
	cout << "Highest digit: " << max << endl;
	cout << "Lowest digit: " << min << endl;
	
	return 0;
}