#include <iostream>
using namespace std;


int main() {
    int num = 10;
    void *p;
    int *p1 = &num;
    p = p1;
    cout << p << endl;
    cout << p1 << endl;
    // p1 = NULL;
    return 0;
}