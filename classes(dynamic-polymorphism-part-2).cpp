#include <iostream>
using namespace std;

class Address;
class Person;
class Student;
class Employee;

class Address {
protected:
   int houseNum, street;
   string city;

public:
   Address(int houseNum = 0, int street = 0, string city = "") {
       this->houseNum = houseNum;
       this->street = street;
       this->city = city;
   }

   friend ostream& operator << (ostream& out, Address& address);
};

ostream& operator << (ostream& out, Address& address) {
   out << endl << "House Number: " << address.houseNum;
   out << endl << "Street: " << address.street;
   out << endl << "City: " << address.city;
   return out;
}

class Person {
protected:
   string name;
   int age;
   Address address;

public:
   Person(string name = "", int age = 0, Address address = {0, 0, ""}) {
       this->name = name;
       this->age = age;
       this->address = address;
   }

   virtual void func() const=0;

   virtual void display() {
		cout << endl << "Name: " << name;
		cout << endl << "Age: " << age;
		cout << endl << "address: " << address;
	}
};

class Student : public Person {
protected:
   string rollNo;
   char grade;

public:
   Student(string rollNo, char grade, string name, int age, Address address): Person(name, age, address) {
       this->rollNo = rollNo;
       this->grade = grade;
       this->name = name;
       this->age = age;
       this->address = address;
   }

   void display() {
       cout << endl << "Name: " << name;
       cout << endl << "Age: " << age;
       cout << endl << "Roll Number: " << rollNo;
       cout << endl << "Grade: " << grade;
       cout << endl << "address: " << address;
   }
};

class Employee : public Person {
protected:
	string empId;
	string designation;

public:
   Employee(string empId, string designation, string name, int age, Address address): Person(name, age, address) {
		this->empId = empId;
		this->designation = designation;
		this->name = name;
		this->age = age;
		this->address = address;
	}

	void display() {
		cout << endl << "Name: " << name;
		cout << endl << "Age: " << age;
		cout << endl << "Employee ID: " << empId;
		cout << endl << "Designation: " << designation;
		cout << endl << "address: " << address;
	}
};

class Classroom {
protected:
	Person** persons;
	int size;

public:
   Classroom(Person** persons, int size) {
		this->persons = persons;
		this->size = size;
	}

   void display() {
       for (int i = 0; i < size; i++) {
			persons[i]->display();
		}
	}

};

int main() {

   cout << "Code by: @MaleekNoob";

   return 0;
}