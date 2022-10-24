#include<iostream>
using std::cin;
using  std::cout;
int main() {
    constexpr double SumOfAnglesInTriangle = 180;
    double a, b, c, diff;
    cin >> a >> b >> c;
    diff =  SumOfAnglesInTriangle - a - b - c;
    if(diff) {
        cout << "NO";
    }
    else
        cout << "YES";
    return 0;
}