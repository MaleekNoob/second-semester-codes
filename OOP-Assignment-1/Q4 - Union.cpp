/*
Name: Maleek Hussain Ali
Roll Number: 22i-1526
Section: B
*/
#include<iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int* sort(int* array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = (i + 1); j < size; j++) {
			if (array[i] > array[j]) {
				swap(array[i], array[j]);
			}
		}
	}
	return array;
}
int* increaseDynammicArray(int* array, int& size) {  //Increases Dynammic Array by size 1
	int new_size = size + 1;
	int* newArray = new int[new_size];

	for (int i = 0; i < new_size; i++) {
		newArray[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}
	size = new_size;
	delete[] array;
	array = newArray;
	newArray = NULL;

	return array;
}
struct arrayUnion {
	int arr1[10]; //keep this size
	int arr2[5]; // keep this size
	int* ResultUnionArr = new int;
	int size = 0;  //size of dynammic array
	bool isRepeat = true;  //true if particular number is repeated
	int iter = 0;  //controls iteration of dynammic array;
	void input()
	{
		cout << "\nInput first array: ";
		for (int i = 0; i < 10; i++) {
			cout << endl << "Enter number: ";
			cin >> arr1[i];
		}
		cout << "\nInput second array: ";
		for (int i = 0; i < 5; i++) {
			cout << endl << "Enter number: ";
			cin >> arr2[i];
		}
	}
	void find_union()
	{
		//find union of arr1 and arr2
		for (int i = 0; i < 10; i++) {
			isRepeat = false;
			for (int j = (i + 1); j < 10; j++) {
				if (arr1[i] == arr1[j]) {
					isRepeat = true;
					break;
				}
			}

			if (isRepeat) {
				continue;
			}
			else {
				ResultUnionArr = increaseDynammicArray(ResultUnionArr, size);  //makes space for upcomming variable
				ResultUnionArr[iter] = arr1[i];
				iter++;
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < size; j++) {
				if (arr2[i] == ResultUnionArr[j]) {
					break;
				}

				if (j == (size - 1)) {
					ResultUnionArr = increaseDynammicArray(ResultUnionArr, size);  //makes space for upcomming variable
					ResultUnionArr[size - 1] = arr2[i];
				}
			}
		}
	}
	void printresult()
	{
		//print array with union
		cout << endl << "\nArray 1: " << endl;  //prints out first array
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				cout << "{" << arr1[i] << ", ";
			}
			else if (i == 9) {
				cout << arr1[i] << '}';
			}
			else {
				cout << arr1[i] << ", ";
			}
		}

		cout << endl << "\nArray 2: " << endl;  //prints out second array
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				cout << "{" << arr2[i] << ", ";
			}
			else if (i == 4) {
				cout << arr2[i] << '}';
			}
			else {
				cout << arr2[i] << ", ";
			}
		}
		ResultUnionArr = sort(ResultUnionArr, size);   //Sorts dynammic array
		cout << endl << "\nUnion Matrix is " << endl;
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				cout << "{" << ResultUnionArr[i] << ", ";
			}
			else if (i == (size - 1)) {
				cout << ResultUnionArr[i] << '}';
			}
			else {
				cout << ResultUnionArr[i] << ", ";
			}
		}
		for (int i = 0; i < 3; i++) {
			cout << endl;
		}
	}
};


int main()
{
	arrayUnion u;
	u.input();
	u.find_union();
	u.printresult();
	

	return 0;
}
