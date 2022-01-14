/*
Write a program that uses a structure named MovieData to store the following information about a movie:
Title
Director
Year Released
Running Time (in minutes)
The program should create two MovieData variables, store values in their members, and pass each one, in turn, 
to a function that displays the information about the movie in a clearly formatted manner.
*/

#include <iostream>
#include <string>
using namespace std;

struct MovieData {
	
	string title;
	string director;
	int yearRelease;
	int runningTime;
	double cost;			// movie production cost (in million)
	double revenue;		// first year revenue

};

void showData(const MovieData &m) {

	cout << "\nTitle: " << m.title << endl;
	cout << "Director: " << m. director << endl;
	cout << "Release date: " << m.yearRelease << endl;
	cout << "Duration: " << m.runningTime << endl;
	cout << "Production cost: $" << m.cost << " million" << endl;
	cout << "First year revenue: $" << m.revenue << " million" << endl;
	
}

int main() {
	
	MovieData movie1 {"Lord of the Ring", "Peter Jackson", 2001, 120, 93, 897.7};
	MovieData movie2 {"The Matrix Resurrections", "Lana Wachowski", 2021, 148, 190, 106};
	
	cout << "\nMovie Information\n";
	showData(movie1);
	showData(movie2);
	
	return 0;
	
}