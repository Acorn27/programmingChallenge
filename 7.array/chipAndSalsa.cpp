// This program create 2 5-element arrays
// one to save 5 diffent name of salsa and
// the other save sale amount for each salsa
// program should let user ennter sal amount
// then display the report as well as the highest
// and lowest selling product

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 5;


void getSales(int sale[], string name[], int size) {
  for (int count = 0; count < SIZE; count++) {
    do {
      cout << "Enter sale for " << name[count] << " salsa: ";
      if (!(cin >> sale[count])) {
        cout << "Please enter integer only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
      } else if (sale[count] < 0) {
        cout << "Number of jar sold can not be negative.\n";
      } else {
        break;
      }
    } while (true);
  }
}



void findExtreme(int sale[], string name[], int size) {
  int highest = sale[0], lowest = sale[0];
  int highestIndex = 0, lowestIndex = 0;
  for (int count = 0; count < size; count++) {
    if (sale[count] > highest) {
      highest = sale[count];
      highestIndex = count;
	}
	if (sale[count] < lowest) {
		lowest = sale[count];
		lowestIndex = count;
	} 
    }
  cout << name[highestIndex] << " salsa has the highest sale among the others.\n";
  cout << name[lowestIndex] << " salsa has the lowest sale among the others.\n";
}


void  displayReport(int sale[], string name[], int size) {
  cout << endl << setw(30) << left << "Salsa Name" << setw(10) << left << "Sale" << endl;
  for (int count = 0; count < size; count++) {
    cout << setw(30) << left << name[count] << setw(10) << left << sale[count] << endl; 
  }
  cout << endl;
  findExtreme(sale, name, size);
}



int main() {

  string salsaNames[SIZE] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
  int salsaSales[SIZE];
  
  getSales(salsaSales, salsaNames, SIZE);
  
  displayReport(salsaSales, salsaNames, SIZE);

  return 0;

}
