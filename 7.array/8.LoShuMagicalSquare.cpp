/*
This program is called Lo Shu Magical Square
It is used to check if the two dimension array
that user entered is a Lo Shu Magical square or not
Requirement of magical square: 
  + the grid contains the number for 1 to 9
	+ The sum of each row, each column, each diagonal add up to the exact same number.
*/

#include <iostream>
using namespace std;

const int NUMBER_OF_ROWS = 3;
const int NUMBER_OF_COLUMNS = 3; 
const string columnName[NUMBER_OF_ROWS] = {"left", "middle", "right"};
const string rowName[NUMBER_OF_COLUMNS] = {"top", "middle", "bottom"};

void retrieveNumber(int[][NUMBER_OF_COLUMNS]);
bool checkColumn(int[][NUMBER_OF_COLUMNS]);
bool checkRow(int[][NUMBER_OF_COLUMNS]);
bool checkDiagonal(int[][NUMBER_OF_COLUMNS]);


int main() {
	
	int grid[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	
	retrieveNumber(grid);
	
	cout << endl;
	if (checkDiagonal(grid) && checkColumn(grid) && checkRow(grid)) {
		cout << "Good job! You entered a Lo Shu Magical Square";
	}
	
	cout << "\nDone.\n";
	return 0;
}

void retrieveNumber(int grid[][NUMBER_OF_COLUMNS]) {
	cout << "Enter value of your Lo Shu Magical Square.\n";
	for (int row = 0; row < NUMBER_OF_ROWS; row++) {
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++) {
			cout << "Enter value for " << rowName[row] << " " << columnName[column] << ": ";
			cin >> grid[row][column];
		}
	}
}

bool checkRow(int grid[][NUMBER_OF_COLUMNS]) {
	int topRow = grid[0][0] + grid[0][1] + grid[0][2];
	for (int row = 1; row < NUMBER_OF_ROWS; row++) {
		int nextRow = grid[row][0] + grid[row][1] + grid[row][2];
		if (topRow != nextRow) {
			cout << "This is not a Lo Shu Square.\n";
			cout << rowName[row] << "row's sum is not equal the other.\n";
			return (false);
		}
	}
	return (true);
}

bool checkColumn(int grid[][NUMBER_OF_COLUMNS]) {
	int leftColumn = grid[0][0] + grid[1][0] + grid[2][0];
	for (int column = 1; column < NUMBER_OF_COLUMNS; column++) {
		int nextColumn = grid[0][column] + grid[1][column] + grid[2][column];
		if (nextColumn != leftColumn) {
			cout << "This is not a Lo Shu Square.\n";
			cout << columnName[column] << " column's sum is not equal the other's.";
			return (false);
		}
	}
	return (true);
}

bool checkDiagonal(int grid[][NUMBER_OF_COLUMNS]) {
	int sumBackward = grid[0][0] + grid[2][2];
	int sumForward = grid[0][2] + grid[2][0];
	if (sumBackward != sumForward) {
		cout << "This is not a Lo Shu square.\n";
		cout << "Diagonal's sum is not equal each other.\n";
		return (false);
	} else {
		return (true);
	}
}