/*
The following function uses reference variables as parameters.
Rewrite the function so it uses pointers instead of reference variables, 
then demonstrate the function in a complete program.
*/

#include <iostream>
using namespace std;

int doSomething(int* x, int* y) {
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	
  return (*x + *y);
}

int main() {
	
	int x = 10, y = 2;
	
	cout << "Before calling the function:\n"
	     << "x = " << x << endl
	     << "y = " << y << endl;
	
	cout << "The function returns "
	     << doSomething(&x,&y) << endl << endl;
			 
	cout << "After calling the function:\n"
	     << "x = " << x << endl
	     << "y = " << y << endl;
			 
	return 0;
}

