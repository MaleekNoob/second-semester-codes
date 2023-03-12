/*
 3.	Ask the user to enter the coordinate of point in x-y coordinate system. Depending upon the value of x and y value, the program will identify in which quadrant the point lies. Implement this program using switch statement as well as by ternary operator.
*/

#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Enter the coordinate of point in x-y coordinate system: ";
    cin >> x >> y;

    //using switch statement
    switch (x > 0) {
        case true:
            switch (y > 0) {
                case true:
                    cout << "The point lies in first quadrant.";
                    break;
                case false:
                    cout << "The point lies in fourth quadrant.";
                    break;
            }
            break;
        case false:
            switch (y > 0) {
                case true:
                    cout << "The point lies in second quadrant.";
                    break;
                case false:
                    cout << "The point lies in third quadrant.";
                    break;
            }
            break;
    }

    //using ternary operator
    (x > 0) ? ((y > 0) ? cout << "The point lies in first quadrant." : cout << "The point lies in fourth quadrant.") : ((y > 0) ? cout << "The point lies in second quadrant." : cout << "The point lies in third quadrant.");

    return 0;
}