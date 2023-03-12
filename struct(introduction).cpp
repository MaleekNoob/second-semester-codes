#include <iostream>
using namespace std;

struct employee {
    string name;
    int age;
    long long cnic;
} person1, person2, person3;

int main() {
    
    employee person = {"Ahmed", 24, 3830241324557};

    cout << "Name: " << person.name;
    cout << endl << "Age: " << person.age;
    cout << endl << "CNIC: " << person.cnic;

    cout << "Name: " << person1.name;
    cout << endl << "Age: " << person1.age;
    cout << endl << "CNIC: " << person1.cnic;

    cout << "Name: " << person2.name;
    cout << endl << "Age: " << person2.age;
    cout << endl << "CNIC: " << person2.cnic;

    cout << "Name: " << person3.name;
    cout << endl << "Age: " << person3.age;
    cout << endl << "CNIC: " << person3.cnic;

    return 0;
}