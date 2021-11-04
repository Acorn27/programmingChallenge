/* This program checked answer entered by user
by an array of correct answer has been initialzed.
Program should do the following tasks:
  + initilized correct answer in one array  
	+ ask user to enter answer for 20 question and store in another array 
	+ display whether student passed the exam
	+ display total of correct answer, incorrect answer
	+ a list of question number of incorect answer
*/

#include <iostream>
#include <vector>
using namespace std;

const int NUMBER_OF_QUESTIONS = 20;
vector<char> answerKey = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};

void getStudentAns(vector<char>);
bool passExam(vector<char>);
void displayResult(vector<char>);

int main() {
	
	vector<char> studentAnswer;
	getStudentAns(studentAnswer);
	
	if (passExam(studentAnswer)) {
		cout << "Congratulation! You have passed the exam.\n";
	} else {
		cout << "You have not passed the exam. Better luck next time kiddo.\n";
	}
	
	displayResult(studentAnswer);
	
	
	
}

void getStudentAns(vector<char> studentAnswer) {
	char answer;
	cout << "Enter student answers.\n";
	for (int count = 0; count < NUMBER_OF_QUESTIONS; count++) {
		do {
		cout << count + 1 << ". ";
		cin  >> answer;
		answer = toupper(answer);
		if (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D') {
			cout << "We only accept the letter A, B, C, or D as answers.\n";
			cout << "Please enter answer again.\n";
			cin.clear();
			cin.ignore(1000,'\n');
		} else {
		  studentAnswer.push_back(answer);
		  break;
		}
	  } while (true);
  }
}

bool passExam(vector<char> studentAnswer) {
	int wrongAnswer = 0;
	int count = 0;
	for (int count = 0; count < NUMBER_OF_QUESTIONS; count++) {
		(studentAnswer[count] == answerKey[count] ? wrongAnswer++ : wrongAnswer = wrongAnswer);
		if (wrongAnswer  > 5) {
			return (false);
		}
	}
	return (true);
}

void displayResult(vector<char> studentAnswer) {
	vector<int> wrongAnswer;
	vector<int> rightAnswer;
	for (int count = 0; count < NUMBER_OF_QUESTIONS; count++) {
		if (studentAnswer[count] == answerKey[count]) {
			rightAnswer.push_back(count);
		} else {
			wrongAnswer.push_back(count);
		}
	}
	
	cout << "Numbers of correct answers: " << rightAnswer.size() << endl;
	cout << "Number of incorrect answers: " << wrongAnswer.size() << endl;
	cout << "Question numbers of the incorrectly answered questions: " << endl;
	for (int var : wrongAnswer) {
		cout << var << endl;
	}
}