#include <iostream>
#include <string>
using namespace std;

int main()
{
    try {
        string str = "Hello there! my name is Aditya";
        cout << endl << "str.length(): " << str.length();
        string temp = str.substr(50, 10);
        cout << endl << "Temp: " << temp;
    }

    catch(out_of_range oor) {
        cout << endl << "In block out of range:\nError message: " << oor.what();
    }
}
