/*
Lottery Statistics
To play the PowerBall lottery, you buy a ticket that has five numbers in the range of 1–69, and a “PowerBall” number in the range of 1-26. 
(You can pick the numbers yourself, or you can let the ticket machine randomly pick them for you.) 
Then, on a specified date, a winning set of numbers are randomly selected by a machine. 
If your first five numbers match the first five winning numbers in any order, and your PowerBall 
number matches the winning PowerBall number, then you win the jackpot, which is a very large amount of money. 
If your numbers match only some of the winning numbers, you win a lesser amount, depending on how many of 
the winning numbers you have matched. 
In the student sample programs for this book, you will find a file named pbnumbers.txt, 
containing the winning lottery numbers that were selected between February 3, 2010 and May 11, 2016 
(the file contains 654 sets of winning numbers). Here is an example of the first few lines of the file’s contents: 
17	22	36	37	52	24
14	22	52	54	59	04
05	08	29	37	38	34
10	14	30	40	51	01
07	08	19	26	36	15
and so on …
Each line in the file contains the set of six numbers that were selected on a given date. 
The numbers are separated by a space, and the last number in each line is the PowerBall number 
for that day. For example, the first line in the file shows the numbers for 
February 3, 2010, which are 17, 22, 36, 37, 52, and the PowerBall number 24.
Write one or more programs that work with this file to perform the following:
• Display the 10 most common numbers, ordered by frequency.
• Display the 10 least common numbers, ordered by frequency.
• Display the 10 most overdue numbers (numbers that haven’t been drawn in a long time), ordered from most overdue to least overdue.
• Display the frequency of each number 1-69, and the frequency of each Powerball number 1-26.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const string INPUT_FILE = "pbnumbers.txt";

void split(const string& s, const char delimiter, vector<string>& tokens) {

	int tokenStart = 0;
	int delimPos = s.find(delimiter);
	
	while (delimPos != string::npos) {
		string tok = s.substr(tokenStart, delimPos - tokenStart);
		
		tokens.push_back(tok);
		tokenStart = ++delimPos;

		delimPos = s.find(delimiter, delimPos);
		
		if (delimPos == string::npos) {
			string tok = s.substr(tokenStart, delimPos - tokenStart);
			tokens.push_back(tok);
		}
	}
}

void retrieveData(vector<string> &normalBall, vector<string> &powerBal, string fileName) {
	
	ifstream input_file(fileName);
	
	string line;
	while (!(input_file.eof())) {
		
		getline(input_file, line);
		
		// split input into smaller item
		vector<string> temp;
		split(line, ',', temp);
		
		for (int i = 4; i <= 9; i++) {
			if (i == 9) {
				powerBal.push_back(temp[i]);
			} else {
				normalBall.push_back(temp[i]);
			}
		}
	}
	
	input_file.close();
	
}

int main() {
	
	vector<string> normalBall;
	vector<string> powerBall;
	retrieveData(normalBall,powerBall, INPUT_FILE);
	
	
	return 0;
}