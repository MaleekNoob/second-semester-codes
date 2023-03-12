#include <iostream> 
using namespace std;

int main() {
	int mainSize, secondarySize;
	cout << "\nEnter main size: ";
	cin >> mainSize;
	cout << "\nEnter secondary size: ";
	cin >> secondarySize;

	int** twoDArray = new int*[mainSize * secondarySize];

	for (int i = 0; i < mainSize; i++) {
		twoDArray[i] = new int[secondarySize];
	}

	for (int i = 0; i < mainSize; i++) {
		for (int j = 0; j < secondarySize; j++) {
			cout << "\nEnter value: ";
			cin >> **(twoDArray + j + (i * secondarySize));
		}
	}

	for (int i = 0; i < mainSize; i++) {
		for (int j = 0; j < secondarySize; j++) {
			cout << endl << twoDArray[i][j];
		}
	}

	return 0;
}