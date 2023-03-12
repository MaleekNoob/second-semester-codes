/*
Program to clear conepts regarding destructors in c++
1. See what happens to dynamic classes with default destructor
2. See what happens to dynamic classes with our very own destructor
3. Play around with dynamic data members within class via default and user-built destructor
*/

#include <iostream>
using namespace std;

class Class {
    private:
        int int_data;
        double double_data;
        char char_data;
        int* dynamic_int_data = new int;

    public:
    Class() {
        int_data = 0;
        double_data = 0;
        char_data = 0;
        *dynamic_int_data = 0;
    }

    Class(int integer, double decimal, char character, int* dynamic): int_data(integer), double_data(decimal), char_data(character) {
        *dynamic_int_data = *dynamic; //deep copy
    }

    // Class(Class &obj) {
    //     this->char_data = obj.char_data;
    //     this->double_data = obj.double_data;
    //     this->int_data = obj.int_data;
    //     this->dynamic_int_data = 
    // }
};

int main() {

    int* dynamic = new int;
    *dynamic = 10;

    cout << endl << "ADDRESS AND VALUE OF DYNAMIC VARIABLE BEFORE MODIFICATION";
    cout << endl << "Address: " << dynamic << endl << "Value: " << *dynamic;

    int* dynamic_arr = new int[5]{1, 2, 3, 4, 5};
    cout << endl;

    cout << endl << "ADDRESS AND VALUE OF DYNAMIC ARRAY BEFORE MODIFICATION";
    cout << endl << "Address: " << dynamic_arr << endl << "Values: ";
    for (int i = 0; i < 5; i++) {
        cout << endl << *(dynamic_arr + i);
    }

    *dynamic = *dynamic_arr;
    cout << endl << "ADDRESS AND VALUE OF DYNAMIC VARIABLE AFTER MODIFICATION";
    cout << endl << "Address: " << dynamic << endl << "Values: ";
    for (int i = 0; i < 5; i++) {
        cout << endl << *(dynamic + i);
    }

    return 0;
}