#include <iostream>
using namespace std;

int fabonacci(int n) {
    if (n == 1) {
        return 1;
    } else if (n <= 0) {
        return 0;
    } else {
        return (fabonacci(n - 1) + fabonacci(n - 2));
    }
}

int main() {
    int index;
    cout << "\nEnter fabonacci index: ";
    cin >> index;
    cout << "\nValue: " << fabonacci(index);

    return 0;
}

