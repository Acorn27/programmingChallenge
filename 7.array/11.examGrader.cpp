/*
This program grades final exam. It will do the following task:
  + read student answer file and correct answer file into 2 array
  + display a list of question that student missed: show both correct answer and student's incorrect answer
  + display total question missed
  + percentage of correct answer
  + if percentage is 70 or greater, the program should indicate that student passed the program. Otherwiest, display student failed the program
 */
 
 #include <iostream>
 #include <fstream>
 #include <vector>
 using namespace std;
 
 const string ANSWER_KEY = "CorrectAnswers.txt",
                   STUDENT_KEY = "StudentAnswers.txt";
				   
const int NUMBER_OF_QUESTIONS = 20;

// This method will get char data from a file and store it into a vector
void retrieveData(vector<char> &vectorName, string fileName) {
	
	char data;
	
	ifstream inputFile("ANSWER_KEY");
	
	if (inputFile) {
		cout << "File open successfully.\n";
		while (inputFile >> data) {
		vectorName.push_back(data);
	} else {
		cout << "Error opening file.\n";
	}
	
	inputFile.close();
}

// This method will display student's incorrect answer and the correct answer based on answer key
void displayIncorrect(const vector<char> studentAnswer, const vector<char> key) {
	cout << "\nList of questions missed:\n";
	for (int count = 0; count < NUMBER_OF_QUESTIONS; count ++) {
		if (studentAnswer[count] != key[count]) {
			cout  << "Question " << count << " : your answer " << studentAnswer[count] << ", correct answer " << key[count] << ".\n";
		}
	}
}

// This method will return total number of student's missed question
int caclIncorrect(const vector<char> studentAnswer, const vector<char> key) {
	int totalIncorrect = 0;
	for (int count = 0; count < NUMBER_OF_QUESTIONS; count++) {
		if studentAnswer[count] != key[count] {
			totalIncorrect++;
		}
	}
	
	return (totalIncorrect);
}

bool isPassed(int percentage) {
	if (percentage >= 70) {
		return (true);
	} else {
		return (false);
	}
}
int main() {
	
	vector<char> studentAnswer;
	vector<char> correctAnswer;
	
	retrieveData(studentAnswer, STUDENT_KEY);
	retrieveData(correctAnswer, ANSWER_KEY);
	
	void displayIncorrect(studentAnswer, correctAnswer);
	
	int incorrects = calcIncorrect(studentAnswer, correctAnswer);
	cout << "Total number of question missed: " << incorrects << endl;
	
	float percentage = static_cast<float>(incorrects) / NUMBER_OF_QUESTIONS;
    cout << "The percentage of question answered correctly: " << percentage << endl;
	
	if (isPassed(percentage)) {
		cout << "Congratulation!. You passed the exam!\n";
	} else {
		cout << "Better luck next time kiddo.\n";
	}
	
	cout << "\nDone.\n";
	return 0;
}