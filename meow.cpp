#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {

    list<int> myVector;
    myVector.push_front(10);
    myVector.push_front(11);
    myVector.push_front(12);

    list<int>::iterator it;
    for(it = myVector.begin(); it != --myVector.end(); ++it) {
        cout << *it << endl;
    }
    cout << "Meow1: " << *it << endl;
    it--;
    cout << "Meow2: " << *it << endl;
    it--;
    cout << "Meow2: " << *it << endl;

    for (int num: myVector) {
        cout << num << endl;
    }   
    // cout<<f.first+f.second;

    // std::vector<int*> twoDVector;
    // twoDVector.push_back(new int[5]);
    // std::vector<int> myVector;

    // for (int i = 0; i < 5; i++) {
    //     twoDVector[0][i] = i ;
    // }

    // vector<int*>::iterator it;
    // for (it = twoDVector.begin(); it != twoDVector.end(); it++) {
    //     for (int i = 0; i < 5; i++)
    //         cout << endl << *it[i];
    // }

    // // Inserting elements at the end of the vector
    // myVector.push_back(10);
    // myVector.push_back(20);
    // myVector.push_back(30);

    // // Accessing elements using the subscript operator
    // std::cout << "Element at index 1: " << myVector[1] << std::endl;

    // // Accessing elements using the at() function
    // std::cout << "Element at index 2: " << myVector.at(2) << std::endl;

    // // Checking the size and capacity of the vector
    // std::cout << "Size of vector: " << myVector.size() << std::endl;
    // std::cout << "Capacity of vector: " << myVector.capacity() << std::endl;

    // // Reserving capacity in advance
    // myVector.reserve(10);
    // std::cout << "Updated capacity of vector: " << myVector.capacity() << std::endl;

    // // Iterating over the vector using a range-based for loop
    // for (int num : myVector) {
    //     std::cout << num << " ";  // num is automatically assigned the value of the current element
    // }
    // std::cout << std::endl;

    // // Modifying elements using the subscript operator
    // myVector[0] = 5;
    // myVector[2] = 15;

    // // Inserting an element at a specific position
    // std::vector<int>::iterator it = myVector.begin() + 1;
    // myVector.insert(it, 25);

    // for (; it != myVector.end(); it++)

    // // Erasing an element at a specific position
    // myVector.erase(myVector.begin() + 2);

    // // Checking if the vector is empty
    // if (myVector.empty()) {
    //     std::cout << "The vector is empty." << std::endl;
    // } else {
    //     std::cout << "The vector is not empty." << std::endl;
    // }

    // // Clearing the vector
    // myVector.clear();

    // // Checking the size after clearing the vector
    // std::cout << "Size of vector after clearing: " << myVector.size() << std::endl;

    return 0;
}
