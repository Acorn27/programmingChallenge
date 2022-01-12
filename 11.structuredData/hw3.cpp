#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

struct InventoryItem {

	int partNumber;
	string description;
	int onHand;          // Units on hand
	double price;

};

void getItem(InventoryItem &structure) {
	
	cout << "Enter Part Number: ";
	cin >> structure.partNumber;
	cout << "Enter Part Description: ";
	cin.ignore();
	getline(cin, structure.description);
	cout << "Enter the quantity on hand: ";
	cin >> structure.onHand;
	cout << "Enter the unit price: ";
	cin >> structure.price;
	
};

void showItem(const InventoryItem &structure) {
	
	cout << setprecision(2) << fixed << showpoint;
	cout << "\nItem Description\n";
	cout << "Part's Number: " << structure.partNumber << endl;
	cout << "Description: " << structure.description << endl;
	cout << "Quantity on hand: " << structure.onHand << endl;
	cout << "Unit's price: $" << structure.price << endl;
}

int main() {
	
	InventoryItem part;
	
	getItem(part);
	
	showItem(part);
	
	return 0;
	
}