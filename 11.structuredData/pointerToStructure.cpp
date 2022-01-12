#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
	
	string name;
	int idNum;
	int creditHours;		// credit hours enrolled
	double GPA;
	
};

void getData(Student* c){
	
	cout << "Student Name: ";
	getline(cin, c -> name);
	cout << "Student ID Number: ";
	cin >> c -> idNum;
	cout << "Credit Hours: ";
	cin >> c -> creditHours;
	cout << "Current GPA: ";
	cin >> c -> GPA;
	
}

int main() {
	
	Student freshman;
	
	getData(&freshman);
	
	cout << "\nHere is the student data you entered\n";
	cout << "Name: " << freshman.name << endl;
	cout << "ID: " << freshman.idNum << endl;
	cout << "Credit Hours: " << freshman.creditHours << endl;
	cout << "GPA: " << freshman.GPA << endl;
	
	return 0;
}