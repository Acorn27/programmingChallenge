#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159;

struct Circle {
	
	double radius;
	double diameter;
	double area;
	
};

// get structure data and return structure variable
Circle getData(Circle &var) {
	
	cout << "Enter the diameter of the circle: ";
	cin >> var.diameter;
	
	var.radius = var.diameter / 2;
	var.area = PI * pow(var.radius, 2);
	
	return var;
}

// display circle data
void showData(const Circle &var) {
	
	cout << setprecision(2) << fixed << showpoint;
	cout << "\nThe radius and area of the circle are: \n";
	cout << "Radius: " << var.radius << endl;
	cout << "Area: " << var.area << endl;

}

int main() {
	
	Circle myCircle;
	
	myCircle = getData(myCircle);
	
	showData(myCircle);
	
	return 0;
	
}