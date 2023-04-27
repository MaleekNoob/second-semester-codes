#include <iostream>
using namespace std;

class Parent;
class Child;

class Parent {
    // Child* child;

public:
    // Parent(Child* child) {
    //     this->child = child;
    // }

    void print() {
        // child->print();
        cout << "Parent" << endl;
    }
};

class Child : public Parent {
public:
    // Child() : Parent(this) {}

    void print() {
        cout << "Child" << endl;
    }
};

int main() {
    Child* c = new Child();
    Parent* p = new Parent();
    c->print();
    p->print();
    return 0;
}