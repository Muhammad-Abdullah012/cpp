#include<iostream>
using namespace std;
int main() {
    bool found{false};
    unsigned int n, k, v;
    cin >> n >> k;
    for(unsigned int i{0}; i < n; i++) {
        cin >> v;
        if(v == k) {
            found = true;
        }
    }
    if(found == true)
        cout << 1;
    else    
        cout << -1;
    return 0;
}