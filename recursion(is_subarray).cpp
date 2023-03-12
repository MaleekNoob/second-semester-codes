#include <iostream>
using namespace std;

bool isSubstring(char* str) {
    if (str == NULL) {
        return false;
    }
    if (str[0] == '\0') {
        return true;
    }
    if (str[0] == 'a' && str[1] == 'b' && str[2] == 'c') {
        return true;
    }
    return isSubstring(str + 1);


}

int stringLength(char* str) {
    if (str == NULL) {
        return 0;
    }
    if (str[0] == '\0') {
        return 0;
    }
    return 1 + stringLength(str + 1);
}

int main() {

    char str[] = "abc";
    cout << isSubstring(str) << endl;
    cout << stringLength(str) << endl;

    return 0;
}