#include <iostream>
using namespace std;

template <typename T, typename T2>
void function(T &t, T2 &t2) {
    cout << "In function: Passed value is " << t << " and " << t2 << endl;
    t2 += t;
}

int main() {

    int a = 10, a1 = 20;
    float b = 10.5, b1 = 20.5;
    string c = "abracadabra", c1 = "alakazam";
    double d = 10.5, d1 = 20.5;

    function(a, b1);
    function(b, a1);
    function(c, c1);
    function(d, b1);

    cout << endl << "In main: a = " << a << " and a1 = " << a1 << endl;
    cout << "In main: b = " << b << " and b1 = " << b1 << endl;
    cout << "In main: c = " << c << " and c1 = " << c1 << endl;
    cout << "In main: d = " << d << " and d1 = " << d1 << endl;

    return 0;
}