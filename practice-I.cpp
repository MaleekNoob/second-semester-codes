#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

char* storeValue(char* arr, int size) ;

void displayValue(char* arr, int size);

void replace(char*, char*, char**, char**);

int main(int argc, char *argv[]) {
    // char* arr1,* arr2;
    // arr1 = new char[10];
    // arr2 = new char[10];
    // cout << "\nEnter your character array: ";
    // cin.getline(arr1, 10);
    // cout << "\nEnter you second character array: ";
    // cin.getline(arr2, 10);

    // cout << "\nOutside the function: ";
    // cout << "\nAddress of array 1 is " << &arr1 << " and the address of array 2 is " << &arr2;

    // replace(arr1, arr2, &arr1, &arr2);
    // cout << "\nHere you go:\narray 1: " << arr1 << "\narray 2: " << arr2;

    char* str1 = "Self-doubt is key to success";
    char* src;
    char* str2[20]; //empty string
    char* desk;
    src = str1;
    desk = *str2;

    return 0;
}

char* storeValue(char* arr, int size) {
    char permission;
    int iter = 0;
    do
    {
        cout << "\nStoring at index " << iter << ": ";
        cin >> *(arr + iter);
        cout << "\nagain?";
        cin >> permission;
        iter++;
    } while (permission == 'y');
    
}

void displayValue(char* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << endl << "Value stored at index " << i << " is " << arr[i];
    }
}

void replace(char* arr1, char* arr2, char** address1, char** address2) {
    cout << endl << "Inside the function: ";
    cout << "\nWe kind of made address of array 1 is " << address1 << " and the address of array 2 is " << address2;
    *address1 = arr2;
    *address2 = arr1;

}

//void pointer (also legit try to typecast as well da)
//do things with constant pointers