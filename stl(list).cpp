// Cody by: Chat GPT-3.5
#include <iostream>
#include <list>



int main() {
    std::list<int> myList;

    // Inserting elements at the end of the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Inserting elements at the beginning of the list
    myList.push_front(5);
    myList.push_front(15);

    // Inserting an element after a specific position
    std::list<int>::iterator it = myList.begin();
    ++it; // Advance iterator to the second position
    myList.insert(it, 25);

    // Removing elements from the list
    //myList.pop_back(); // Remove the last element
    //myList.pop_front(); // Remove the first element
    //myList.erase(it); // Remove the element at the second position

    // Iterating over the list using a range-based for loop
    for (int num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reversing the list
    // myList.;
    myList.reverse();
    // Iterating over the reversed list using an iterator
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    // Clearing the list
    myList.clear();

    // Checking if the list is empty
    if (myList.empty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }

    return 0;
}
