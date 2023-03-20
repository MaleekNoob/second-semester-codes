#include <iostream>
using namespace std;

class usingSubscript {
    int a[10];

    public:
    usingSubscript() {
        for (int i = 0; i < 10; i++) {
            a[i] = i;
        }
    }

    usingSubscript(int i[]) {
        for (int j = 0; j < 10; j++) {
            a[j] = i[j];
        }
    }

    int& operator[](int i) {
        return a[i];
    }
};

int main() {

    usingSubscript obj1;
    cout << endl << obj1[5] << endl;


    return 0;
}