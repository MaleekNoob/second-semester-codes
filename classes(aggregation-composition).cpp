#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declarations
class Engine;
class Car;
class Person;

// Engine class (part of Car)
class Engine {
public:
    Engine(string type) : type(type) {}

    string getType() {
        return type;
    }

private:
    string type;
};

// Car class (composed of Engine)
class Car {
public:
    Car(string make, string model, Engine* engine) : make(make), model(model), engine(engine) {}

    string getMake() {
        return make;
    }

    string getModel() {
        return model;
    }

    Engine* getEngine() {
        return engine;
    }

private:
    string make;
    string model;
    Engine* engine;
};

// Person class (aggregates Cars)
class Person {
public:
    Person(string name) : name(name) {}

    void addCar(Car* car) {
        cars.push_back(car);
    }

    string getName() {
        return name;
    }

    void printCars() {
        Car* car;
        cout << name << "'s cars:" << endl;
        for (int i = 0; i < cars.size(); i++) {
            car = cars[i];
            cout << "\tMake: " << car->getMake() << ", Model: " << car->getModel() << ", Engine Type: " << car->getEngine()->getType() << endl;
        }
    }

private:
    string name;
    vector<Car*> cars;
};

int main() {
    // Create engine
    Engine* engine = new Engine("V8");

    // Create car with engine
    Car* car = new Car("Ford", "Mustang", engine);

    // Create person and add car
    Person* person = new Person("John");
    person->addCar(car);

    // Print person's cars
    person->printCars();

    // Clean up
    delete engine;
    delete car;
    delete person;

    return 0;
}