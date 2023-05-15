/*
*Name: Maleek Hussain Ali
*Roll No: 22i-1526
*Section: SE-B
*/
#include <iostream>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '^' || c == 'v' || c == '~');
}

string deMorgan(string s) {
    string result = "";
    int count = -1;
    char st[s.length()];
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st[++count] = s[i];
        } else if (s[i] == ')') {
            string temp = "";
            while (count != -1 && st[count] != '(') {
                temp = st[count--] + temp;
            }
            count--;
            if (count != -1 && st[count] == '~') {
                st[count] = ' ';
                for (int j = 0; j < temp.length(); j++) {
                    if (temp[j] == '^') {
                        temp[j] = 'v';
                    } else if (temp[j] == 'v') {
                        temp[j] = '^';
                    } else if (temp[j] != '^' && temp[j] != 'v' && temp[j] != ' ') {
                        temp.insert(j + 1, 1, '~');
                        j++;
                    }
                }
            }
            for (int j = 0; j < temp.length(); j++) {
                st[++count] = temp[j];
            }
        } else {
            st[++count] = s[i];
        }
    }
    while (count != -1) {
        result = st[count--] + result;
    }
    return result;
}

int main() {
    string formula;
    cout << "Enter a propositional formula: ";
    getline(cin, formula);
    string simplifiedFormula = deMorgan(formula);
    cout << "Simplified formula: " << simplifiedFormula << endl;
    return 0;
}