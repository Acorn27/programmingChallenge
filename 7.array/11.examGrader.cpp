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
 
 const string STUDENT_FILE = "CorrectAnswers.txt",
              ANSWER_KEY_FILE = "StudentAnswers.txt";
				   
const int NUMBER_OF_QUESTIONS = 20;

// This method will get char data from a file and store it into a vector
void retrieveData(vector<char> &vectorName, string fileName) {
	
	char data;
	
	ifstream inputFile(fileName);
	
	if (inputFile) {
		cout << "File " << fileName << " open successfully.\n";
		while (inputFile >> data) {
		  vectorName.push_back(data);
		}
	} else {
		cout << "Error opening file " << fileName <<  endl;;
		exit(1);
	}
	
	inputFile.close();
}

// This method will display student's incorrect answer and the correct answer next to it based on answer key
void displayIncorrect(const vector<char> studentAnswer, const vector<char> key) {
	cout << "\nList of questions missed:\n";
	for (int count = 0; count < NUMBER_OF_QUESTIONS; count ++) {
		if (studentAnswer[count] != key[count]) {
			cout  << "Question " << count + 1 << " : your answer " << studentAnswer[count] << ", correct answer " << key[count] << ".\n";
		}
	}
}

// This method will return total number of student's missed question
int caclIncorrect(const vector<char> studentAnswer, const vector<char> key) {
	int totalIncorrect = 0;
	for (int count = 0; count < NUMBER_OF_QUESTIONS; count++) {
		if (studentAnswer[count] != key[count]) {
			totalIncorrect++;
		}
	}
	
	return (totalIncorrect);
}

// This method return true if argument  is 70 or greater. Otherwise, return false.
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
	
	retrieveData(studentAnswer, STUDENT_FILE);
	retrieveData(correctAnswer, ANSWER_FILE);
	
	displayIncorrect(studentAnswer, correctAnswer);
	
	int incorrects = caclIncorrect(studentAnswer, correctAnswer);
	cout << "Total number of question missed: " << incorrects << endl;
	
	float percentage = (static_cast<float>(NUMBER_OF_QUESTIONS - incorrects) / NUMBER_OF_QUESTIONS) * 100;
  cout << "The percentage of question answered correctly: " << percentage << endl;
	
	if (isPassed(percentage)) {
		cout << "Congratulation!. You passed the exam!\n";
	} else {
		cout << "Better luck next time kiddo.\n";
	}
	
	cout << "\nDone.\n";
	return 0;
}