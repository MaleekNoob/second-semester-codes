#include <iostream>
#include <cmath>
using namespace std;

int reverseNumber(int n) {

    int i = -1;
    int temp = n;
    while (temp > 0) {
        i++;
        temp /= 10;
    }

    if (n % 10 == n) {
        return n;
    }
    else {
        return ((n % 10) * (pow(10, i))) + reverseNumber(n / 10);
    }

    return NULL;
}

int main() {
    int num, i;
    cout << "\nEnter number: ";
    cin >> num;

    cout << "\nReverse number is " << reverseNumber(num);

    return 0;
}
