#include <iostream>
using namespace std;

class Engine {
    string engineNum;

    public:
    Engine(string engineNum = "") {
        this->engineNum = engineNum;
    }

    string getEngineNum() {
        return engineNum;
    }

    void setEngineNum(string engineNum) {
        this->engineNum = engineNum;
    }

    void display() {
        cout << "Engine number: " << engineNum << endl;
    }
};

class Car {
    string make;
    double price;
    Engine engine;  // Composition

    public:
    Car(string make = "", double price = 0.0, Engine engine = {""}) {
        this->make = make;
        this->price = price;
        this->engine = engine;
    }

    string getMake() {
        return make;
    }

    double getPrice() {
        return price;
    }

    Engine getEngine() {
        return engine;
    }

    void setMake(string make) {
        this->make = make;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setEngine(Engine engine) {
        this->engine = engine;
    }

    void display() {
        cout << "Make: " << make << ", Price: " << price << ", Engine ID: " << engine.getEngineNum() << endl;
    }
};

class Workshop {
    int numberOfVehicles, crew;
    Engine* engine;  // Aggregation

    public:
    Workshop(int numberOfVehicles = 0, int crew = 0, Engine* engine = nullptr) {
        this->numberOfVehicles = numberOfVehicles;
        this->crew = crew;
        this->engine = engine;
    }

    int getNumberOfVehicles() {
        return numberOfVehicles;
    }

    int getCrew() {
        return crew;
    }

    Engine* getEngine() {
        return engine;
    }

    void setNumberOfVehicles(int numberOfVehicles) {
        this->numberOfVehicles = numberOfVehicles;
    }

    void setCrew(int crew) {
        this->crew = crew;
    }

    void setEngine(Engine* engine) {
        this->engine = engine;
    }

    void display() {
        cout << "Number of vehicles: " << numberOfVehicles << ", Crew: " << crew << ", Engine ID: " << engine->getEngineNum() << endl;
    }
};

int main() {

    Engine engine1("1234567890");
    Car car1("Ford", 10000.00, engine1);
    engine1 = Engine("0987654321");
    Car car2("Toyota", 20000.00, engine1);
    cout << "Displaying cars:" << endl;
    car1.display();
    car2.display();

    Workshop workshop1(10, 5, &engine1);
    engine1 = Engine("4587881209");
    Workshop workshop2(20, 10, &engine1);
    cout << "Displaying workshops:" << endl;
    workshop1.display();
    workshop2.display();


    return 0;
}