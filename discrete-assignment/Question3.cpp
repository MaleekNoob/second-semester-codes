/*Name: Maleek Hussain Ali
*Roll No: 22i-1526
*Section: SE-B
*/
#include <iostream>
using namespace std;

class Card;

class Card {
public:
    int color;
    int shape;
    int number;
};

bool is(Card c1, Card c2, Card c3) {
    if ((c1.color == c2.color && c1.color == c3.color && c2.color == c3.color) ||
        (c1.color != c2.color && c1.color != c3.color && c2.color != c3.color)) {
        if ((c1.shape == c2.shape && c1.shape == c3.shape && c2.shape == c3.shape) ||
            (c1.shape != c2.shape && c1.shape != c3.shape && c2.shape != c3.shape)) {
            if ((c1.number == c2.number && c1.number == c3.number && c2.number == c3.number) ||
                (c1.number != c2.number && c1.number != c3.number && c2.number != c3.number)) {
                return true;
            }
        }
    }
    return false;
}

void validation(int& value) {
    while (value < 0 || value > 2) {
        cout << "Invalid input. Please enter a valid number in the range of 0 to 2: ";
        cin >> value;
    }
}

int main()
{
    int cards = 3; 
    Card card[cards];   
    for (int i = 0; i < cards; i++) {
        cout << endl << "Enter attributes for Card " << (i + 1) << ":" << endl;
        cout << "Enter color [0, 1, 2]: ";
        cin >> card[i].color;
        validation(card[i].color);
        cout << "Enter shape [0, 1, 2]: ";
        cin >> card[i].shape;
        validation(card[i].shape);
        cout << "Enter number [0, 1, 2]: ";
        cin >> card[i].number;
        validation(card[i].number);
    }

    int sets = 0;
    for (int i = 0; i < cards - 2; i++) {
        for (int j = i + 1; j < cards - 1; j++) {
            for (int k = j + 1; k < cards; k++) {
                if (is(card[i], card[j], card[k])) {
                    cout << "Set found: Cards " << (i + 1) << ", " << (j + 1) << ", " << (k + 1) << endl;
                    sets++;
                }
            }
        }
    }
    
    if (sets == 0) {
        cout << "Sets not found" << endl;
    } 
    else {
        cout << "Number of total sets found: " << sets << endl;
    }

    return 0;
}