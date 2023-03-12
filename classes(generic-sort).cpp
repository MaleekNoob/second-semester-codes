#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

class sort {
    private:
    int *intArr = new int;
    float *floatArr = new float;
    string *stringArr = new string;

    public: 
    sort() {}
    void sortArray(int size, int type);
    void printArray(int size, int type);

};

void sort::sortArray(int size, int type) {

    switch (type)
    {
    case 1:
        intArr = new int[size];
        for (int i = 0; i < size; i++) {
            cin >> intArr[i];
        }

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (intArr[i] > intArr[j])
                    swap(intArr[i], intArr[j]);
            }
        }

        printArray(size, type);
        break;

    case 2:
        floatArr = new float[size];
        for (int i = 0; i < size; i++) {
            cin >> floatArr[i];
        }

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (floatArr[i] > floatArr[j])
                    swap(floatArr[i], floatArr[j]);
            }
        }

        printArray(size, type);
        break;

    case 3:
        stringArr = new string[size];
        for (int i = 0; i < size; i++) {
            cin >> stringArr[i];
        }

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (stringArr[i] > stringArr[j])
                    swap(stringArr[i], stringArr[j]);
            }
        }

        printArray(size, type);
        break;
    
    default:
        break;
    }


    delete[] intArr;
    delete[] floatArr;
    delete[] stringArr;
}

void sort::printArray(int size, int type) {
    switch (type)
    {
    case 1:
        for (int i = 0; i < size; i++) {
            cout << endl << intArr[i];
        }
        break;
    
    case 2:
        for (int i = 0; i < size; i++) {
            cout << endl << floatArr[i];
        }
        break;

    case 3:
        for (int i = 0; i < size; i++) {
            cout << endl << stringArr[i];
        }
        break;

    default:
        break;
    }
}

int main() {

    int n, q;

    cout << "\nEnter size: ";
    cin >> n;
    cout << "\nEnter type: ";
    cin >> q;

    sort element;
    element.sortArray(n , q);

    return 0;
}