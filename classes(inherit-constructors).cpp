#include <iostream>
using namespace std;

class A {
    public:
    A() {
        cout << 1;
    }

    ~A() {
        cout << -1;
    }
};

class B: virtual public A {
    public:
    B() {
        cout << 2;
    }

    ~B() {
        cout << -2;
    }
};

class C: virtual public B {
    public:
    C() {
        cout << 3;
    }

    ~C() {
        cout << -3;
    }
};

class D: public A, public B, public C {
    public:
    D() {
        cout << 4;
    }

    ~D() {
        cout << -4;
    }
};

int main() {
    D d;
    return 0;
}