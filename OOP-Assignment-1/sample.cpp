#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int input(char& ch) {
    // intch; 
   ch = _getch();
//    cout << endl << static_cast<int>(ch);
    return static_cast<int>(ch);
}

int STRLEN(string s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

bool validation(string s) {
    if (STRLEN(s) == 8) {
        for (int i = 0; i < STRLEN(s); i++) {
            if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^' || s[i] == '&' || s[i] == '*') {
                break;
            }
            if (i == STRLEN(s) - 1) {
                cout << endl << "Atleast one special character is required." << endl;
                return true;
            }
        }

        for (int i = 0; i < STRLEN(s); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                break;
            }

            if (i == STRLEN(s) - 1) {
                cout << endl << "Atleast one uppercase letter is required." << endl;
                return true;
            }
        }

        for (int i = 0; i < STRLEN(s); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                break;
            }

            if (i == STRLEN(s) - 1) {
                cout << endl << "Atleast one lowercase letter is required." << endl;
                return true;
            }
        }

        for (int i = 0; i < STRLEN(s); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                break;
            }

            if (i == STRLEN(s) - 1) {
                cout << endl << "Atleast one numeric digit is required." << endl;
                return true;
            }
        }

        return false;
    }
    else if (STRLEN(s) < 8) {
        cout << endl << "Password must be atleast 8 characters long." << endl;
        return true;
    }
    else if (STRLEN(s) > 8) {
        cout << endl << "Password should maximum have 8 characters." << endl;
        return true;
    }
    else {
        return false;
    }
}

string enterPassword(string s) {
    string password;
    char c;
    do {

        password = "";
        cout << "Enter your password: ";
        while(input(c) !=  13) {
            password += c;
            cout << '*'; // display asterisks instead of actual password characters
        }

    } while (validation(password));

    return password;
}

int main() {
  string password;
//   char c;
  
  password = enterPassword(password);
  
  cout << endl;
  cout << "Your password is: " << password << endl;
  
  return 0;
}