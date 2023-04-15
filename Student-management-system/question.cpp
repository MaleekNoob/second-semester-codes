#include <iostream>
#include <fstream>
using namespace std;

class Address {
    string house, street, city;

    public:
    Address(string house = "", string street = "", string city ="") {
        this->house = house;
        this->street = street;
        this->city = city;
    }

    string getHouse() {
        return house;
    }

    string getStreet() {
        return street;
    }

    string getCity() {
        return city;
    }
};

class Person {
    protected:
    string cnic, name, contact;
    Address a;

    public:
    Person(string cnic = "", string name = "", string contact = "", string house = "", string street = "", string city = ""): a(house, street, city) {
        this->cnic = cnic;
        this->name = name;
        this->contact = contact;
    }

    string getHouse() {
        return a.getHouse();
    }

    string getStreet() {
        return a.getStreet();
    }

    string getCity() {
        return a.getCity();
    }

    string getName() {
        return name;
    }
};

class Student: public Person {
    string rollNo, program, courses[5];
    float cgpa;

    public:
    Student(string rollNo = "", string program = "", float cgpa = 0.0, string cnic = "", string name = "", string contact = "", string house = "", string street = "", string city = "") : Person(cnic, name, contact, house, street, city) {
        this->rollNo = rollNo;
        this->program = program;
        this->cgpa = cgpa;
    }

    void setCourses(const string courses[] = {}) {
        for (int i = 0; i < 5; i++) {
            // cout << "Successfully read " << courses[i] << endl;
            this->courses[i] = courses[i];
        }
    }

    void setCourses(string course, int i) {
        this->courses[i] = course;
    }

    string getRollNo() {
        return rollNo;
    }

    float getCGPA() {
        return cgpa;
    }

    string* getCourses() {
        return courses;
    }

    void display() {
        cout << endl << "Name: " << name << endl << "CNIC: " << cnic << endl << "Roll No: " << rollNo << endl << "CGPA: " << cgpa << endl << "Program: " << program << endl << "Contact: " << contact << endl << "House: " << getHouse() << endl << "Street: " << getStreet() << endl << "City: " << getCity() << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Course " << i + 1 << ": " << this->courses[i] << endl;
        }
    }
};

class Faculty: public Person {
    string empNo, designation, joiningDate, courses[3];

    public: 
    Faculty(string empNo = "", string designation = "", string joiningDate = "", string cnic = "", string name = "", string contact = "", string house = "", string street = "", string city = "") : Person(cnic, name, contact, house, street, city) {
        this->empNo = empNo;
        this->designation = designation;
        this->joiningDate = joiningDate;
    }

    void setCourses(string courses[] = {}) {
        for (int i = 0; i < 3; i++) {
            this->courses[i] = courses[i];
        }
    }

    void display() {
        cout << endl << "Name: " << name << endl << "CNIC: " << cnic << endl << "Employee No: " << empNo << endl << "Designation: " << designation << endl << "Joining Date: " << joiningDate << endl << "Contact: " << contact << endl << "House: " << getHouse() << endl << "Street: " << getStreet() << endl << "City: " << getCity() << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Course " << i + 1 << ": " << courses[i] << endl;
        }
    }
};

class Course: public Student, public Faculty {
    string title, code, stream;
    int crdHrs;

    public: 
    Course(string title ="", string code ="", string stream ="", int crdHrs = 0) {
        this->title = title;
        this->code = code;
        this->stream = stream;
        this->crdHrs = crdHrs;
    }

    string getTitle() {
        return title;
    }

    string getCode() {
        return code;
    }

    void display() {
        cout << endl << "Title: " << title << endl << "Code: " << code << endl << "Stream: " << stream << endl << "Credit Hours: " << crdHrs << endl;
    }
};

class Classroom: public Course {
    string roomNo, floor;
    int capacity;

    public:
    Classroom(string roomNo = "", string floor = "", int capacity = 0) {
        this->roomNo = roomNo;
        this->floor = floor;
        this->capacity = capacity;
    }
};

string excludeWhiteSpaces(string str) {
    string newStr = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            newStr += str[i];
        }
    }
    return newStr;
}

string substring(string str, int start, int end) {
    string sub = "";
    for (int i = start; i < end; i++) {
        sub += str[i];
    }
    return sub;
}

string substring(const char* str, int start, int end) {
    string sub = "";
    for (int i = start; i < end; i++) {
        sub += str[i];
    }
    return sub;
}

