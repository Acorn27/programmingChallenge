/*
This program should ask user to enter file anme. Then display: 
  +the lowest and highest number in the array
  +total of numbers in the array
  +the average of number in the array
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void retrieveData(vector<int>&, string);
int returnHighest(vector<int>);
int returnLowest(vector<int>);
int returnTotal(vector<int>);
int returnAverage(vector<int>);

int main() {

  vector <int> numberList;
  string fileName;
  cout << "Enter file's name: ";
  cin >> fileName;

  retrieveData(numberList, fileName);

  int highest = returnHighest(numberList);
  int lowest = returnLowest(numberList);
  int total = returnTotal(numberList);
  int average = returnAverage(numberList);

  cout << endl;
  cout << "Highest number: " << highest << endl;
  cout << "Lowest number: " << lowest << endl;
  cout << "Total of numbes: " << total << endl;
  cout << "Average: " << average << endl;
  cout << endl;


  cout << "\nDone.\n";
  return 0;
}

void retrieveData(vector <int> &vector, string fileName) {
  ifstream inputFile(fileName);
  if (inputFile) {
    cout << "File opening success\n";
    int number;
    while (inputFile >> number) {vector.push_back(number);};
  } else {
    cout << "Error opening File. Please re-rerun program.\n";
  }
}

int returnHighest(vector<int> vector) {
  int size = vector.size();
  int highest = vector[0];
  for (int index = 1; index < size; index++) {
    (highest < vector[index] ? highest = vector[index] : highest = highest);
  }
  return (highest);
}

int returnLowest(vector<int> vector) {
  int size = vector.size();
  int lowest = vector[0];
  for (int index = 1; index < size; index++) {
    (lowest > vector[index] ? lowest = vector[index] : lowest = lowest);
  }
  return (lowest);
}

int returnTotal(vector<int> vector) {
  int size = vector.size();
  int total = 0;
  for (int index = 0; index < size; index++) {
    total += vector[index];
  }
  return (total);
}

int returnAverage(vector<int> vector) {
  int size = vector.size();
  int total = 0;
  for (int index = 0; index < size; index++) {
    total += vector[index];
  }
  return (total / size);

}



