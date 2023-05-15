#include <iostream>
#include <string>

using namespace std;

// Animal class (base class)
class Animal {
public:
    Animal(string name) : name(name) {}

    // Virtual function that will be overridden by derived classes
    virtual void speak() {
        cout << "I am an animal." << endl;
    }

protected:
    string name;
};

// Dog class (derived class)
class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}

    // Override base class function
    void speak() override {
        cout << name << " says Woof!" << endl;
    }
};

// Cat class (derived class)
class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}

    // Override base class function
    void speak() override {
        cout << name << " says Meow!" << endl;
    }
};

// Main function
int main() {
    // Create Animal, Dog, and Cat objects
    Animal* animal = new Animal("Generic Animal");

    // Call speak() function on each object
    animal->speak();  // Output: I am an animal.

    animal = new Cat("Whiskers");
    animal->speak();     // Output: Fido says Woof!
    animal = new Dog("Fido");
    animal->speak();     // Output: Whiskers says Meow!

    // Clean up
    delete animal;

    return 0;
}
