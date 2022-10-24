#include<iostream>
#include<iomanip>
using namespace std;
void print(const unsigned short int& n) {
    for(unsigned short int i{0}; i < n; ++i) {
        cout << setw(n - i);
        for(unsigned short int j{0}; j <= i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
}
int main() {
    unsigned short int n;
    cin >> n;
    print(n);
    return 0;
}