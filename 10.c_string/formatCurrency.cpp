#include <iostream>
#include <string>
using namespace std;

void dollarFormat(string &input) {
	
	int dp;
	
	dp = input.find('.');
	if (dp > 3) {
		for (int x = dp -3; x > 0; x -= 3) {  // This is an interesting use of for loop; need attention
			input.insert(x, ",");								// insert only accept string, which is why we use ",". instead of ','
		}
	}
	input.insert(0, "$");
}

int main() {
	
	string input;
	
	// get dollar amount from user
	cout << "Enter a dollar amount in in form nnnnn.nn: ";
	getline(cin, input);
	
	dollarFormat(input);
	
	// Display formatted dollar amount
	cout << "\nHere is the amount formatted: "
	     << input << endl;

  return 0;			 
}