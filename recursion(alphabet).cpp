#include <iostream>
using namespace std;

void printAlphabets(int num, int &counter, int i = 0) {
    
    if (i < num) {
        cout << static_cast<char>(64 + counter);
        counter++;
        i++; 
        printAlphabets(num, counter, i);
    }

}

void printAlphabetPattern(int num, int counter, int num1) {
    
    if (num1 <= num) {
        printAlphabets(num1, counter);
        cout << endl;
        printAlphabetPattern(num, counter, num1 + 1);
    }

}

int main() {

    printAlphabetPattern(5, 1, 1);
    return 0;
}