/*
    Problem Statement:
    Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
    Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). 
    If an element is 0, then cannot move through that element.

    Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
    Output: 3 (1-> 3 -> 8 ->9)
    Explanation: Jump from 1st element 
    to 2nd element as there is only 1 step, 
    now there are three options 5, 8 or 9. 
    If 8 or 9 is chosen then the end node 9 
    can be reached. So 3 jumps are made.

    Input: arr[] = {1, 4, 3, 2, 6, 7}
    Output: 2 (1-> 4 -> 7)
    Explanation: Jump from 1st element to 2nd 
    element as there is only 1 step, 
    now there are three options 4, 3 or 2.
*/

#include <iostream>
using namespace std;

void makeJumps(int arr[], int &index, int jump) {

    if (jump > 0) {
        index++;
        makeJumps(arr, index, (jump - 1));
    }
}

int calculateJump(int arr[], int N) {

    // Base Case
    static int jumpCount, index;
    if (index >= N) {
        return jumpCount;
    }
    else {

        makeJumps(arr, index, arr[index]);
        jumpCount++; 
        index++;
        return calculateJump(arr, N);
    }
}

int main() {

    int N = 18;
    int arr[N] = {1, 4, 3, 2, 6, 7, 3, 2, 6, 7, 6, 2, 1, 5, 3, 6, 8, 5};
    cout << calculateJump(arr, N);

    return 0;
}