#include <iostream>
using namespace std;

void print(int n) {
    if (n > 0) {
        print(n - 1);
        cout << '*';
    }
}

void pattern(int n) {
    if (n > 0) {
        cout << endl;
        print(n);
        pattern (n - 1);
    }
}

int bin_2_int(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10 + 2 * bin_2_int(n / 10));
    }
}

int main()
{
    int num;
    cout << "\nEnter number: ";
    cin >> num;
    pattern(num);

    return 0;
} // namespace std;

