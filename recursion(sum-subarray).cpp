#include <iostream>
using namespace std;

void sum_substring(int array[], int num, int size) {
    
    static int i, sum;
    int j = 0, k = 0;
    if (i < size) {

        for (j = i; j < size; j++) {

            for (k = i; k <= j; k++) {
                sum += array[k];
            }

            if (sum == num) {
                cout << "\nStarting index: " << i << " \nEnd index: " << j;
                exit (0);
            }
            else {
                sum = 0;
            }
        }

        i++;
        sum = 0;
        sum_substring(array, num, size);

    }
    else {
        cout << "\nNot found";
    }

}

int main() {

    int S = 5, N = 9;
    int array[] = {1, 2, 3, 4, 5};
    sum_substring(array, N, S);

    return 0;
}