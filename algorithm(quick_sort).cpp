#include <iostream>
using namespace std;

void quick_sort(int arr[], int start, int end) {

    if ((end - start) < 2) {
        //do notiong
    } else {
        //sort pivot
        int head = start;
        int foot = end - 1;
        int pivot = head;

        // finding pivot 
        while (head != foot) {

            if (pivot == head) {
                if (arr[pivot] > arr[foot]) {
                    swap(arr[pivot], arr[foot]);
                    pivot = foot;
                    head++;
                    
                } else {
                    foot--;
                }
            }
            else if (pivot == foot) {
                if (arr[pivot] < arr[head]) {
                    swap(arr[pivot], arr[head]);
                    pivot = head;
                    foot--;
                    
                } else {
                    head++;
                }
            }
        }

        quick_sort(arr, start, pivot);
        quick_sort(arr, pivot+1, end);

    }
}

int main() {

    int arr[] = {1, 5, 3, -6, 6, 4, 7, 3 ,9, 2, -10, 0 ,5 , 7};

    quick_sort(arr, 0, 14);

    for (int i = 0; i < 14; i++) {
        cout << endl << arr[i];
    }

    return 0;
}