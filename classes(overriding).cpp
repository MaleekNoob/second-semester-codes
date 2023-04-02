#include <iostream>
using namespace std;

class Class1 {
    int a, b;

    public: 
    Class1(int i = 0, int j = 0) {
        a = i;
        b = j;
        cout << endl << "Class1 constructor called" << endl;
    }

    void func1() {
        cout << "Class1 func1 called" << endl;
    }
};

class Class2: public Class1 {
    int c, d;

    public:
    Class2(int i = 0, int j = 0, int k = 0, int l = 0): Class1(i, j) {
        c = k;
        d = l;
        cout << endl << "Class2 constructor called" << endl;
    }

    void func2() {
        cout << "Class2 func2 called" << endl;
    }
};

class Class3: public Class2 {
    int e, f;

    public: 
    Class3(int i = 0, int j = 0, int k = 0, int l = 0, int m = 0, int n = 0): Class2(i, j, k, l) {
        e = m;
        f = n;
        cout << endl << "Class3 constructor called" << endl;
    }
};

int main() {



    return 0;
}