// Qiii. A)
//A program to print table
#include<iostream>
using namespace std;
int main() {
    int n, r;
    cout << "Enter a number of table : ";
    cin >> n;
    cout << "Enter range of table: ";
    cin >> r;
    cout << "Table of " << n << " is:\n";
    for(int i = 1; i <= r; ++i) {
        cout << n << " x " << i << " = " << n * i << "\n";
    }
    return 0;
}