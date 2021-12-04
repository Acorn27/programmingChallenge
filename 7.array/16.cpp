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
using namespace std;

const string nameFile = "Teams.txt";
const string winnerFile = "WorldSeriesWinners.txt";

// To Do: retrieve data from Teams.txt(should take 2 parameter, file name and string vector name)
bool getList(vector<string> &teamsList, string fileName) {
	
	ifstream inputFile(fileName);
	
	if (!inputFile) {
		cout << "Error opening file named " << fileName << "\n";
		return false;
	} else {
		cout << "File open successfully\n";
		string Name;
		int count = 0;
	  while (!inputFile.eof()) {
			getline(inputFile, Name);
		  teamsList.push_back(Name);
			count++; 
	  }
		cout << count << " items has been successfully read from " << fileName << "\n";
	  inputFile.close();
		return true;
	}

}

// To Do: display list of Teams(take string vector as parameter)
void displayList(const vector<string> teamsList) {
	for (int index = 0; index < teamsList.size(); index++ ) {
		cout << index << ". " << teamsList[index] << "\n";
	}
}


// To Do: find number of time that Team has Won(take name vector parameter and year int vector)
int getNumberOfWinTime(const vector<string> teamsList, string fileName) {
	
	cout << "\nPlease enter Team's Name or index: ";
	string name;
	int index = 0;
  
	getline(cin, name);
	if (name.size() == 1 || name.size() == 2) {
		index = stoi(name);
		cout << "Index input received\n";
		name = teamsList[index];
	}
	
	cout << "You entered: " << name << endl;
	
	ifstream inputFile(fileName);
	if (!inputFile) {
		cout << "Error opening file name " << fileName << "\n";
	} else {
		int count = 0;
		while (!inputFile.eof()) {
			string dataLine;
			getline(inputFile, dataLine);
			if (dataLine == name) {
				count++;
			}
		}
		return count;
	}
}

// To Do: display the year that team has won(take string vector parameter)

int main() {
	
	// string vector than contain name of several Leagut basball teams
	vector<string> TeamsList;
	
	// call retrieve data vector , if true then call display function
	if (getList(TeamsList, nameFile)) {
		displayList(TeamsList);
		
		int winTimes;
		winTimes = getNumberOfWinTime(TeamsList, winnerFile);
		cout << endl;
		if (winTimes != 0) {
		  cout << "The team you entered has won " << winTimes << " times\n";
		} else {
			cout << "The team you entered is not match\n";
		}
	}
	
	// notify and terminate program
	cout << "\nDone!\n";
	return 0;
}