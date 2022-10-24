#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    unordered_map<string, int> um;
    unsigned int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        um[s]++;
    }
    unsigned int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        cout << um[s] << "\n";
    }
    return 0;
}