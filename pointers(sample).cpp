#include <iostream>
using namespace std;

int main() {

    int arr[] = {4, 5, 6, 7};
    int* ptr = (arr + 2);
    int *p = ptr;
    (*p)++;
    --(*(ptr++));
    cout << *p << " : " << *ptr << endl;

    return 0;
}