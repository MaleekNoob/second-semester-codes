#include <iostream>
#include <fstream>

using namespace std;

// Structure to hold student information
struct Student {
    int rollNumber;
    string name;
    float marks;
};

// Function to add a student record to the binary file
void addStudentRecord(const string& filename) {
    Student student;

    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, student.name);

    cout << "Enter Marks: ";
    cin >> student.marks;

    // Open the file in binary append mode
    ofstream outfile(filename, ios::binary | ios::app);

    if (!outfile) {
        cerr << "Error opening file!" << endl;  // cerr: standard error stream
        return;
    }

    // Write the student record to the file
    outfile.write(reinterpret_cast<const char*>(&student), sizeof(Student));  // reinterpret_cast: converts one pointer type to another

    // Close the file
    outfile.close();

    cout << "Student record added successfully." << endl;
}

// Function to display all student records from the binary file
void displayStudentRecords(const string& filename) {
    // Open the file in binary mode
    ifstream infile(filename, ios::binary);

    if (!infile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Student student;

    cout << "Student Records:" << endl;

    // Read and display all student records from the file
    while (infile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Name: " << student.name << endl;
        cout << "Marks: " << student.marks << endl;
        cout << endl;
    }

    // Close the file
    infile.close();
}

// Function to update a student record in the binary file
void updateStudentRecord(const string& filename) {
    int rollNumber;

    cout << "Enter the Roll Number of the student to update: ";
    cin >> rollNumber;

    // Open the file in binary read-write mode
    fstream file(filename, ios::binary | ios::in | ios::out);

    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Student student;

    bool found = false;

    // Find the student record with the given roll number and update it
    while (!found && file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            found = true;

            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, student.name);

            cout << "Enter new Marks: ";
            cin >> student.marks;

            // Move the file pointer back by sizeof(Student) bytes
            file.seekp(-sizeof(Student), ios::cur);

            // Write the updated student record to the file
            file.write(reinterpret_cast<const char*>(&student), sizeof(Student));

            cout << "Student record updated successfully." << endl;
        }
    }

    // Close the file
    file.close();

    if (!found) {
        cout << "Student record not found." << endl;
    }
}

int main() {
    string filename = "students.dat";

    int choice;

    do {
        cout << "Binary File Handling Menu:" << endl;
        cout << "1. Add a Student Record" << endl;
        cout << "2. Display Student Records" << endl;
        cout << "3. Update a Student Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentRecord(filename);
                break;
            case 2:
                displayStudentRecords(filename);
                break;
            case 3:
                updateStudentRecord(filename);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
