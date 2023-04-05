#include <iostream>
using namespace std;

class Fruit {
    protected:
    int number_of_fruits;

    public: 
    void calculate(int number_of_fruits) {
        this->number_of_fruits = number_of_fruits;
    }

    int getNumberOfFruits() {
        return number_of_fruits;
    }

};

class Apples: public Fruit {
    protected:
    int number_of_apples;

    public:
    void calculate(int number_of_apples) {
        this->number_of_apples = number_of_apples;
    }

    int getNumberOfApples() {
        return number_of_apples;
    }

};

class Mangoes: public Fruit {
    protected:
    int number_of_mangoes;

    public:
    void calculate(int number_of_mangoes) {
        this->number_of_mangoes = number_of_mangoes;
    }

    int getNumberOfMangoes() {
        return number_of_mangoes;
    }

};

int main() {

    Apples a;
    Mangoes m;

    a.calculate(10);
    m.calculate(10);

    cout << a.getNumberOfApples() << endl;
    cout << m.getNumberOfMangoes() << endl;
    

    return 0;

}