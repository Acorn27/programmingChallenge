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
  for (int type = 0; type < SIZE; type++) {
    do {
      cout << "Enter sale for " << name[type] << " salsa: ";
      if (!(cin >> sale[type])) {
        cout << "Please enter integer only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
      } else if (sale[type] < 0) {
        cout << "Number of jar sold can not be negative.\n";
		cout << "Please re-enter number of jars sold.\n";
      } else {
        break;
      }
    } while (true);
  }
}

void findExtreme(int sale[], string name[], int size) {
  int highest = sale[0];
  int lowest = sale[0];
  int highestIndex = 0;
  int lowestIndex = 0;
  for (int pos = 0; pos < size; pos++) {
    if (sale[pos] > highest) {
      highest = sale[pos];
      highestIndex = pos;
	}
	if (sale[pos] < lowest) {
		lowest = sale[pos];
		lowestIndex = pos;
	} 
    }
  cout << "Highest sale: " << name[highestIndex] << endl;
  cout << "Lowest sale: " << name[lowestIndex] << endl;
}

void findTotal(int sale[], int size) {
	int total = 0;
	for (int pos = 0; pos < size; pos++) {
		total += sale[pos];
	}
	cout << "Total jars sold: " << total << endl;
}

void  displayReport(int sale[], string name[], int size) {
  cout << endl;
  cout << "          Salsa Sales Report          ";
  cout << endl << setw(30) << left << "Salsa Name" << "Jars sold" << endl;
  cout <<"________________________________\n";
  
  for (int pos = 0; pos < size; pos++) {
    cout << setw(30) << left << name[pos] << sale[pos] << endl; 
  }
  cout << endl;
  findTotal(sale, size);
  findExtreme(sale, name, size);
}



int main() {

  string salsaNames[SIZE] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
  int salsaSales[SIZE];
  
  // get number of jars sold for each type of salsa
  getSales(salsaSales, salsaNames, SIZE);
  
  // display report, which incude sale for each salsa type, highest and lowest salsa 
  displayReport(salsaSales, salsaNames, SIZE);

  return 0;

}
