#include <iostream>
using namespace std;

void asending_order(int n) {
    if (n > 0) {
        // cout << ' ' << n; /* incase of desending */
        asending_order(n - 1);
        cout << ' ' << n;
    }
}

int main() {
    int num;
    cout << "\nEnter number: ";
    cin >> num;
    asending_order(num);

    return 0;
}