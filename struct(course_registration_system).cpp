#include <iostream>
using namespace std;int numberOfDigits(int n){if(n==0){return 0;}else{return 1+numberOfDigits(n/10);}}int main(){int num;cout<<"Enter a number: ";cin>>num;cout<<"\nThe number of digits in "<<num<<" are "<<numberOfDigits(num);return 0;}