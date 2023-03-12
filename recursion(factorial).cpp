#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    // factorial of number
    int num;
    cout << "\nEnter a number: ";
    cin >> num;
    cout << "\nFactorial: " << factorial(num);

    return 0;
}