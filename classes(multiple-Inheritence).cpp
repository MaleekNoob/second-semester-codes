#include <iostream>
#include <cstring>
using namespace std;

class Human {
    protected:
    char* gender;
    int age;

    public:
    Human() {
        this->gender = new char;
        *this->gender = '\0';
        this->age = 0;
    }

    Human(char* gender, int age) {
        this->gender = new char[strlen(gender) + 1];
        for (int i = 0; i < strlen(gender); i++) {
            this->gender[i] = gender[i];
        }
        this->age = age;
    }

    Human(Human &h) {
        this->gender = new char[strlen(h.gender) + 1];
        for (int i = 0; i < strlen(h.gender); i++) {
            this->gender[i] = h.gender[i];
        }
        this->age = h.age;
    }

    virtual void display() {
        cout << endl << "Gender: " << this->gender << endl;
        cout << "Age: " << this->age << endl;
    }
};

class Person: public virtual Human {
    protected:
    char* name;
    int index;

    public:
    Person() {
        this->name = new char;
        *this->name = '\0';
        this->age = 0;
    }

    Person(char* name, int age) {
        this->name = new char[strlen(name) + 1];
        for (int i = 0; i < strlen(name); i++) {
            this->name[i] = name[i];
        }
        this->age = age;
    }

    Person(Person &p) {
        this->name = new char[strlen(p.name) + 1];
        for (int i = 0; i < strlen(name); i++) {
            this->name[i] = p.name[i];
        }
        this->age = p.age;
    }

    void display() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
    }
};

class Citizen: public virtual Human {
    protected:
    char* ID;
    char* country;
    int index;

    public:
    Citizen() {
        this->ID = new char;
        *this->ID = '\0';
        this->country = new char;
        *this->country = '\0';
    }

    Citizen(char* ID, char* country) {
        this->ID = new char[strlen(ID) + 1];
        for (int i = 0; i < strlen(ID); i++) {
            this->ID[i] = ID[i];
        }
        this->country = new char[strlen(country) + 1];
        for (int i = 0; i < strlen(country); i++) {
            this->country[i] = country[i];
        }
    }

    Citizen(Citizen &c) {
        this->ID = new char[strlen(c.ID) + 1];
        for (int i = 0; i < strlen(ID); i++) {
            this->ID[i] = c.ID[i];
        }
        this->country = new char[strlen(c.country) + 1];
        for (int i = 0; i < strlen(country); i++) {
            this->country[i] = c.country[i];
        }
    }

    void display() {
        cout << "ID: " << this->ID << endl;
        cout << "Country: " << this->country << endl;
    }
};

class Employee: public Person, public Citizen {
    char* empID;
    int yearsInOffice;

    public:
    Employee() {
        this->empID = new char;
        *this->empID = '\0';
        this->yearsInOffice = 0;
        // index = 0;
    }

    Employee(char* empID, int years) {
        this->empID = new char[strlen(empID) + 1];
        for (int i = 0; i < strlen(empID); i++) {
            this->empID[i] = empID[i];
        }
        this->yearsInOffice = years;
    }

    Employee(Employee &e) {
        this->empID = new char[strlen(e.empID) + 1];
        for (int i = 0; i < strlen(empID); i++) {
            this->empID[i] = e.empID[i];
        }
        this->yearsInOffice = e.yearsInOffice;
    }

    void display() {
        cout << "Employee ID: " << this->empID << endl;
        cout << "Years in Office: " << this->yearsInOffice << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {

    // testing function overriding
    char* char_Arr;
    char_Arr = new char[30];
    int age;
    cout << "\nEnter Gender: ";
    cin >> char_Arr;
    cout << "\nEnter age: ";
    cin >> age;
    Human h1(char_Arr, age);
    char* char_Arr1;
    char_Arr1 = new char[30];
    cout << "\nEnter ID: ";
    cin >> char_Arr;
    cout << "\nEnter Country: ";
    cin >> char_Arr1;
    Person p1(char_Arr, age);
    Citizen c1(char_Arr, char_Arr1);
    Employee e1(char_Arr, age);
    cout << "\nHuman: ";
    h1.display();
    cout << "\nPerson: ";
    p1.display();
    cout << "\nCitizen: ";
    c1.display();
    cout << "\nEmployee: ";
    e1.display();


    return 0;
}