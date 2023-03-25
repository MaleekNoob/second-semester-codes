#include <iostream>
using namespace std;

class Sample {
    int a, b;

    public:
    Sample(int i = 0, int j = 0) {
        a = i;
        b = j;
    }

    friend int sum(Sample);

    Sample operator+ (Sample);
};

Sample Sample::operator+ (Sample s) {
    Sample temp;
    temp.a = a + s.a;
    temp.b = b + s.b;
    return temp;
}

int sum (Sample s) {
    return s.a + s.b;
}

int main() {



    return 0;
}