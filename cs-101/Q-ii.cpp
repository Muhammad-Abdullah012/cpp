//Qii.
//Program to check if a 5 digit number is plaindrome or not.
#include<iostream>
using namespace std;
int main() {
    int number, arr[5];
    bool plaindrome{false};
    cout << "Enter five digit number: ";
    cin >> number;
    for(int i = 0, n = number; i < 5; ++i) {
        arr[i] = n % 10;
        n /= 10;
    }
    for(int i = 0, j = 4; i < 2 ; ++i, --j) {
        if(arr[i] == arr[j]) {
            plaindrome = true;
        }
        else {
            plaindrome = false;
            break;
        }
    }
    if(plaindrome) {
        cout << number << " is a plaindrome number.";
    }
    else {
        cout << number << " is not plaindrome.";
    }
    return 0;
}