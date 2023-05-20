#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    
    vector<int>::iterator it;
    // using pre-increment operator
    for (it = a.begin(); it != a.end(); ++it) {
        cout << *it << endl;
    }

    cout << endl << "Enter index: ";
    int index;
    cin >> index;
    cout << "a[" << index << "] = " << a.at(index) << endl;

    cout << endl << "Enter value to be inserted: ";
    int value;
    cin >> value;
    cout << "Enter index: ";
    cin >> index;
    a.insert(a.begin() + index, value);

    //display
    for (it = a.begin(); it != a.end(); ++it) {
        cout << *it << endl;
    }

    cout << endl << "Enter index to be deleted: ";
    cin >> index;
    a.erase(a.begin() + index); 

    //display
    for (it = a.begin(); it != a.end(); ++it) {
        cout << *it << endl;
    }
    
    cout << endl << "Back: " << a.back() << endl;

    a.clear();
    cout << endl << "Size of vector a: " << a.size() << endl;
    
    //display
    for (it = a.begin(); it != a.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}