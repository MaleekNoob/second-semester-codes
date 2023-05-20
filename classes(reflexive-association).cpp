#include <iostream>
using namespace std;

class roboust {
    private:
    roboust* a;
    int* numbers, total_numbers;

    public:
    roboust() {
        a = nullptr;
        total_numbers = 0;
        numbers = new int[total_numbers];
    }

    void add(int n) {
        int* temp_arr = new int[total_numbers + 1];
        for (int i = 0; i < total_numbers; i++) {
            temp_arr[i] = numbers[i];
        }
        temp_arr[total_numbers] = n;
        delete[] numbers;
        numbers = temp_arr;
        total_numbers++;
    }

    //getters and setters
    roboust get() {
        return *a;
    }

    void set(roboust a) {
        *this->a = roboust(a);
    }

    roboust(roboust &r) {
        total_numbers = r.total_numbers;
        int* temp_arr = new int[total_numbers];
        for (int i = 0; i < total_numbers; i++) {
            temp_arr[i] = r.numbers[i];
        }
        delete[] numbers;
        numbers = temp_arr;
    }

    friend ostream& operator<<(ostream& out, roboust& r) 
    {
        for (int i = 0; i < r.total_numbers; i++) {
            out << r.numbers[i] << " ";
        }

        return out;
    }

    void display() {
        for (int i = 0; i < total_numbers; i++) {
            cout << numbers[i] << " ";
        }
    }
};

int main() {

    //implementation 
    roboust a;
    a.add(1);
    a.add(43);
    a.add(-6);
    a.add(16);
    a.add(23);
    a.add(-61);
    roboust b(a);
    cout << b;

    return 0;
}