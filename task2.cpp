/*
 2.	Write a program that takes a character as input and outputs whether it is a digit or not. Implement this task using switch statement as well as by ternary operator.
*/

#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    //using switch statement
    switch (ch) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            cout << "It is a digit.";
            break;
        default:
            cout << "It is not a digit.";
            break;
    }

    //using ternary operator
    (ch >= '0' && ch <= '9') ? cout << "It is a digit." : cout << "It is not a digit.";
    
    return 0;
}