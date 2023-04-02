#include <iostream>
using namespace std;

int main() {

    int i = 0;

    while (1) {
        i++;
        if (i < 10)
            continue;
        else    
            break;      
    }

    cout << "Found it!";

    return 0;
}