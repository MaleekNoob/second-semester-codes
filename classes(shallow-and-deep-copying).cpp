#include <iostream>
#include <cstring>
using namespace std;

class person {
    private:
    char* name = new char;
    int age;

    public:
    person() {
        name = "0";
        age = 0;
    }

    person (char Name[], int Age) {
        strcpy(name, Name);
        age = Age;
    }

    person (person &p) {
        strcpy(name, p.name);
        age = p.age;
    }

    char* getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(char Name[]) {
        strcpy(name, Name);
    }

    void setAge(int Age) {
        age = Age;
    }

};

int main() {

    char name[10] = "mein jan";
    person p1(name, 20);
    cout << p1.getName() << endl;

    person p2(p1);
    p2.setName("mein nahi");
    cout << p2.getName() << endl;
    cout << p1.getName() << endl;

    return 0;
}