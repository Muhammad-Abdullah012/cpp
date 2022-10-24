//Qi.
//Program to find sum of even numbers from 11 to 30.
#include<iostream>
using namespace std;
int main() {
    int sum{0};
    for(int i = 11; i <= 30; i++) {
        if(i % 2 == 0) {
            sum += i;
        }
    }
    cout << "Sum of all even numbers from 11 to 30 is : " << sum;
    return 0;
}