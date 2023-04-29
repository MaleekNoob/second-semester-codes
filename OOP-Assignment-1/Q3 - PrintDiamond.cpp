/*
Name: Maleek Hussain Ali
Roll Number: 22i-1526
Section: B
*/


#include<iostream>
using namespace std;

void validation(int& n) {  //Validates user input for pattern
	while (n < 0) {
		cout << "\nPlease enter a positive number: ";
		cin >> n;
	}
}

void steric(int n) {  //prints out required sterics
	if (n > 0) {
		cout << '*';
		steric(n - 1);
	}
}

void spaces(int n) {  //Prints out required white spaces
	if (n > 0) {
		cout << ' ';
		spaces(n - 1);
	}
}

void upperPattern(int n, int counter) {  //Recursive funtions to print upper half of pattern
	if (counter < n) {  //Calls itself untill counter reaches given input value
		steric(n - counter);
		spaces(counter * 2);
		steric(n - counter);
		cout << endl;
		upperPattern(n, counter + 1);
	}
}

void lowerPattern(int n, int counter) {  //Recursive funtions to print upper half of pattern
	if (counter <= n) {  //Calls itself untill counter reaches given input value
		if (counter > 1) {
			steric(counter);
			spaces((n * 2) - (counter * 2));
			steric(counter);
			cout << endl;
		}
		lowerPattern(n, counter + 1);
	}
}

void printDiamond(int n)
{
	static int counter = 0;
	upperPattern(n, counter);
	lowerPattern(n, counter);
}

int main()
{
	int n;
	cout << "Enter Number of star: ";
	cin >> n;
	validation(n);
	printDiamond(n);
	return 0;
}
