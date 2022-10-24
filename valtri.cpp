#include<iostream>
using namespace std;
int main() {
    unsigned int n;
    cin >> n;
    if( !(n%5) || !(n%6)) {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}