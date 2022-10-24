#include<iostream>
#include"BigInt.h"

using std::cin;
using std::cout;

int main() {
    BigInt a, b, c;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter another number: ";
    cin >> b;
    c = b;
    cout << "c is: " << c;
    cout << "\nSum of " << a << " and " << b << " is: " << a + b << "\n";
    
    return 0;
}