//Q v(a).
#include<iostream>
using namespace std;
int main() {
    int y;
    cin >> y;
    switch(y)
    {
        case 0:
            cout << "y = 0";
            break;
        case 1:
        case 2:
            cout << "y = 1 or 2";
            y += 2;
            break;
        case 3:
            cout << "y = 3";
            break;
        case 4:
            cout << "y = 4";
            cout << "y is four";
            break;
        default:
            cout << "Else";
            break;
    }
    return 0;
}