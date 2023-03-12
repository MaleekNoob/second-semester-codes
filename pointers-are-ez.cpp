#include <iostream>
#include <stdlib.h>

struct person {
    char name[30];
    int age;
};

int main(int argc, char* argv[]) {
    
    struct person people[50]; 

    struct person *peoplePtr = people;

    for (int i = 0; i < 50; i++) {
        peoplePtr->age = i;
    }
}