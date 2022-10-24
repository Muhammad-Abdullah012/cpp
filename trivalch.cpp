#include<iostream>
using namespace std;
int main() {
    unsigned int a, b, c;
    double s, area;
    cin >> a >> b >> c;
    s = (double)(a + b + c) / 2;
    area = (double)s * (s-a) * (s-b) * (s-c);
    if(area < 1) {
        cout << "NO";
    }
    else 
        cout << "YES";
    return 0;
}