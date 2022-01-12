#include <iostream>
#include <string>
using namespace std;

struct Contact {
	
	string name;
	string emailAddress;
	string phoneNumber;
	
};

Contact getData() {
	
	Contact c;
	cout << "Enter your name: ";
	getline(cin, c.name);
	cout << "Enter your email address: ";
	getline(cin, c.emailAddress);
	cout << "Enter your phone number: ";
	getline(cin,c.phoneNumber);
	
	return c;
}

int main() {
	
	auto [name, email, phone] = getData();
	cout << "\nYou entered\n";
	cout << "Name: " << name << endl;
	cout << "Email address: " << email << endl;
	cout << "Phone number: " << phone << endl;
	
	return 0;
	
}