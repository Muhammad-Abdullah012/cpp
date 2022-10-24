#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    map<string, int> m;
    unsigned int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto &pr:m) {
        cout << pr.first << " " << pr.second << "\n";
    }
    return 0;
}