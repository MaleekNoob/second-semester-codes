#include <iostream>
using namespace std;

int main() {

    char str;
    int counter = 0;
    cout << "Enter string: ";
    cin >> str;
    
        if (str >= '0' && str <= '9')
            cout << str;
        else 
            switch(str) {
                case 'A':
                cout << 10;
                break;
                case 'B':
                cout << 11;
                break;
                case 'C':
                cout << 12;
                break;
                case 'D':
                cout << 13;
                break;
                case 'E':
                cout << 14;
                break;
                case 'F':
                cout << 15;
                break;
                default:
                cout << "cannot exist";
                break;
            }

    return 0;
}