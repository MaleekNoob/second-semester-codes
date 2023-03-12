/*
 1.	Write a program that takes a one-digit number (0 to 9) as input and outputs the corresponding Morse code. Display an error message if number is not single digit. Implement it using switch statement.
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number between 0 and 9: ";
    cin >> num;
    switch (num)
    {
        case 0:
            cout << "-----";
            break;
        case 1:
            cout << ".----";
            break;
        case 2:
            cout << "..---";
            break;
        case 3:
            cout << "...--";
            break;
        case 4:
            cout << "....-";
            break;
        case 5:
            cout << ".....";
            break;
        case 6:
            cout << "-....";
            break;
        case 7:
            cout << "--...";
            break;
        case 8:
            cout << "---..";
            break;
        case 9:
            cout << "----.";
            break;
        default:
            cout << "Error: Number is not single digit.";
            break;
    }
    return 0;
}

