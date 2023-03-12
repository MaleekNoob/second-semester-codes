#include <iostream>
using namespace std;

class A {
    private:
    int a;
    int &cRef = a;

    public:
    A() {
        a = 0;
    }

    A(int &A): a(A) {}

    int getA() {
        return a;
    }

    void setA(int A) {
        a = A;
    }

    void display() {
        cout << "a: " << a << endl;
    }

    ~A() {
        cout << "Destructor called" << endl;
    }
};

int main() {

    int num;
    A* a1 = new A[10];
    A* aPtr = a1;

    for (int i = 0; i < 10; i++) {
        cout << "Enter number: ";
        cin >> num;
        a1[i].setA(num);
    }

    for (int i = 0; i < 10; i++) {
        cout << endl << (aPtr + i)->getA();
    }


    return 0;
}