#include<bits/stdc++.h>
using namespace std;

int squares(const int& a, int& b) {
    int count{};
    int sqrt{1};
    for(int i = a; i <= b; ++i) {
        sqrt = std::floor(std::sqrt(i));
        if(sqrt * sqrt == i) {
            ++count;
            i += sqrt * 2;
        }
    }
    return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b;
    cin >> a >> b;
    cout << squares(a, b);
    return 0;
}