//Q vi.
#include<iostream>
using namespace std;
int main() {
    char ch;
    int n;
    cout << "Enter any alphabet: ";
    cin >> ch;
    n = static_cast<int>(ch);
    if(n >= 97 && n <= 122) {
        n -= 32;
        ch = static_cast<char>(n);
        cout << "Uppercase letter is: " << ch;
    }
    return 0;
}