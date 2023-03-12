#include <iostream>
using namespace std;

class A {
    private:
    int a, b;

    public:
    A() {
        a = 0;
        b = 0;
    }

    A(int g):a(g) {}

    A(int a, int b) {
        this->a = a;
        this->b = b;
    }

    int getA() {
        return a;
    }

    int getB() {
        return b;
    }

    void setA(int a) {
        this->a = a;
    }

    void setB(int b) {
        this->b = b;
    }

    void display() {
        cout << endl << a << endl << b;
    }

    int operator + (int num) {
        return this->a + this->b + num;
    }

    A operator + (A &obj) {
        A obj2 = A(this->a + obj.a, this->b + obj.b);
        return obj2;
    }

    A operator << (A &obj) {
        cout << "\na = " << obj.a;
        cout << "\nb = " << obj.b;
    }

};



int main() {

    A a, b, c;
    a.setA(3);
    a.setB(6);

    b.setA(2);
    b.setB(3);

    c = a + b;

    a << c;

    return 0;
}