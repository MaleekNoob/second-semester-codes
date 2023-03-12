#include <iostream>
using namespace std;

bool compareArrayNumber(int array[], int index, int size) {
    
    static int j;
    if (j < size) {

        if (index == array[j]) {
            j = 0;
            return true;
        }

        j++;
        return (false || compareArrayNumber(array, index, size));
    }
    else {
        j = 0;
        return false;
    }

}

int missingNumber(int array[], int size) {
    
    static int i;

    if (i == 0)
        i = 1;

    if (i <= size) {
        
        if (!compareArrayNumber(array, i, size)) {
            return i;
        }

        i++;
        return missingNumber(array, size);
    }
    else {
        return -1;
    }
}

int main() {

    int N = 15;
    int array[] = {6, 9, 1, 3, 2, 8, 4, 7, 5, 10, 15, 13, 12, 14};

    cout << missingNumber(array, N);

    return 0;
}