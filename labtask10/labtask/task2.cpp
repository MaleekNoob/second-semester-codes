#include <iostream>
using namespace std;

class Employee {
    protected:
    string name;
    int empID;

    public:
    Employee(string name = " ", int empID = 0) {
        this->name = name;
        this->empID = empID;
    }
};

class HourlyEmployee: public Employee {
    protected:
    double hourlyIncome;

    public:
    HourlyEmployee(string name, int empID, double hourlyIncome = 0): Employee(name, empID) {
        this->hourlyIncome = hourlyIncome;
    }

    double calculate_the_hourly_income(int hours) {
        return (hourlyIncome * hours);
    }
};

class PermanentEmloyee: public Employee {
    protected:
    double HourlyIncome;

    public:
    PermanentEmloyee(string name, int empID, double HourlyIncome = 0): Employee(name, empID) {
        this->HourlyIncome = HourlyIncome;
    }

    double calculate_the_hourly_income(int hours) {
        return (HourlyIncome * hours);
    }
};


int main() {

    HourlyEmployee h("John", 1, 100);
    PermanentEmloyee p("John", 1, 100);

    cout << h.calculate_the_hourly_income(10) << endl;
    cout << p.calculate_the_hourly_income(10) << endl;

    return 0;
}