string substring(char* str, int start, int end) {
    string sub = "";
    for (int i = start; i < end; i++) {
        sub += str[i];
    }
    return sub;
}

int stringToInt(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

int main() {

    Student s[450];
    string rollNo, program, courses[5], cnic, name, contact, house, street, city, trash;
    float cgpa;
    fstream myfile1, myfile2, myfile3, myfile4, myfile5;
    myfile1.open("Student_add.txt");
    myfile2.open("Std_regd_courses.txt");
    myfile3.open("Faculty_add.txt");
    myfile4.open("Faculty_assigned_courses.txt");
    myfile5.open("Courses.txt");

    if (myfile1.fail()) {
        cout << endl << "Error in opening the Student_add.txt";
        exit(0);
    }

    if (myfile2.fail()) {
        cout << endl << "Error in opening the Std_regd_courses.txt";
        exit(0);
    }

    if (myfile3.fail()) {
        cout << endl << "Error in opening the Faculty_add.txt";
        exit(0);
    }

    if (myfile4.fail()) {
        cout << endl << "Error in opening the Faculty_assigned_courses.txt";
        exit(0);
    }

    if (myfile5.fail()) {
        cout << endl << "Error in opening the Courses.txt";
        exit(0);
    }

    for (int i = 0; i < 450; i++) {

        myfile1 >> name >> cnic >> rollNo >> cgpa >> program >> contact >> house >> street >> city;

        s[i] = Student(rollNo, program, cgpa, cnic, name, contact, house, street, city);

        myfile2 >> trash >> courses[0] >> courses[1] >> courses[2] >> courses[3] >> courses[4];

        for (int j = 0; j < 5; j++) {
            s[i].setCourses(courses[j], j);
        }
    }

    Faculty f[50];
    string empNo, designation, joiningDate;

    for (int i = 0; i < 50; i++) {

        myfile3 >> name >> cnic >> empNo >> designation >> contact >> joiningDate >> house >> street >> city;

        f[i] = Faculty(empNo, designation, joiningDate, cnic, name, contact, house, street, city);

        for (int i = 0; i < 3; i++) {
            myfile4 >> courses[i];
        }

        f->setCourses(courses);
    }

    Course c[40];
    string line;
    string code, title, stream;
    int credit_hours;

    for(int i = 0; i < 40; i++) {
        getline(myfile5, code, '\t');
        getline(myfile5, title, '\t');
        myfile5 >> credit_hours;
        getline(myfile5, stream, '\n');
        c[i] = Course(title, code, excludeWhiteSpaces(stream), credit_hours);
    }

    myfile1.close();
    myfile2.close();
    myfile3.close();
    myfile4.close();

    int choice;
    while (1)
    {
        cout << endl << "\n1-Students belonging to given city\n2-Print detail of student according to given input\n3-Print course details of particular student according to given roll number\n4-Display all students enrolled in particular course according to given course code\n5-Terminate Student management app\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl << "Enter city name to display all Students belonging to that city: ";
            cin >> city;

            for (int i = 0; i < 450; i++) {
                if (s[i].getCity() == city) {
                    s[i].display();
                }
            }
            break;

        case 2:
            cout << endl << "Enter roll Number of Student to print his/her details: ";
            cin >> rollNo;

            for (int i = 0; i < 450; i++) {
                if (s[i].getRollNo() == rollNo) {
                    s[i].display();
                }
            }
            break;

        case 3:
            cout << endl << "Enter roll number for a particular student: ";
            cin >> rollNo;

            for (int i = 0; i < 450; i++) {
                if (s[i].getRollNo() == rollNo) {
                    for (int j = 0; j < 5; j++)
                    {    
                        for (int k = 0; k < 40; k++ )
                            if (s[i].getCourses()[j] == c[k].getCode()) {
                                cout << endl << "Course Title: " << c[k].getTitle();
                                cout << endl << "Course Code: " << c[k].getCode();
                                break;
                            }
                    }
                }
            }
            break;

        case 4:
            cout << endl << "Enter course code to display all students enrolled in that course: ";
            cin >> code;

            for (int i = 0; i < 450; i++) {
                for (int j = 0; j < 5; j++) {
                    if (s[i].getCourses()[j] == code) {
                        s[i].display();
                    }
                }
            }
            break;

        case 5:
            exit(0);

        default:
            cout << endl << "Error! please input again" << endl;
            break;
        }

    }

    return 0;
}