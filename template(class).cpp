#include <iostream>
using namespace std;

template <typename T, class T2>
class Pair {
    private:
    T a;
    T2 b;

    public:
    Pair() {
        a = 0;
        b = 0;
    }
    
    Pair<T, T2>(T a, T2 b);

    void setA(T a) {
        this->a = a;
    }

    void setB(T2 b) {
        this->b = b;
    }

    T getA() {
        return a;
    }

    T2 getB() {
        return b;
    }

    T2 sum() {
        return a + b;
    }

    void display() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

template <typename T, class T2>
Pair<T, T2>::Pair(T a, T2 b) {
    this->a = a;
    this->b = b;
}

int main() {

    int a = 10, b = 20;
    Pair<int, float> p;
    p.display();
    b = 30;
    p.setB(b);
    p.display();
    a = 40;
    p.setA(a);
    p.display();
    cout << endl;
    cout << "a = " << p.getA() << endl;
    cout << "b = " << p.getB() << endl;
    cout << "sum = " << p.sum() << endl;

    return 0;
}