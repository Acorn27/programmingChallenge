/*
This program need two .txt files: Teams.txt and WorldSeriesWinners.txt
Teams.txt contains a list of several Major League baseball teams in alphabest order
WorldSeriesWinners constain chronogical list of these Team from 1903 to 2021
the program should:
	+ display a list of team retrieve from data in Teams.txt
	+ Allow user to enter name of basball team they want to find year window
	+ Display that team winning year as well as number of time they has won the World Series
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const string nameFile = "Teams.txt";
const string winnerFile = "WorldSeriesWinners.txt";

// To Do: retrieve data from file(should take 2 parameter, file name and string vector name)
void getList(vector<string>& teamsList, string fileName) {

	ifstream inputFile(fileName);

	if (!inputFile) {
		cout << "Error opening file named " << fileName << "\n";
	}
	else {
		cout << fileName << " has been opened successfully\n";
		string Name;
		int count = 0;
		while (!inputFile.eof()) {
			getline(inputFile, Name);
			teamsList.push_back(Name);
			count++;
		}
		cout << count << " items has been successfully read from " << fileName << "\n\n";
		inputFile.close();
	}

}

// To Do: display list of Teams(take string vector as parameter)
void displayList(const vector<string> teamsList) {
	
	cout << "Major League Baseball Teans List\n";
	for (unsigned index = 0; index < teamsList.size(); index++) {
		cout << index << ". " << teamsList[index] << "\n";
	}
}

// To Do: a final 2D vector that the inter vector
// hold a list of year an index corresponding Team won world. The 2d vector should look like
/* 
{
	{2001}  //  "Anaheim Angel" has won in 2001
	{2002}	//  "Arizona Diamondbacks" has won in 2002
	{1995}  //  "Atlanta Braves" has won in 2003
}

*/
void yearWin(vector<vector<int> > &yearList, const vector<string> teamsList, const vector<string> winList) {
	for (unsigned i = 0; i < teamsList.size(); i++) {
		vector<int> temp;

		int year = 1903;
		for (unsigned j = 0; j < winList.size(); j++) {
			if (teamsList[i] == winList[j]) {
				temp.push_back(year);
			}
			if (year == 1903 || year == 1993) {
			  year += 2; 
			}
			else {
				year ++;
			}
		}
		yearList.push_back(temp);
	}
}

// To Do: get user input function
string getUserInput(const vector<string> TeamsList) {

	cout << "\nPlease enter Team's Name or index: ";
	string name;
	int index = 0;

	getline(cin, name);
	if (name.size() == 1 || name.size() == 2) {
		index = stoi(name);
		cout << "Index input received\n";
		name = TeamsList[index];
	}
	cout << "You entered: " << name << "\n\n";
	return name;
}

int main() {

	// TeamsList vector to hold a list of major league baseball team
	// winList vector to hold a chronogical list of team that won wirld series
	vector<string> TeamsList;
	vector<string> winList;

  // retrieve data from file to vector for later use
	getList(winList, winnerFile);
	getList(TeamsList, nameFile);
	
	// display list for user to select
	displayList(TeamsList);

  // create 2D vector
	vector<vector<int> > yearList;
  
	// call 2D vector-creator fucntion
	yearWin(yearList, TeamsList, winList);

  // call get user-input function
	string name;
  name = getUserInput(TeamsList);

  // calculate number of year that team has won, and the specific year name
	for (int index = 0; index < yearList.size(); index++) {
		if (TeamsList[index] == name) {
			cout << TeamsList[index] << " has won " << yearList[index].size() << " times ";
			cout << "which is in ";
			for (int count = 0; count < yearList[index].size(); count++) {
				cout << yearList[index][count];
				if (count == yearList[index].size() - 1) {
					cout << ".";
				} else {
					cout << ", ";
				}
			}
		}
	}

	// notify and terminate program
	cout << "\n\nDone!\n";
	return 0;
}