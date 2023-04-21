#include <iostream>
#include <cstring>
using namespace std;

class Employee {
	string firstName, lastName;
	char initial;

public:
	Employee(string f, string l, char i) {
		firstName = f;
		lastName = l;
		initial = i;
	}

	~Employee() {}

	virtual void display() = 0;

	void print() const {
		cout << endl << "First name: " << firstName;
		cout << endl << "Last name: " << lastName;
		cout << endl << "Initial: " << initial;

	}
};

class SalaryEmployee : public Employee {
	double salary;

public:
	SalaryEmployee(string f , string l, char i, double s = 0) : Employee(f, l, i) {
		salary = s;
	}

	~SalaryEmployee() {}

	void display() {
		Employee::print();
		cout << endl << "Salary: " << salary;
	}

};

class HourlyEmployee : public Employee {
	int numberOfHours;
	float rate;

public:
	HourlyEmployee(string f, string l, char i , int n =0, float r = 0) : Employee(f, l, i) {
		numberOfHours = n;
		rate = r;
	}

	~HourlyEmployee() {}

	void display() {
		Employee::print();
		cout << endl << "Wage: " << (numberOfHours * rate);
	}
};

int main() 
{

	SalaryEmployee s("Hussain", "Ali", 'H', 150000);
	s.display();
	HourlyEmployee h("Hamza", "Bhatti", 'H', 27, 1200);
	h.display();

	return 0;
}