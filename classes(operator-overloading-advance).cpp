#include <iostream>
using namespace std;

class Calculation {

    private:
    int a;

    public:
    Calculation(int i = 0) {
        a = i;
    }

    int getA() {
        return a;
    }

    void setA(int a) {
        this->a = a;
    }

    ~Calculation() {}

    Calculation operator + (Calculation obj) {
        Calculation temp;
        temp.a = a + obj.a;
        return temp;
    }

    Calculation operator * (Calculation obj) {
        Calculation temp;
        temp.a = a * obj.a;
        return temp;
    }

    Calculation operator / (Calculation obj) {
        Calculation temp;
        temp.a = a / obj.a;
        return temp;
    }

    void operator++() {
        a++;
    }

    void operator++(int i) {
        a++;
        i++;
    }

    void operator ~ () {
        display();
    }

    // int operator + (int a) {
    //     return this->a + a;
    // }

    void display() {
        cout << endl << "a = " << a;
    }

};

int operator+(Calculation obj) {
    return obj.getA();
}

int main() {

    Calculation meow(4), meow1(2), meow2(4), meow3(4);
    Calculation meowN = (meow * meow1) + (meow2 / meow3);
    
    ~meowN;


    return 0;
}