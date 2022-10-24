#include<iostream>
using namespace std;
auto add(const unsigned int& n) {
    unsigned long int sum = (unsigned long int) n * (n + 1) / 2;
    return sum;
}
int main() {
    unsigned int n;
    cin >> n;
    cout << add(n);
    return 0;
}