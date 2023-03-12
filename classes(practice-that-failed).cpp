#include <iostream>
using namespace std;

class customer {
private:
    int* age = new int;
    string id, name, address, phone;

public:
    customer() {
        id = "0";
        name = "0";
        address = "0";
        phone = "0";
        age = 0;
    }

    customer(string id, string name, string address, string phone, int Age) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->phone = phone;
        *age = Age;
    }

    void setID(string id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void setPhone(string phone) {
        this->phone = phone;
    }

    void setAge(int *Age) {
        *age = *Age;
    }

    void setAge(int Age) {
        *age = Age;
    }

    string getID() {
        return id;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    string getPhone() {
        return phone;
    }

    int getAge() {
        return *age;
    }

    int* getAgePointer() {
        return age;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Age: " << *age << endl;
    }
};

int main() {

    int age = 31;
    int *agePtr = &age;
    customer c1;
    c1.setID("123");
    c1.setName("John");
    c1.setAddress("123, Main Street");
    c1.setPhone("1234567890");
    c1.setAge(agePtr);

    customer c2(c1);
    age = 40;
    c2.setAge(agePtr);

    c1.display();
    c2.display();

    return 0;
}