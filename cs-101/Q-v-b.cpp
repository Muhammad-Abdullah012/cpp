//Q v(b).
#include<iostream>
using namespace std;
int main() {
    int a, b;
    char c;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Enter '+' for addition, '-' for subtraction, '*' or 'x' for multiplication, '%' for remainder , '/' or 'd' or 'D' for division: ";
    cin >> c;
    if(c == '+') {
        cout << a + b;
    }
    else if(c == '-') {
        cout << a - b;
    }
    else if(c == '*' || c == 'x') {
        cout << a * b;
    }
    else if(c == '%') {
        cout << a % b;
    }
    else if(c == '/' || c == 'd' || c == 'D') {
        cout << a / b;
    }
    else {
        cout << "invalid operator";
    }
    return 0;
}