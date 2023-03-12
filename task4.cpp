/*
 4.	Write a program that takes a two-digit number as input and outputs the sum of its digits or multiplication of its digits depending upon user’s choice.
*/

#include <iostream>
using namespace std;

int main() {
    int num, choice;
    cout << "Enter a two-digit number: ";
    cin >> num;
    cout << "Enter 1 for sum of digits or 2 for multiplication of digits: ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Sum of digits: " << (num / 10) + (num % 10);
            break;
        case 2:
            cout << "Multiplication of digits: " << (num / 10) * (num % 10);
            break;
        default:
            cout << "Error: Invalid choice.";
            break;
    }
    return 0;
}