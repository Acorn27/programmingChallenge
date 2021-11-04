/*
This program should do the following task:
  + string vector to store 5 student names
   + an vector of 5 letter to store 5 student leter grade
   + an 2d vector to store 4 test score of 5 students
 Program should user enter each student's name and their 4 test score 
 then display average test score as well as a letter grade based on the average
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int NUMBER_OF_STUDENTS = 5,
              NUMBER_OF_TEST = 4; 

void  getName(vector<string> &studentName) {
	string name;
	for (int count = 0; count < NUMBER_OF_STUDENTS; count++) {
		cout << "Enter name of student " << count + 1 << ": ";
		getline(cin, name);
		studentName.push_back(name);
	}
}

void getScore(vector<vector<int> > &testScore, const vector<string> studentName) {
  int score;
  for (int student = 0; student < NUMBER_OF_STUDENTS; student++) {
  vector<int> inner;
	  for (int test = 0; test < NUMBER_OF_TEST; test++) {
		  cout << "Enter test score of test " << test + 1 << " for " << studentName[student] << ": ";
		  cin >> score;
		  inner.push_back(score);
    }
    testScore.push_back(inner);
    }
}

string returnGrade(const int average) {
	if (average > 90) {
		return ("A");
	} else if (average > 80) {
		return ("B");
	} else if (average > 70) {
		return ("C");
	} else if (average > 60) {
		return ("D");
	} else {
		return ("F");
	}
}


void displayFinal(const vector<vector<int> > testScore, const vector<string> studentName) {
	for (int studentPos = 0; studentPos < testScore.size(); studentPos++) {
		float average = 0.0f;
		int total = 0;
		for (int testPos = 0; testPos < testScore[studentPos].size(); testPos++) {
			total += testScore[studentPos][testPos];
		}
		average = total / testScore[studentPos].size();
		cout << "Final Grade of  " << studentName[studentPos] << " is " << returnGrade(average) << " with the average of " << average << endl;
	}
}


int main() {
  
  vector<string> studentName;
  vector<char> studentGrade;
  vector<vector<int> > testScore;  

	getName(studentName);
	getScore(testScore, studentName);
	
	displayFinal(testScore, studentName);
	
	cout << "\nDone.\n";
	return 0;
}

