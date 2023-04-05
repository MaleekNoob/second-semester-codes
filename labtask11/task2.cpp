#include <iostream>
using namespace std;

class Car {
    string make, carModel, regNo, year;

public:
    Car() {
        this->make = "";
        this->carModel = "";
        this->regNo = "";
        this->year = "";
    }

    Car(string make, string carModel , string regNo , int year ) {
        this->make = make;
        this->carModel = carModel;
        this->regNo = regNo;
        this->year = year;
    }

    void setMake(string make) {
        this->make = make;
    }

    void setCarModel(string carModel) {
        this->carModel = carModel;
    }

    void setRegNo(string regNo) {
        this->regNo = regNo;
    }

    void setYear(string year) {
        this->year = year;
    }

    string getMake() {
        return make;
    }

    string getCarModel() {
        return carModel;
    }

    string getRegNo() {
        return regNo;
    }

    string getYear() {
        return year;
    }

};

class Garage {
    string name;
    int index;
    int capacity;
    Car *cars;

public:
    Garage() {
        this->name = "";
        this->index = 0;
        this->capacity = 0;
        this->cars = new Car[capacity];
    }

    Garage(string name, int index, int capacity) {
        this->name = name;
        this->index = index;
        this->capacity = capacity;
        this->cars = new Car[capacity];
    }

    bool isEmpty() {
        return (index == 0);
    }

    bool IsFull () {
        return (index == capacity);
    }

    bool Push (Car c) {
        if (IsFull()) {
            return false;
        }
        cars[index] = c;
        index++;
        return true;
    }

    bool Find (string reg) {
        for (int i = 0; i < capacity; i++) {
            if (cars[i].getRegNo() == reg) {
                return true;
            }
        }
        return false;
    }

    bool Remove (string reg) {
        if (isEmpty()) {
            return false;
        }

        for (int i = 0; i < capacity; i++) {
            if (cars[i].getRegNo() == reg) {
                for (int j = i; j < capacity - 1; j++) {
                    cars[j] = cars[j + 1];
                }
                index--;
                return true;
            }
        }

        return false;
    }

    void Display () {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Index: " << index << endl;
        for (int i = 0; i < index; i++) {
            cout << "Make: " << cars[i].getMake() << endl;
            cout << "Model: " << cars[i].getCarModel() << endl;
            cout << "Reg No: " << cars[i].getRegNo() << endl;
            cout << "Year: " << cars[i].getYear() << endl;
        }
    }


};

int main() {

    Garage g("Garage", 0, 5);

    Car c1("Toyota", "Corolla", "LHR 123", 2010);
    Car c2("Toyota", "Corolla", "LHR 124", 2010);
    Car c3("Toyota", "Corolla", "LHR 125", 2010);
    Car c4("Toyota", "Corolla", "LHR 126", 2010);
    Car c5("Toyota", "Corolla", "LHR 127", 2010);
    Car c6("Toyota", "Corolla", "LHR 128", 2010);

    g.Push(c1);
    g.Push(c2);
    g.Push(c3);
    g.Push(c4);
    g.Push(c5);
    g.Push(c6);

    cout << endl << "Find: " << g.Find("LHR 123");
    cout << endl << "Remove: " << g.Remove("LHR 123");
    cout << endl << "is Empty" << g.isEmpty();
    cout << endl << "is Full" << g.IsFull();

    g.Display();

    return 0;
}