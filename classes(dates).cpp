#include <iostream>
using namespace std;

class Date {
    private:
    int day;
    int month;
    int year;

    public:

    Date() {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int d, int m, int y):day(d), month(m), year(y) {}

    void addDay(int d) {
        day = day + d;

        while (day > 31) {
            day -= 31;
            month++;

            while (month > 12) {
                month -= 12;
                year++;
            }
        }
    }

    void addWeek(int week) {
        day += week * 7;

        while (day > 31) {
            day -= 31;
            month++;

            while (month > 12) {
                month -= 12;
                year++;
            }
        }
    }

    void addMonth(int m) {
        month += m;

        while (month > 12) {
            month -= 12;
            year++;
        }
    }

    void Add(int d, int m) {
        addDay(d);
        addMonth(m);
    }

    bool isLeapYear() {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            return true;
        }
        else {return false;}
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    void setDay(int d) {
        day = d;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }

};

int main() {

    int day, month, year;
    Date d1;
    cout << "\nEnter day: ";
    cin >> day;
    cout << "\nEnter month: ";
    cin >> month;
    cout << "\nEnter year: ";
    cin >> year;
    d1 = Date(day, month, year);
    d1.Add(10, 2);
    d1.addDay(10);
    d1.addWeek(2);
    d1.addMonth(2);
    cout << endl << d1.isLeapYear() << endl;

    d1.display();


    return 0;
}