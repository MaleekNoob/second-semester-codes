#include <iostream>
using namespace std;

int power(int num, int pow) {
    if (pow == 0) {
        return 1;
    }
    else {
        return num * power(num, pow - 1);
    }
}

int main() {
    int num, pow;
    cout << "\nEnter number da: ";
    cin >> num;
    cout << "\nEnter power da: ";
    cin >> pow;
    cout << "\nThe answer is " << power(num, pow);

    return 0;
}