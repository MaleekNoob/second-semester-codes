#include <iostream>
#include <conio.h>
using namespace std;

string input() {
    string mainStr;
    char character;

    do
    {
        if (static_cast<int>(character) != 8) {
            mainStr += character;
        }

        character = getche();

        if (static_cast<int>(character) == 8) {
                mainStr.pop_back();
        }
    } while (static_cast<int>(character) != 13);
    
    return mainStr;
}

struct employee {
    int salary;
    string name;
    int employeeId;

};

struct boss {
    long revenue;
    string name;
    string companyName;

};

int main() {

    employee *ptr1, person;
    boss *ptr2, boss1;

    string str1, str2;

    cout << "\nEnter employee's name: ";
    str1 = input();
    // cin >> person.name;
    cout << "\nEnter boss company name: ";
    str2 = input();
    // cin >> boss1.companyName;
    cout << "\nEmployee name: " << str1;
    cout << "\nBoss company name: " << str2;

    return 0;
}