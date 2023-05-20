#include <iostream>
using namespace std;

int main() {

    try {
        int a;
        cout << "Enter a number: ";
        cin >> a;

        if (!cin) {
            throw string("Invalid input. Input must be an Integer.");
        }

        if (a <= 0) {
            throw a;
        }

        if (a == 100) {
            throw 'a';  // dummy character to call eclipse
        }
    }
    catch(string s) {
        cout << "Error message:\n" << s;
    }

    catch(int a) {
        cout << "Program terminated due to unexcpected input\nInput: " << a;
    }

    catch(...) {
        cout << "OOPS";
    }

    return 0;
}