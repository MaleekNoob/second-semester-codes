#include <iostream>
using namespace std;

class Shapes {
    protected:
    int width, height;

    public:
    Shapes(int i = 0, int j = 0) {
        width = i;
        height = j;
        cout << endl << "Shapes class constructor called" << endl;
    }

    virtual int area() {
        cout << "Parent class area: " << endl;
        return 0;
    }
};

class Rectangle: public Shapes {
    public:
    Rectangle(int i = 0, int j = 0): Shapes(i, j) {
        cout << endl << "Rectangle class constructor called" << endl;
    }

    int area() {
        cout << "Rectangle class area: " << endl;
        return (width * height);
    }
};

class Triangle: public Shapes {
    public:
    Triangle(int i = 0, int j = 0): Shapes(i, j) {
        cout << endl << "Triangle class constructor called" << endl;
    }

    int area() {
        cout << "Triangle class area: " << endl;
        return (width * height / 2);
    }
};

// Multi-level inheritance

class Square: public Rectangle {
    protected:
    int width, height;

    public:
    Square(int i = 0, int j = 0): width(i), height(j), Rectangle(i, j) {
        cout << endl << "Square class constructor called" << endl;
    }

    int area() {
        cout << "Square class area: " << endl;
        return (width * height);
    }
};

// Multiple inheritance

class Cube: public Triangle, public Square {
    protected:
    int width, height;

    public:
    Cube(int i = 0, int j = 0): width(i), height(j) {
        cout << endl << "Cube class constructor called" << endl;
    }

    int area() {
        cout << "Cube class area: " << endl;
        return (width * height);
    }
};

int main() {

    Cube cube(10, 10);

    // store the address of Rectangle
    // shape = &rec;

    return 0;
}