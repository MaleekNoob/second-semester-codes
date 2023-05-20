#include <iostream>
using namespace std;

class A {
    private:
    int a, b, c, d;

    public:
    A(int a, int b, int c) {
        cout << "Constructor called" << endl;
        this->a = a;
        this->b = b;
        this->c = c;
    }

    int getD() {
        return a;
    }

    void setD(int d) {
        this->d = d;
    }

    void display() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
    }

    ~A() {
        cout << "Destructor called" << endl;
    }
};

void function(A &a) {
    // In function. Set d = 10
    a.setD(10);
    a.display();
    // return a;
}

int main() {
    A a(1, 2, 3);
    function(a);
    a.display();
    return 0;
}