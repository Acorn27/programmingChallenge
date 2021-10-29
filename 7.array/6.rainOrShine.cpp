/*
This program is used to keep track of weather condition in 
three-month summer season. store the information in a 2-dimemsion
array that has 3 rows, each row has 31 columns. The program should:
  +read data from the a file names rainOrshine.txt
  +display number of rainy, sunny, cloudy day in each month and whole period
  +display month that has largest rainy days
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int NUMBER_OF_MONTHS = 3,
          NUMBER_OF_DAYS = 31;

void retrieveData(string[][NUMBER_OF_DAYS]);
void displayStats(stirng[][NUMBER_OF_DAYS]);

ifstream inputFile("RainOrShine.txt");

int main(){
  // create 2 dimension array to store weather information
  string weatherStats[NUMBER_OF_MONTHS][NUMBER_OF_DAYS];

  // retrieve data from file to inputFile
  retrieveData(weatherStats);

  //display statistic
  displayStats(weatherStats);

  // notify and terminate program
  inputFile.close();
  cout << "\nDone\n";
 return 0;
}

void retrieveData(string array[NUMBER_OF_MONTHS][NUMBER_OF_DAYS]) {
  char byte = 0;
  for (int month = 0; month < NUMBER_OF_MONTHS; month++) {
    for (int day = 0; day < NUMBER_OF_DAYS; day++) {
      while (inputFile.get(byte)) {
        array[month][day] = byte;
      }
    } 
  }
}

void displayStats(string array[NUMBER_OF_MONTHS][NUMBER_OF_DAYS]) {
  for (int month = 0; month < NUMBER_OF_MONTHS; month++) {
    for (int day = 0; day < NUMBER_OF_DAYS; day++) {
      if (array[month][day] = 
    }
  }

}
