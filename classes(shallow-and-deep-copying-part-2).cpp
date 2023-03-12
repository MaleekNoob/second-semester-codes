#include <iostream>
#include <cstring>
using namespace std;

class class1 {
    private:
    char* name;
    int age;

    public: 
    class1() {
        name = new char[20];
    }
    
    class1(char name[], int Age) {
        name = new char[20];
        strcpy(this->name, name);
        age = Age;
    }

    // class1(class1 &c) {
    //     name = new char[20];
    //     strcpy(name, c.name);
    //     age = c.age;
    // }

    char* getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    void setAge(int Age) {
        age = Age;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {

    // we will deep copy the object of class
    int age;
    char name[100];
    class1 c1;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    c1.setName(name);
    c1.setAge(age);
    cout << "\nC1: ";
    c1.display();
    class1 c2(c1);
    cout << "\nC2: ";
    c2.display();
    cout << "Enter name: ";
    cin >> name;
    c1.setAge(age);
    c2.setName(name);
    cout << "\nC1: ";
    c1.display();
    cout << "\nC2: ";
    c2.display();

    return 0;
}