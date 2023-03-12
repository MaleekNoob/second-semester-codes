#include <iostream>
#include <cmath>
using namespace std;

class pattern {
    
private:
    int userNumber;

    void printAscendingLine(int num) {

        if (num > 0) {
            printAscendingLine(num - 1);
            cout << "  " << num;
        }

    }

    void printDesendingLine(int num) {

        if (num > 0) {
            cout << "  " << num;
            printDesendingLine(num - 1);
        }

    }

    void printStericLine(int num) {

        if (num > 0) {
            cout << " *";
            printStericLine(num - 1);
        }

    }

    void printWhiteLine(int num) {

        if (num > 0) {
            cout << "  ";
            printWhiteLine(num - 1);
        }

    }

    void printAlphabets(int num, int &counter, int i = 0) {
        
        if (i < num) {
            cout << static_cast<char>(64 + counter);
            counter++;
            i++; 
            printAlphabets(num, counter, i);
        }

    }


public:
    pattern() {
        userNumber = 0;
    }

    pattern(int num) {
        userNumber = num;
        // pattern(num - 1);
    }

    void ascendingNumberPattern(int num) {

        if (num > 0) {
            printAscendingLine(num);
            cout << endl;
            ascendingNumberPattern(num - 1);
        }

    }

    void desendingNumberPattern(int num) {

        if (num > 0) {
            printDesendingLine(num);
            cout << endl;
            desendingNumberPattern(num - 1);
        }

    }

    void printPlainPattern(int num) {

        if (num > 0) {
            printStericLine(num);
            cout << endl;
            printPlainPattern(num - 1);
        }

    }

    void printPlainReversePattern(int num) {

        if (num > 0) {
            printPlainReversePattern(num - 1);
            cout << endl;
            printStericLine(num);
        }

    }

    void printDiamond(int num, int counter = 1) {

        if (counter <= num) {

            if (counter <= (num/2)) {
                printWhiteLine((num/2) - counter);
                printStericLine(counter * 2);
                cout << endl;
            }
            else {
                printWhiteLine(counter - (num/2));
                printStericLine((num - counter) * 2);
                cout << endl;
            }

            printDiamond(num, (counter + 1));
        }

    }

    void printDiamondOdd(int num, int counter = 1) {

        if (counter <= num) {
        
            if (counter <= ceil(num / 2.0)) {
                printWhiteLine(ceil(num / 2.0) - counter);
                printStericLine(counter);
                printStericLine(counter - 1);
            }
            else {
                printWhiteLine(counter - ceil(num / 2.0));
                printStericLine((num - counter) + 1);
                printStericLine(num - counter);
            }

            cout << endl;
            printDiamondOdd(num, counter + 1);

        }
    }

    void printAlphabetPattern(int num, int counter, int num1) {
        
        if (num1 <= num) {
            printAlphabets(num1, counter);
            cout << endl;
            printAlphabetPattern(num, counter, num1 + 1);
        }

    }


};

int main() {

    pattern p1;
    int number;
    char yesOrNo;
    cout << "\nDo you want to some patterns da? ";
    cin >> yesOrNo;

    if (yesOrNo == 'y') {
        cout << "\nEnter number: ";
        cin >> number;
        p1 = pattern(number);
        p1.printAlphabetPattern(number, 1, 1);
    }

    return 0;
}