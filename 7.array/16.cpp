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

// To Do: retrieve data from Teams.txt(should take 2 parameter, file name and string vector name)
bool getList(vector<string>& teamsList, string fileName) {

	ifstream inputFile(fileName);

	if (!inputFile) {
		cout << "Error opening file named " << fileName << "\n";
		return false;
	}
	else {
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
	for (unsigned index = 0; index < teamsList.size(); index++) {
		cout << index << ". " << teamsList[index] << "\n";
	}
}



int main() {

	// string vector than contain name of several Leagut basball teams
	vector<string> TeamsList;
	vector<string> winList;


	getList(winList, winnerFile);
	getList(TeamsList, nameFile);
	
	displayList(TeamsList);

	vector<vector<int> > yearList;
	for (unsigned i = 0; i < TeamsList.size(); i++) {
		vector<int> temp;

		int year = 1903;
		for (unsigned j = 0; j < winList.size(); j++) {
			if (TeamsList[i] == winList[j]) {
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


	// call retrieve data vector , if true then call display function

	cout << "\nPlease enter Team's Name or index: ";
	string name;
	int index1 = 0;

	// get user's Team

	getline(cin, name);
	if (name.size() == 1 || name.size() == 2) {
		index1 = stoi(name);
		cout << "Index input received\n";
		name = TeamsList[index1];
	}
	cout << "You entered: " << name << endl;
	cout << TeamsList.size() << endl;
	cout << yearList.size() << endl;
	cout << winList.size() << endl;


	for (int index = 0; index < yearList.size(); index++) {
		if (TeamsList[index] == name) {
			cout << TeamsList[index] << " has won " << yearList[index].size() << " times ";
			cout << "which is in ";
			for (int year2 : yearList[index]) {
				cout << year2 << ", ";
			}
		}
	}





	// notify and terminate program
	cout << "\nDone!\n";
	return 0;
}