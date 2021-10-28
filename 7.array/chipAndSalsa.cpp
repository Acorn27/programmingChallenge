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



void findHighest(int sale[], string name[], int size) {
  int highest = sale[0];
  int highestIndex = 0;
  for (int count = 0; count < size; count++) {
    if ( highest < sale[count]) {
      highest = sale[count];
      highestIndex = count;
    }
  }
  cout << name[highestIndex] << " salsa has the highest sale among the others.\n";
}



void findLowest(int sale[], string name[], int size) {
  int lowest = sale[0];
  int lowestIndex = 0;
  for (int count = 0; count < size; count++) {
    if ( lowest > sale[count]) {
      lowest = sale[count];
      lowestIndex = count;
    }
  }
  cout << name[lowestIndex] << " salsa has the lowest sale among the others.\n";
}



void  displayReport(int sale[], string name[], int size) {
  cout << endl << setw(15) << left << "Sale Name" << "Sale" << endl;
  for (int count = 0; count < size; count++) {
    cout << setw(15) << left << name[count] << sale[count] << endl; 
  }

  findLowest(sale, name, size);
  findHighest(sale, name, size); 
}



int main() {

  string salsaNames[SIZE] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
  int salsaSales[SIZE];
  
  getSales(salsaSales, salsaNames, SIZE);
  
  displayReport(salsaSales, salsaNames, SIZE);

  return 0;

}
